#include "../../include/cmakegenerator.h"

CMakeGenerator::CMakeGenerator(Estate* env) {
    this->env = env;
}

void CMakeGenerator::compile()
{
    //Get all linked libraries
    env->validate_all_deps_built();
    auto linked_libraries = env->get_linked_library_paths();
    
    //Get CMake version required
    std::string cmake_v = env->get_req_cmake_version();
    
    //Get project name
    std::string proj_name = env->get_state()[0]; //First item in tuple is project name
    
    //Get exports
    auto exports = env->get_exports();
    
    // Now we finally start building the file
    std::string result;
    result += "# Auto-generated by LightSpeed: https://github.com/JacksonCoder/LightSpeed\n";
    result += "# For project: " + proj_name + "\n";
    result += "cmake_minimum_required (VERSION " + cmake_v + ")\n";
    result += "project(" + proj_name + ")\n\n";
    for(auto l : linked_libraries) {
        result += "target_link_libraries(" + l + ")\n";
    }
    
    
    this->output = result;
}

std::string CMakeGenerator::get_output()
{
    return output;
}