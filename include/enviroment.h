// enviroment.h

#ifndef ENVIROMENT
#define ENVIROMENT
#include <string>
#include "inputhandling.h"
#include "fileloader.h"
#include "configparser.h"

using namespace std;
class EState {
    string conf_access;
    string error_status = "No error occured";
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
        }
        bool is_stable() {
            //Test config file exists
            File* file = FileLoader::load(conf_access,true);
            if (!file->open()) {
                error_status = "Could not access local configuration file: '" + conf_access + "'. Please check that the file exists or you are in the proper directory";
                return false;
            }
                ConfigParser c = ConfigParser(file);
            if(!c.success()) {
              error_status = c.error_msg();
              return false;
            }
            return true;
        }
        void fail() {
            std::cerr<<"An error occured while running LightSpeed:"<<std::endl;
            std::cerr<<error_status<<std::endl;
            exit(1);
        }
};

#endif
