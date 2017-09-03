#ifndef RESOURCE_LOADER_H
#define RESOURCE_LOADER_H

#include <string>
#include <memory>
#include <vector>
#include <assimp/scene.h>
#include "mesh.h"

namespace ogle {
class ResourceLoader
{
    public:
        ResourceLoader();
        ResourceLoader(const ResourceLoader& other);
        virtual ~ResourceLoader();
        static std::shared_ptr<std::string> loadShader(const std::string filename);
        static std::shared_ptr<std::vector<Mesh>> loadMesh(const std::string filename);


    protected:

    private:
        static std::shared_ptr<std::vector<Mesh>> processNode(aiNode *node, const aiScene *scene);
        static Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        void operator=(const ResourceLoader& other) {}
};
}

#endif // RESOURCE_LOADER_H
