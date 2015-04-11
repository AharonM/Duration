#include <ctime>
#include <string>
#include <sstream>

#include "clock_utils.h"

using namespace std;



Duration Duration::buildDuration(clock_t dur)
{
    Duration obj;
    obj.tics= dur % CLOCKS_PER_SEC;

    obj.seconds= dur / CLOCKS_PER_SEC % SECONDS_PER_MINUTE;

    obj.minutes= dur / CLOCKS_PER_SEC / SECONDS_PER_MINUTE % MINUTES_PER_HOUR;

    obj.hours= dur / CLOCKS_PER_SEC / SECONDS_PER_MINUTE / MINUTES_PER_HOUR;

    return obj;
}

string asString(Duration obj)
{
    string time;
    stringstream ss;
    ss << obj.hours << ":" << obj.minutes << ":" << obj.seconds << ":" << obj.tics;
    ss >> time;
    return time;
}

