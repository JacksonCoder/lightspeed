// configparser.h

#ifndef CONFIGPARSER
#define CONFIGPARSER
#include <iostream>
#include "file.h"
#include <string>
#include <cassert>
#include "../external/json.hpp"
using json = nlohmann::json;

class ConfigParser {
    bool has_success = false;
    std::string error = "No error has occured";
    json object;
    bool latest;
    std::string projname;
    std::string lsfile;
    
public:
    ConfigParser(File*);
    
    bool success();
    
    std::string error_msg();
    
    bool getlatest();
    
    std::string getprojectname();
    
    std::string getlspath();
    
};

class ProjectFileParser {
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
