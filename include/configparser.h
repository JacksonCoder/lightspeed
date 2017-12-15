// configparser.h

#ifndef CONFIGPARSER
#define CONFIGPARSER
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
    ConfigParser(File* f) {
        // Get contents of file
        std::string filecontents = f->getContents();
        try {
            object = json::parse(filecontents);
        }
        catch(...) {
            error = "An exception was thrown during parsing of JSON data";
            return;
        }
        try {
            std::exception e;
            if(!object["ProjName"].is_string()) throw e;
            if(!object["LSFile"].is_string()) throw e;
            if(!object["latest"].is_boolean()) throw e;
        }
        catch(std::exception& e){
            error = "The current Project is broken. Please recreate the Project.";
            return;
        }
        latest = object["latest"];
        projname = object["ProjName"];
        lsfile = object["LSFile"];
        std::cout << "Loaded"<< std::endl;
        has_success = true;
    }
    
    bool success() {
        return has_success;
    }
    
    std::string error_msg() {
        return error;
    }
    
    bool getlatest() {
        return latest;
    }
    
    std::string getprojectname() {
        return projname;
    }
    
    std::string getlspath() {
        return lsfile;
    }
    
};

class ProjectFileParser {
    std::string error_msg;
    std::string name,version,owner;
    json object;
    bool has_success = false;
    std::vector<json> dependencies;
    std::string custom_install_directory;
public:
    ProjectFileParser(File* f) {
        std::string contents = f->getContents();
        try {
            object = json::parse(contents);
        }
        catch(...) {
            error_msg = "An exception was thrown during parsing of the JSON data";
            return;
        }
        try {
            std::exception e;
            if(!(object["name"].is_string())) throw e;
            if(!(object["version"].is_string())) throw e;
            if(!(object["owner"].is_string())) throw e;
        }
        catch (std::exception& e) {
            std::cout<<"B";
            error_msg = "There was an error parsing your package definition file. Check the file for typos";
            return;
        }
        name = object["name"];
        version = object["version"];
        owner = object["owner"];
        json deproot = object["dependencies"];
        if (!deproot.is_array()) {
            error_msg = "There was an error parsing the dependencies for your project. Make sure they are formatted correctly";
            return;
        }
        for (auto package : deproot) {
            dependencies.push_back(package);
        }
    }
    
    std::string get_error() {
        return error_msg;
    }
    
};

class LSFileParser {
};

#endif
