#include "../../include/inputhandling.h"

InputHandleOutput::InputHandleOutput(std::map<std::string,std::string> args) {
            
            for(auto a : args) {
                if(a.second == "__empty!") {
                    reg_args.push_back(a.first);
                }
                else {
                    arguments[a.first] = a.second;
                }
            }
        }
std::map<std::string,std::string> InputHandleOutput::get_args() {
    return arguments;
}
std::vector<std::string> InputHandleOutput::get_reg_args() {
    return reg_args;
}
std::string InputHandleOutput::get_option() {
    if(arguments["option"] != "") {
        return arguments["option"];
    }
    return "";
}

InputHandle::InputHandle(int argc, char** argv) {
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

InputHandleOutput InputHandle::out() {
    return InputHandleOutput(buildargs);
}

void InputHandle::build() {}
