#include "resource_loader.h"

#include <iostream>
#include <fstream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

// For Texture loading check out: https://www.youtube.com/watch?v=yQx_pMsYqzU

namespace ogle {
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

std::shared_ptr<std::vector<Mesh>> ResourceLoader::loadMesh(const std::string filename) {
    Assimp::Importer importer;

    const aiScene *scene = importer.ReadFile(filename, aiProcess_Triangulate | aiProcess_FlipUVs);
    if(!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode ) {
        std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;

        exit(1);
    }
    std::string directory = filename.substr(0, filename.find_last_of('/'));

    return processNode( scene->mRootNode, scene);
}

std::shared_ptr<std::vector<Mesh>> ResourceLoader::processNode(aiNode *node, const aiScene *scene) {
    std::shared_ptr<std::vector<Mesh>> meshes = std::make_shared<std::vector<Mesh>>();
    for (GLuint i = 0; i < node->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];

        meshes->push_back(processMesh(mesh, scene));
    }

    for (GLuint i = 0; i < node->mNumChildren; i++) {
        std::shared_ptr<std::vector<Mesh>> children = processNode(node->mChildren[i], scene);
        meshes->insert(meshes->end(), children->begin(), children->end());
    }
    return meshes;
}

Mesh ResourceLoader::processMesh(aiMesh *mesh, const aiScene *scene) {
    std::shared_ptr<Mesh> value = std::make_shared<Mesh>();

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    for (GLuint i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;
        Vector3f vec;

        vec.setX(mesh->mVertices[i].x);
        vec.setY(mesh->mVertices[i].y);
        vec.setZ(mesh->mVertices[i].z);
        vertex.setPos(vec);

        //vec.setX(mesh->mNormals[i].x);
        //vec.setY(mesh->mNormals[i].y);
        //vec.setZ(mesh->mNormals[i].z);
        //vertex.setNorm(vec);

        //if (mesh->mTextureCoords[0]) {
        //    Vector2f vec;

        //    vec.setX(mesh->mTextureCoords[0][i].x);
        //    vec.setY(mesh->mTextureCoords[0][i].y);

        //    vertex.setTexCoords(vec);
        //} else {
        //    vertex.setTexCoords(0.0f, 0.0f);
        //}

        vertices.push_back(vertex);
    }

    for(GLuint i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];

        for(GLuint j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }

    //if (mesh->mMaterialIndex >= 0) {
    //    aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];

    //    std::vector<Texture> diffuseMaps = loadMaterialTexture( material, aiTextureType_DIFFUSE, "texture_diffuse");
    //    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

    //    std::vector<Texture> specularMaps = loadMaterialTexture( material, aiTextureType_SPECULAR, "texture_specular");
    //    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    //}

    value->addVertices(vertices, indices);

    return *value;
}

//std::vector<Texture> loadMaterialTextures(aiMaterial *material, aiTextureType type, std::string typeName) {
//    vectore<Texture> textures;

//    for(GLuint i = 0; i < material->GetTextureCount(type); i++) {
//        aiString str;
//        material->getTexture(type, i, &str);

//        GLboolean skip = false;
//        for(GLuint j = 0; j < textures_loaded.size(); j++) {
//            if (textures_loaded[j].path == str) {
//                textures.push_back(textures_loaded[j]);
//                skip = true;

//                break;
//            }
//        }

//        if (!skip) {
//            Texture texture;
//            texture.id = TextureFromFile(str.C_Str(), this->directory);
//            texture.type = typeName;
//            texture.path = str;
//            texture.push_back(texture);

//            this->textures_loaded.push_back(texture);
//        }

//    }
//    return textures;
//}

//GLint TextureFromFile(const char *path, std::string directory) {
//    string filename = std::string(path);
//    filename = directory + "/" + filename;
//    GLuint textureID;
//    glGenTextures(1, &textureID);

//    int width, height;
//    unsigned char *image = SOIL_load_image( filename.c_str(), &width, &height, 0, SOIL_LOAD_RGB);

//    glBindTexture(GL_TEXTURE_2D, textureID);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//    glGenerateMipmap(GL_TEXTURE_2D);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_FILTER, GL_LINEAR);
//    glBindTexture(GL_TEXTURE_2D, 0);

//    SOIL_free_image_data(image);

//    return textureID;
//}

ResourceLoader::~ResourceLoader()
{
    //dtor
}

}

