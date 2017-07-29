#include "resource_loader.h"

#include <iostream>
#include <fstream>

ResourceLoader::ResourceLoader()
{
    //ctor
}

ResourceLoader::ResourceLoader(const ResourceLoader& other)
{
    //copy ctor
}

std::shared_ptr<std::string> ResourceLoader::loadShader(const std::string filename) {
    std::string line;
    std::shared_ptr<std::string> shaderCode = std::make_shared<std::string>();
    std::ifstream shaderFile(filename);
    if (shaderFile.is_open()) {
        while (getline(shaderFile, line)) {
            shaderCode->append(line + "\n");
        }
        shaderFile.close();
    } else {
        std::cerr << "Couldn't Open File: " << filename << std::endl;
    }
    return shaderCode;
}

ResourceLoader::~ResourceLoader()
{
    //dtor
}



