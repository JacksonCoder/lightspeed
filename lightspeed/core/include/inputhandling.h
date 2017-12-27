// includehandling.h
#ifndef INPUTHANDLING
#define INPUTHANDLING
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../globals.h"

class InputHandleOutput {
    std::map<std::string,std::string> arguments;
    std::vector<std::string> reg_args;
    std::string option;
    public:
        InputHandleOutput(std::map<std::string,std::string> args);
        std::map<std::string,std::string> get_args();
        std::vector<std::string> get_reg_args();
        std::string get_option();
};
class InputHandle : public ModuleObject {
    std::map<std::string,std::string> buildargs;
public:
    InputHandle(int,char**);
    
    void build();
    InputHandleOutput out();
};



#endif
