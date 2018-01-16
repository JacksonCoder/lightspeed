#include "../../include/optionswitch.h"

OptionSwitch::OptionSwitch(EState* env) {
        local_conf = env->get_state();
        option = env->get_option();
        this->env = env;
}

void OptionSwitch::run_switch()
{
    if ( option == "help" || option == "version") {
        help();
        return;
    }
    if (option == "status") {
        std::cout << "Checking state of current project..." << std::endl;
        try {
            env->stability_check();
        } catch(std::exception&) {
            std::cout << "Global config file is not stable" << std::endl;
        }
        std::cout << "Global config file is stable." << std::endl;
        return;
    }
    if (option == "sandbox") {
        std::cout << "Welcome to the LightSpeed beta sandbox! Test potential features here!" << std::endl;
        for(auto s : SANDBOX_OPTIONS) {
            std::cout << s.first << " -> " << s.second << std::endl;
        }
        std::cout << "Please select a beta feature to test:";
        char c;
        std::cin >> c;
        if(SANDBOX_OPTIONS[c] == "compilation") {
            //Run compilation
            std::cout << "--- Starting compilation sandbox ---" << std::endl;
            std::cout << "Enter CMake version:";
            std::string v; std::cin >> v;
            std::cout <<"Enter a list of file paths (enter '!' to stop entering items:";
            std::string buffer;
            std::vector<std::string> libraries;
            while(buffer != "!") {
                std::cin >> buffer;
                if(buffer != "!")
                    libraries.push_back(buffer);
            }
            env->set_config_state(v,libraries,{});
            std::cout<<"Generating CMake linkage file..." << std::endl;
            auto compiler = CMakeGenerator(env);
            compiler.compile();
            std::cout << "Done.\nResult:\n" << compiler.get_output();
            return;
        }
        if(SANDBOX_OPTIONS[c] == "utils") {
            // Run utils demo
            std::cout<< "Enter directory (file or HTTP):";
            std::string file;
            std::cin >> file;
            getSource source_grabber(file);
            source_grabber.get();
            return;
        }
        if(SANDBOX_OPTIONS[c] == "network") {
            // No current network features
            std::string path;
            std::cout << "Enter URL:";
            std::cin >> path;
            HTTPConnection h(path);
            std::cout << "Directory output:" << std::endl;
            h.fetch(true,"");
            std::cout << std::endl << "Result:" << std::endl;
            if (h.did_fail()) std::cout << "There was an error trying to connect" << std::endl;
            h.getResult().print();
            return;
        }
        if(SANDBOX_OPTIONS[c] == "parsing") {
            // No current parsing features
            std::cout << "Enter file location of package file:";
            std::string loc;std::cin>>loc;
            ProjectFileParser parser = ProjectFileParser(FileLoader::load(loc,true));
            if(parser.did_fail()) {
                std::cout << "--- ERROR ---" << std::endl;
                std::cout << parser.get_error() << std::endl;
                return;
            }
            std::cout << "File parsed successfully. Details:" << std::endl;
            
            std::cout << "List of dependencies:\n";
            for(auto j : parser.get_dependencies()) {
                std::cout << j << std::endl;
            }
            std::cout << "Build information:\n";
            std::cout << "Should generate CMake linkage file: " << parser.make_cmake_link() << std::endl;
            std::cout << "Build system: " << parser.type() << std::endl;
            std::cout << "Directories/files to include:" << std::endl;
            for(auto i : parser.get_include()) {
                std::cout << i << std::endl;
            }
            return;
        }
    }
    ErrorManager::error(option + " is not a valid command. Run `lightspeed-bin help` for a list of commands","optionswitch",true); // This shouldn't be run, but we should catch things if they do somehow get there.
}
