#include <iostream>
#include <string>

#include "duration.h"

using namespace std;

int main()
{
	cout << "Clock ticks per second: " << CLOCKS_PER_SEC << endl;

    Duration obj,obj2,obj3;
    clock_t start_time = clock();
    for (int i = 0; i < 1000000; i++)
        i / 17;
    clock_t end_time = clock();

    clock_t duration = end_time - start_time;
    obj = Duration(duration);

    cout << "Single loop 0 to 1,000,000: " << obj << endl;

	string time = asString(obj);
	obj = Duration(time);
	cout << "obj string: "<< time << endl;
	
    start_time = clock();
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000000; j++)
            i / 17;
    end_time = clock();

    duration = end_time - start_time;
    obj2 = Duration(duration);
    cout << "Single loop 0 to 1,000,000: " << obj2 << endl;
        
	time = asString(obj2);
    obj2 = Duration(time);
	cout << "obj2 string: "<< time << endl;
	
    obj += obj2;
	cout << "obj after +=: " << obj << endl;
    obj -= obj2;
	cout << "obj after -=: " << obj << endl;
									 
	obj3 = obj + obj2;
	cout << "obj3 after +: " << obj3 << endl;
	obj3 = obj - obj2;
	cout << "obj3 after -: " << obj3 << endl;
	return 0;	                     
}                               
