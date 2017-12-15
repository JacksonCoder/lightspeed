// includehandling.h
#ifndef INPUTHANDLING
#define INPUTHANDLING
#include <iostream>
#include <map>
#include <string>
#include <vector>

class InputHandleOutput {
    std::map<std::string,std::string> arguments;
    std::vector<std::string> reg_args;
    std::string option;
    public:
        InputHandleOutput(std::map<std::string,std::string> args) {
            
            for(auto a : args) {
                if(a.second == "__empty!") {
                    reg_args.push_back(a.first);
                }
                else {
                    arguments[a.first] = a.second;
                }
            }
        }
        std::map<std::string,std::string> get_args() {
            return arguments;
        }
        std::vector<std::string> get_reg_args() {
            return reg_args;
        }
        std::string get_option() {
            if(arguments["option"] != "") {
                return arguments["option"];
            }
            return "";
        }
};
class InputHandle {
    std::map<std::string,std::string> buildargs;
public:
    InputHandle(int argc, char** argv)
    {
        argc -= 1;
        std::vector<std::string> args;
        for(int argv_i = 1; argv_i < argc+1; argv_i++) {
            args.push_back(argv[argv_i]);
        }
        if (argc > 0) {
            buildargs["option"] = args[0];
        }
        for(int arg_i = 1; arg_i < argc; arg_i++) {
            if(args[arg_i][0] == '-' && args[arg_i][1] == '-') {
                buildargs[args[arg_i]] = args[arg_i+1];
                arg_i++;
            }
            else {
                buildargs[args[arg_i]] = "__empty!";
            }
        }
    }
    
    void build() {
        
    }
    InputHandleOutput out() {
        return InputHandleOutput(buildargs);
    }
};



#endif
