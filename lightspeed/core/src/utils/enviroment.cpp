#include "../../include/enviroment.h"

EState::EState(InputHandleOutput i) {
    const string DEFAULT_ACCESS = ".lsconf.json";
    // Check if special conf was specified
    if (i.get_args()["conf"] != "") {
        conf_access = i.get_args()["conf"];
    }
    else {
        conf_access = DEFAULT_ACCESS;
    }
    const string DEFAULT_ACTION = "help";
    // Check if option was specified
    if (i.get_option() != "") {
        option = i.get_option();
    }
    else {
        option = DEFAULT_ACTION;
    }
}

bool EState::setup() {
    //Test config file exists
    File* file = FileLoader::load(conf_access,true);
    if (!file->open()) {
        error_status = "Could not access local configuration file: '" + conf_access + "'. Please check that the file exists or you are in the proper directory";
        return false;
    }
    ConfigParser c = ConfigParser(file);
    if(!c.success()) {
        s_error = c.error_msg();
        s_integrity = false;
    } else {
        s_LSPATH = c.getlspath();
        s_LATEST = c.getlatest();
        s_PROJECTNAME = c.getprojectname();
    }
    
    // Test arguments
    bool option_valid = false;
    for( auto c : CMD_OPTIONS) {
        if ( option == c) option_valid = true;
    }
    if (!option_valid) {
        s_integrity = false; //TODO: Make arg_integrity
        error_status = "The command " + option + " is not recognized as a valid command. Type 'lightspeed help' for help with commands"; //TODO: Create arg_error variable group
    }
    return true;
}

void EState::fail() {
    std::cerr<<"An error occured while running LightSpeed:"<<std::endl;
    std::cerr<<error_status<<std::endl;
    exit(1);
}
        
void EState::fail_with_external(std::string error) {
    error_status = error;
    fail();
}

void EState::stability_check()
 {
        if(s_error != "") error_status = s_error;
        if(!s_integrity) {
            fail();
        }
}

std::tuple<std::string, std::string, bool> EState::get_state() {
    return std::make_tuple(s_PROJECTNAME, s_LSPATH,s_LATEST);
}

std::string EState::get_option()
{
    return option;
}

std::vector<std::string> EState::get_exports()
{
    return c_exports;
}
        
std::string EState::get_req_cmake_version()
{
    return c_cmake_v;
}
        
std::vector<std::string> EState::get_linked_library_paths()
{
    return c_linked_libraries;
}

void EState::set_config_state(std::string version, std::vector<std::string> libraries, std::vector<std::string> exports)
{
    c_cmake_v = version;
    c_linked_libraries = libraries;
    c_exports = exports;
}


