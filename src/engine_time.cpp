#include "engine_time.h"

#include <iostream>

using time_point = std::chrono::_V2::system_clock::time_point;

namespace ogle {
Time::Time()
{
    m_previousTime = getTimeInNanoseconds();
}

Time::~Time()
{

}

int64_t Time::getTimeInNanoseconds() {
    time_point time = std::chrono::high_resolution_clock::now();
    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(time.time_since_epoch()).count();
    return nanoseconds;
}

int64_t Time::getDelta() {
    return Time::getTimeInNanoseconds() - m_previousTime;
}

void Time::markTime() {
    m_previousTime = Time::getTimeInNanoseconds();
}


}
