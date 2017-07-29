#ifndef RESOURCE_LOADER_H
#define RESOURCE_LOADER_H

#include <string>
#include <memory>

class ResourceLoader
{
    public:
        ResourceLoader();
        ResourceLoader(const ResourceLoader& other);
        virtual ~ResourceLoader();
        static std::shared_ptr<std::string> loadShader(const std::string filename);


    protected:

    private:
        void operator=(const ResourceLoader& other) {}
};

#endif // RESOURCE_LOADER_H
