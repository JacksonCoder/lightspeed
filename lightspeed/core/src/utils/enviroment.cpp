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
    // Make sure configuration file (containing repos) exists
    
    File* file = FileLoader::load(conf_access,true);
    if (!file->stable()) {
        ErrorManager::error("Could not access local configuration file: '" + conf_access + "'. Please check that the file exists or you are in the proper directory","enviroment",true);
    }
    LightSpeedConfigurationParser c = LightSpeedConfigurationParser(file);
    ErrorManager::release();
    s_repos = c.fetch();
    
    // Test arguments
    bool option_valid = false;
    for( auto c : CMD_OPTIONS) {
        if ( option == c) option_valid = true;
    }
    if (!option_valid) {
        s_integrity = false; //TODO: Make arg_integrity
        ErrorManager::error("The command " + option + " is not recognized as a valid command. Type 'lightspeed help' for help with commands", "enviroment",true);
    }
}

EState::EState() {
    // Empty constructor for testing purposes only. DO NOT USE THIS CODE IN PRODUCTION.
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


