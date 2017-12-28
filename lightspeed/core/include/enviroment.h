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
    - fail() should only be called when using the EState pointer inside a function. DO NOT CREATE AN EState INSTANCE FOR THE SOLE PURPOSE OF CALLING FAIL (or for any reason, for that matter)
    - EState is a singleton class. Only one should exist, and should be created in the main.cpp file. Whenever referencing an EState class, use pointers, AND NEVER DELETE IT FOR ANY REASON WHATSOEVER (that's handled in main).
    - EState does NOT inherit from the ModuleObject class because A. it isn't a process object and B. It has it's own stability_check() function. In the future, stability_check() should throw an exception, not abort the program.
    - When using EState, you can somewhat consider it as a glboal container. Not to be confused with definitions in globals.h, as those are constant globals.
Also, you might be wondering what a process object is. It's a class that runs some sort of function involved in a LS command sequence. (so most 'top-level' classes) Do not make objects used by other process objects process objects themselves.
*/

class EState {
    string conf_access;
    string error_status = "No error occured";
    
    
    // state variables
    
    vector<string> s_repos;
    bool s_integrity = true;
    string s_error;
    
    string option;
    
    vector<string> c_linked_libraries, c_exports;
    string c_cmake_v;
    bool c_integrity = true;
    string c_error;
    
    public:
        EState(); //Please use for testing only, if you don't want nasty segmentation faults in production.
        EState(InputHandleOutput);
        bool setup();
        void fail();
        
        void fail_with_external(std::string);
        
        void stability_check();
        
        std::tuple<vector<string> > get_state();
        
        std::string get_option();
        
        std::vector<std::string> get_linked_library_paths();
        
        std::string get_req_cmake_version();
        
        std::vector<std::string> get_exports();
        
        void set_config_state(std::string,std::vector<std::string>,std::vector<std::string>);
};

#endif
