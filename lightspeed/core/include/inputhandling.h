// includehandling.h
#ifndef INPUTHANDLING
#define INPUTHANDLING
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "errormanager.h"
#include "../globals.h"

class InputHandleOutput : StatusClass {
    std::map<std::string,std::string> arguments;
    std::vector<std::string> reg_args;
    std::string option;
    public:
        InputHandleOutput();
        void construct(std::map<std::string,std::string> args);
        std::map<std::string,std::string> get_args();
        std::vector<std::string> get_reg_args();
        std::string get_option();
};
class InputHandle : public  ProcessClass<InputHandleOutput> {
    std::map<std::string,std::string> buildargs;
public:
    InputHandle(int argc, char** argv);
    
    virtual void run();
    virtual InputHandleOutput fetch();
};



#endif
