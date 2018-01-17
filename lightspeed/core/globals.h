#ifndef GLOBAL_H_LS
#define GLOBAL_H_LS
#include <string>
#include <vector>
#include <map>

extern const std::string LS_VERSION;
extern std::vector<std::string> CMD_OPTIONS;
extern std::map<char,std::string> SANDBOX_OPTIONS;

template <typename T>
class ProcessClass {
    bool has_failed;
    T result;
public:
    bool did_fail();
    virtual void run() = 0;
    virtual T fetch();
};

class StatusClass {
    // This class doesn't have too much stuff built in
    bool is_stable;
public:
    virtual void stability_update();
    bool stable();
};

template <typename T>
class DispatcherClass {
public:
    virtual void dispatch(T input) = 0;
};

#endif
