#ifndef RESOURCE_LOADER_H
#define RESOURCE_LOADER_H

#include <string>

class ResourceLoader
{
    public:
        ResourceLoader();
        ResourceLoader(const ResourceLoader& other);
        virtual ~ResourceLoader();
        static std::string loadShader(const std::string filename);


    protected:

    private:
        void operator=(const ResourceLoader& other) {}
};

#endif // RESOURCE_LOADER_H
