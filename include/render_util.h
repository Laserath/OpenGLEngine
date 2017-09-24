#ifndef RENDER_UTIL_H
#define RENDER_UTIL_H

#include <string>

class RenderUtil
{
    public:
        RenderUtil();
        RenderUtil(const RenderUtil& other);
        virtual ~RenderUtil();

        static void clearScreen();
        static void initGraphics();
        static void postInitGraphics();
        static void setTextures(bool enabled);
        static void unbindTexture();
        static void shutdown();
        static std::string getOpenGLVersion();

    protected:

    private:
        void operator=(const RenderUtil& other);
};

#endif // RENDER_UTIL_H
