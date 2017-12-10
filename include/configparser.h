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

#endif
