#include "../../include/optionswitch.h"

OptionSwitch::OptionSwitch(EState* env) {
        local_conf = env->get_state();
        option = env->get_option();
        this->env = env;
}

void OptionSwitch::run_switch()
{
    if ( option == "help" || option == "version") {
        help();
        return;
    }
    if (option == "status") {
        std::cout << "Checking state of current project..." << std::endl;
        env->stability_check();
        return;
    }
    /*
    if (option == "install") {
        std::cout<< "Not implemented yet" << std::endl;
        return;
    }
    if (option == "create") {
        std::cout<< "Not implemented yet" << std::endl;
        return;
    }
    if (option == "load") {
        std::cout<< "Not implemented yet" << std::endl;
        return;
    }
    if (option == "search") {
        std::cout<< "Not implemented yet" << std::endl;
        return;
    }
    if (option == "build") {
        std::cout<< "Not implemented yet" << std::endl;
        return;
    }
    if (option == "repo") {
        std::cout<< "Not implemented yet" << std::endl;
        return;
    }
    if (option == "remove") {
        std::cout<< "Not implemented yet" << std::endl;
        return;
    }
    */
    if (option == "sandbox") {
        std::cout << "Welcome to the LightSpeed beta sandbox! Test potential features here!" << std::endl;
        for(auto s : SANDBOX_OPTIONS) {
            std::cout << s.first << " -> " << s.second << std::endl;
        }
        std::cout << "Please select a beta feature to test:";
        char c;
        std::cin >> c;
        if(SANDBOX_OPTIONS[c] == "compilation") {
            //Run compilation
            std::cout << "--- Starting compilation sandbox ---" << std::endl;
            std::cout << "Enter CMake version:";
            std::string v; std::cin >> v;
            std::cout <<"Enter a list of file paths (enter '!' to stop entering items:";
            std::string buffer;
            std::vector<std::string> libraries;
            while(buffer != "!") {
                std::cin >> buffer;
                if(buffer != "!")
                    libraries.push_back(buffer);
            }
            env->set_config_state(v,libraries,{});
            std::cout<<"Generating CMake linkage file..." << std::endl;
            auto compiler = CMakeGenerator(env);
            compiler.compile();
            std::cout << "Done.\nResult:\n" << compiler.get_output();
            return;
        }
    }
    env->stability_check(); // Fails because of invalid command
}
