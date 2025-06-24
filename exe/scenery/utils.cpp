////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "utils.hpp"
#include <ctime>
#include <cstdio>

//std::string             iso8601basic_datetime(const std::chrono::high_resolution_clock::time_point& pt)
//{
//}

std::string             iso8601basic_now()
{
    time_t  now;
    time(&now);
    
    struct tm  mt;
    localtime_r(&now, &mt);
    char        thetime[256];
    sprintf(thetime, "%04d%02d%02d-%02d%02d%02d", 
        1900+mt.tm_year, 1+mt.tm_mon, 1+mt.tm_mday, 
        mt.tm_hour, mt.tm_min, mt.tm_sec
    );
    return thetime;
}

