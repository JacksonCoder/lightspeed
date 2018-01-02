#include "include/inputhandling.h"
#include "include/optionswitch.h"
#include "include/enviroment.h"
#include <fstream>
// Main function for LightSpeed
int main (int argc,char** argv) {
    // Create an input handle and prebuild the outcome
    InputHandle* inputhandler = new InputHandle(argc,argv);
    inputhandler->build();
    
    // Load in the enviroment and verify it's integrity
    std::cout << "Loading the local enviroment." << std::endl;
    EState* estate = new EState(inputhandler->out());
    if(!estate->setup()) {
        estate->fail();
    }
    //Send to switch
    OptionSwitch* o = new OptionSwitch(estate);
    o->run_switch(); // Main entry point for package manager
    //estate.clean();
    delete estate;
    delete inputhandler;
    delete o;
    return 0;
}
