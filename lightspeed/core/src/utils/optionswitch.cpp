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
        try {
            env->stability_check();
        } catch(std::exception&) {
            env->fail();
        }
        std::cout << "Global config file is stable." << std::endl;
        return;
    }
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
        if(SANDBOX_OPTIONS[c] == "utils") {
            // Run utils demo
            std::cout<< "Enter directory (file or HTTP):";
            std::string file;
            std::cin >> file;
            getSource source_grabber(file);
            std::cout << source_grabber.get() <<std::endl;
            return;
        }
        if(SANDBOX_OPTIONS[c] == "network") {
            // No current network features
            std::cout << "Network is still being created. Sorry about that!" << std::endl;
            return;
        }
        if(SANDBOX_OPTIONS[c] == "parsing") {
            // No current parsing features
            std::cout << "Parsing is still being created. Sorry about that!" << std::endl;
            return;
        }
    }
    env->fail(); // Or should we call set_fail()? Maybe do later if needs be.
}
