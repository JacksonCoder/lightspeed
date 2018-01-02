// optionswitch.h

#ifndef OPTION_SWITCH_H
#define OPTION_SWITCH_H

#include "enviroment.h"
#include "help.h"
#include "../globals.h"
#include "cmakegenerator.h"
#include "network.h"
#include "codegrab.h"

class OptionSwitch : public ModuleObject {
    std::tuple<std::vector<std::string> > local_conf;
    std::string option;
    EState* env;
    public:
    OptionSwitch(EState*);
    
    void run_switch ();
    
};



#endif
