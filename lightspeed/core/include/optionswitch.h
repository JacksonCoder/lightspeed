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
    OptionSwitch(EState*);
    
    void run_switch ();
    
};



#endif
