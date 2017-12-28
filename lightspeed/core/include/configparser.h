// configparser.h

#ifndef CONFIGPARSER
#define CONFIGPARSER
#include <iostream>
#include "file.h"
#include <string>
#include <cassert>
#include "../external/json.hpp"
#include "../globals.h"
using json = nlohmann::json;

class ConfigParser : public ModuleObject {
    std::string error = "No error has occured";
    json object;
    std::vector<std::string> repos;
    
public:
    ConfigParser(File*);
    
    bool success();
    
    std::string error_msg();
    
    std::vector<std::string> get_repos();
    
};

class ProjectFileParser : public ModuleObject {
    std::string error_msg;
    std::string name,version,owner;
    json object;
    bool has_success = false;
    std::vector<json> dependencies;
    std::string custom_install_directory;
public:
    ProjectFileParser(File*);
    
    std::string get_error();
    
};
#endif
