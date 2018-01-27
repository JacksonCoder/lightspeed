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
/*
And this is the part where I write down documentation that nobody will probably read anyway. If anything, it'll help me be consistent with design strategies.
--- EState ---
Desciption: A global enviroment state that is local to each LightSpeed process.
Tips:
    - EState can throw fatal errors if it detects something is wrong. This is the only class that does that (All other errors thrown by other modules should ALWAYS BE nonfatal)
    - EState is a state, not a process object, so it does not inherit from ModuleObject
    - All variable information about the enviroment LightSpeed is running in goes in here. This includes command line arguments and global/local file configurations.
    - When using EState, you can somewhat consider it as a glboal container. Not to be confused with definitions in globals.h, as those are constant globals.
Also, you might be wondering what a process object is. It's a class that runs some sort of function involved in a LS command sequence. It will set a flag saying it failed and return early if something goes wrong. It can also throw errors for which the parent process can catch and release. Usually, errors are preferred over has_failed flags.
*/

class EState : public StatusClass {
    // enviromental / command line variables
    string option;
    string conf_access;
    
    // state variables
    
    vector<string> s_repos;
    bool s_integrity = true;
        
    vector<string> c_linked_libraries, c_exports;
    string c_cmake_v;
    
    public:
        EState(); //Please use for testing only, if you don't want nasty segmentation faults in production.
        EState(InputHandleOutput);
        
        std::tuple<vector<string> > get_state();
        
        std::string get_option();
        
        std::vector<std::string> get_linked_library_paths();
        
        std::string get_req_cmake_version();
        
        std::vector<std::string> get_exports();
        
        void set_config_state(std::string,std::vector<std::string>,std::vector<std::string>);
};

#endif
