#include "../../../include/inputhandling.h"

void InputHandleOutput::construct(std::map<std::string,std::string> args) {
            
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


InputHandle::InputHandle(int argc, char** argv) : ProcessClass<InputHandleOutput>() {
    // Refactor this code
    
    // Verify some things
    
    
    if (argc<1) {
        has_failed = true;
        ErrorManager::error("There were no command line arguments passed to the program.","input handling",false);
        return;
    }
    
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
    result.construct(buildargs);
    std::cout << "REACHED" << std::endl;
}

InputHandleOutput::InputHandleOutput()
{
    
}


void InputHandle::run()
{
}

InputHandleOutput InputHandle::fetch()
{
    return result;
}

