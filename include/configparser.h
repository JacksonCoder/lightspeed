// configparser.h

#ifndef CONFIGPARSER
#define CONFIGPARSER
#include "file.h"
#include <string>

class ConfigParser {
    bool has_success = false;
    std::string error = "No error has occured";
    
public:
    ConfigParser(File* f) {
        // For now, always return success
        has_success = true;
    }
    
    bool success() {
        return has_success;
    }
    
    std::string error_msg() {
        return error;
    }
    
};

#endif
