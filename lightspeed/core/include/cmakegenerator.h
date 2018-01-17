#ifndef CMAKEGENERATOR_LS
#define CMAKEGENERATOR_LS

// CMakeGenerator
#include "../external/json.hpp"
#include "enviroment.h"
using json = nlohmann::json;


class CMakeGenerator : public ProcessClass<std::string> {
    EState* env;
    std::string output;
    public:
        CMakeGenerator(EState*);
        virtual void run();
        virtual std::string fetch();
        
};

#endif
