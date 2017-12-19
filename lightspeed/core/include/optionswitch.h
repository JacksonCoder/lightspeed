// optionswitch.h

#ifndef OPTION_SWITCH_H
#define OPTION_SWITCH_H

#include "enviroment.h"
#include "help.h"

class OptionSwitch {
    std::tuple<std::string,std::string,bool> local_conf;
    std::string option;
    EState* env;
    public:
    OptionSwitch(EState* env) {
        local_conf = env->get_state();
        option = env->get_option();
        this->env = env;
    }
    
    void run_switch () {
        if ( option == "help" || option == "version") {
            help();
            return;
        }
        if (option == "status") {
            std::cout << "Checking state of current project..." << std::endl;
            env->stability_check();
            return;
        }
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
        env->stability_check(); // Fails because of invalid command
        
    }
    
};



#endif
