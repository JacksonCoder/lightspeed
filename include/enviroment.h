// enviroment.h

#ifndef ENVIROMENT_H
#define ENVIROMENT_H
#include <string>
#include <tuple>
#include "inputhandling.h"
#include "fileloader.h"
#include "configparser.h"

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
        EState(InputHandleOutput i) {
            const string DEFAULT_ACCESS = ".lsconf.json";
            // Check if special conf was specified
            if (i.get_args()["conf"] != "") {
                conf_access = i.get_args()["conf"];
            }
            else {
                conf_access = DEFAULT_ACCESS;
            }
            const string DEFAULT_ACTION = "help";
            // Check if option was specified
            if (i.get_option() != "") {
                option = i.get_option();
            }
            else {
                option = DEFAULT_ACTION;
            }
            cout<< option << endl;
        }
        bool setup() {
            //Test config file exists
            File* file = FileLoader::load(conf_access,true);
            if (!file->open()) {
                error_status = "Could not access local configuration file: '" + conf_access + "'. Please check that the file exists or you are in the proper directory";
                return false;
            }
            ConfigParser c = ConfigParser(file);
            if(!c.success()) {
                s_error = c.error_msg();
                s_integrity = false;
            } else {
                s_LSPATH = c.getlspath();
                s_LATEST = c.getlatest();
                s_PROJECTNAME = c.getprojectname();
            }
            return true;
        }
        void fail() {
            std::cerr<<"An error occured while running LightSpeed:"<<std::endl;
            std::cerr<<error_status<<std::endl;
            exit(1);
        }
        
        void fail_with_external(std::string error) {
            error_status = error;
            fail();
        }
        
        void stability_check() {
            if(s_error != "") error_status = s_error;
            if(!s_integrity) {
                fail();
            }
        }
        
        std::tuple<std::string,std::string,bool> get_state() {
            return std::make_tuple(s_PROJECTNAME, s_LSPATH,s_LATEST);
        }
        
        std::string get_option() {
            return option;
        }
};

#endif
