#include <ctime>
#include <string>

#include "duration.h"

using namespace std;


Duration &operator +(const Duration &obj1,const Duration &obj2){
	Duration result = obj1;
	return result += obj2;
}

Duration &operator -(const Duration &obj1,const Duration &obj2){
	Duration result = obj1;
	return result -= obj2;
}
	
ostream &operator <<(ostream &os,const Duration &obj){
	os << obj.days << ":" << obj.hours << ":" << obj.minutes << ":" << obj.seconds << ":" << obj.ticks;
	return os;
}


Duration &Duration::operator +=(const Duration &other){
	days += other.days;
	hours += other.hours;
	minutes += other.minutes;
	seconds += other.seconds;
	ticks += other.ticks;
	return *this;
}

Duration &Duration::operator -=(const Duration &other){
	days -= other.days;
	hours -= other.hours;
	minutes -= other.minutes;
	seconds -= other.seconds;
	ticks -= other.ticks;
	return *this;
}

string asString(Duration obj)
{
    string time;
    stringstream ss;
    ss << obj.days << ":" << obj.hours << ":" << obj.minutes << ":" << obj.seconds << ":" << obj.ticks;
    ss >> time;
    return time;
}
