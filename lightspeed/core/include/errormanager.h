#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H
#include <string>
#include <vector>
#include <iostream>

class Error {
public:
    std::string error_msg;
    std::string module_name;
    bool fatal;
    Error(std::string em, std::string mn,bool fatal) {
        error_msg = em;
        module_name = mn;
        this->fatal = fatal;
    }
};


/*
 * So you are probably wondering what the heck this things does.
 * Essentially, it stores errors and releases them (exiting and printing them to the screen),
 * at intervals deemed safe to exit by the program (usually between module uses)
*/


class ErrorManager {
    static std::vector<Error> error_stack;
public:
    static void release(); // Not to be confused with a memory release function
    static void error(std::string,std::string,bool);
};


#endif
