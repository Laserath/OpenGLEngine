#ifndef ENGINE_TIME_H
#define ENGINE_TIME_H

#include <ctime>
#include <chrono>

#define SECOND 1000000000

namespace ogle {
class Time
{
    public:
        Time();
        virtual ~Time();
        static int64_t getTimeInNanoseconds();
        int64_t getDeltaNano();
        float getDeltaMilli();
        float getDelta();

        void markTime();

    protected:

    private:
        Time(const Time& other) { }
        void operator=(const Time& other) { }

        int64_t m_previousTime;
};
}

#endif // ENGINE_TIME_H
