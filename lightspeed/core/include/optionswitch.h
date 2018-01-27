// optionswitch.h

#ifndef OPTION_SWITCH_H
#define OPTION_SWITCH_H

#include "enviroment.h"
#include "help.h"
#include "../globals.h"
#include "cmakegenerator.h"
#include "network.h"
#include "codegrab.h"

class OptionSwitch : public DispatcherClass<EState*> {
    public:
    virtual void dispatch(EState*);
    
};



#endif
