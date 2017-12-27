#ifndef CMAKEGENERATOR_LS
#define CMAKEGENERATOR_LS

// CMakeGenerator
#include "../external/json.hpp"
#include "enviroment.h"
using json = nlohmann::json;


class CMakeGenerator : public ModuleObject {
    EState* env;
    std::string output;
    public:
        CMakeGenerator(EState*);
        void compile();
        std::string get_output();
        
};

#endif
