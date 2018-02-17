#include "../../../include/errormanager.h"

std::vector<Error> ErrorManager::error_stack;

void ErrorManager::release() {
    if(error_stack.size() > 0) {
        // Fail
        std::cout << "Errors have occured and LightSpeed was not able to continue. Below is a list of errors that have occured, in the order they were annouced" << std::endl;
        for(auto error : error_stack) {
            std::cout << "------\n";
            if(error.fatal) std::cout << "FATAL ";
            std::cout << "ERROR IN " + error.module_name + " MODULE:\n" + error.error_msg + "\n";
        }
        std::cout << "Total of " + std::to_string(error_stack.size()) + " errors occured. Exiting now" << std::endl;
        exit(1);
    }
}

void ErrorManager::error(std::string error, std::string mn,bool is_fatal)
{
    error_stack.push_back({error,mn,is_fatal});
    if (is_fatal) release();
}
