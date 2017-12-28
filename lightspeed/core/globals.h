#ifndef GLOBAL_H_LS
#define GLOBAL_H_LS
#include <string>
#include <vector>
#include <map>

extern const std::string LS_VERSION;
extern std::vector<std::string> CMD_OPTIONS;
extern std::map<char,std::string> SANDBOX_OPTIONS;

class ModuleObject {
    bool has_failed;
public:
    bool did_fail();
    void set_fail(bool);
};

#endif
