#include "include/inputhandling.h"
#include "include/optionswitch.h"
#include "include/enviroment.h"
#include "include/errormanager.h"
#include <fstream>
// Main function for LightSpeed
int main (int argc,char** argv) {
    // Create an input handle and prebuild the outcome
    InputHandle* inputhandler = new InputHandle(argc,argv);
    inputhandler->run();
    ErrorManager::release();

    
    EState* estate = new EState(inputhandler->fetch());
    estate->stability_update();
    ErrorManager::release();
    //Send to switch
    OptionSwitch* o = new OptionSwitch();
    o->dispatch(estate); // Main entry point for package manager
    ErrorManager::release();
    //estate.clean();
    delete estate;
    delete inputhandler;
    delete o;
    return 0;
}
