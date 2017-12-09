// includehandling.h
#ifndef INPUTHANDLING
#define INPUTHANDLING
#include <iostream>
#include <map>
#include <string>

class InputHandleOutput {
    std::map<std::string,std::string> arguments;
    public:
        InputHandleOutput(std::map<std::string,std::string> args) {
            arguments = args;
        }
        std::map<std::string,std::string> get_args() {
            return arguments;
        }
};
class InputHandle {
    std::map<std::string,std::string> buildargs;
public:
    InputHandle(int argc, char** argv)
    {
        for(int i = 0; i < argc; i++)
        {
            buildargs[argv[i]] = "a";
        }
    }
    
    void build() {
        
    }
    InputHandleOutput out() {
        return InputHandleOutput(buildargs);
    }
};



#endif
