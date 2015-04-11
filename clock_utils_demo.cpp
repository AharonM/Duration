#include <iostream>
#include <string>

#include "clock_utils.h"

using namespace std;

int main()
{
    cout << "Clock ticks per second: " << CLOCKS_PER_SEC << endl;

    Duration obj,obj2;
    clock_t start_time = clock();
    for (int i = 0; i < 1000000; i++)
        i / 17;
    clock_t end_time = clock();

    clock_t duration = end_time - start_time;
    obj2=obj.buildDuration(duration);
    cout << "Single loop 0 to 1,000,000: " << asString(obj2) << endl;

    start_time = clock();
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000000; j++)
            i / 17;
    end_time = clock();

    duration = end_time - start_time;
    obj2=obj.buildDuration(duration);
    cout << "Nested loops 0 to 1,000 / 0 to 1,000,000: " << asString(obj2) << endl;

    return 0;
}
