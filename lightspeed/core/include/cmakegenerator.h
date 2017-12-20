// CMakeGenerator
#include "../external/json.hpp"
#include "enviroment.h"
using json = nlohmann::json;


class CMakeGenerator {
    EState* env;
    std::string output;
    public:
        CMakeGenerator(EState*);
        void compile();
        std::string get_output();
        
};
