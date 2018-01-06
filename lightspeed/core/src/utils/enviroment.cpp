#include "../../include/enviroment.h"

EState::EState(InputHandleOutput i) {
    const string DEFAULT_ACCESS = ".lsconf.json";
    // Check if special conf was specified
    if (i.get_args()["--conf"] != "") {
        conf_access = i.get_args()["--conf"];
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

EState::EState() {
    // Empty constructor for testing purposes only. DO NOT USE THIS CODE IN PRODUCTION.
}

bool EState::setup() {
    // Make sure configuration file (containing repos) exists
    
    File* file = FileLoader::load(conf_access,true);
    if (!file->open()) {
        ErrorManager::error("Could not access local configuration file: '" + conf_access + "'. Please check that the file exists or you are in the proper directory","enviroment",true);
        return false;
    }
    ConfigParser c = ConfigParser(file);
    if(!c.success()) {
        ErrorManager::error(c.error_msg(),"enviroment",false);
        s_integrity = false;
    } else {
        s_repos = c.get_repos();
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
     std::exception except;
        if(s_error != "") error_status = s_error;
        if(!s_integrity) {
            throw except;
        }
        if(c_error != "") error_status = c_error;
        if(!c_integrity) {
            throw except;
        }
}

std::tuple<std::vector< std::string > > EState::get_state()
{
    return std::make_tuple(s_repos);
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


