// enviroment.h

#ifndef ENVIROMENT_H
#define ENVIROMENT_H
#include <string>
#include <tuple>
#include "inputhandling.h"
#include "fileloader.h"
#include "configparser.h"
#include "../globals.h"

using namespace std;
class EState {
    string conf_access;
    string error_status = "No error occured";
    
    
    // state variables
    
    string s_LSPATH;
    bool s_LATEST;
    string s_PROJECTNAME;
    bool s_integrity = true;
    string s_error;
    
    string option;
    
    public:
        EState(InputHandleOutput);
        bool setup();
        void fail();
        
        void fail_with_external(std::string);
        
        void stability_check();
        
        std::tuple<std::string,std::string,bool> get_state();
        
        std::string get_option();
};

#endif
