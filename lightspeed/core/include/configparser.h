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
    std::vector<json> dependencies;
    std::string custom_install_directory;
    bool link_cmake_deps;
    std::string b_type;
    std::vector<std::string> b_include;
public:
    ProjectFileParser(File*);
    
    std::string get_error();
    
    std::vector<json> get_dependencies();
    
    std::vector<std::string> get_include();
    
    bool make_cmake_link();
    
    std::string type();
};
#endif
