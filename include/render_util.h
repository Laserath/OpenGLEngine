#ifndef RENDER_UTIL_H
#define RENDER_UTIL_H


class RenderUtil
{
    public:
        RenderUtil();
        RenderUtil(const RenderUtil& other);
        virtual ~RenderUtil();

        static void clearScreen();
        static void initGraphics();
        static void shutdown();

    protected:

    private:
        void operator=(const RenderUtil& other);
};

#endif // RENDER_UTIL_H
