#ifndef CLOCK_UTILS_H
#define CLOCK_UTILS_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

const int
SECONDS_PER_MINUTE = 60,
MINUTES_PER_HOUR = 60,
HOURS_PER_DAY = 24;

class Duration
{
	friend Duration &operator +(const Duration &obj1,const Duration &obj2);
	friend Duration &operator -(const Duration &obj1,const Duration &obj2);
	friend ostream &operator <<(ostream &os,const Duration &obj);
	public:
	int days;
    int hours;
    int minutes;
    int seconds;
    int ticks;
    clock_t clockVal;
		
	Duration(int days,int hours, int minutes,int seconds,int ticks):days(days),hours(hours),minutes(minutes),seconds(seconds),ticks(ticks) {}
	
	Duration(clock_t totalTicks){
    ticks = totalTicks % CLOCKS_PER_SEC;

    seconds = totalTicks / CLOCKS_PER_SEC % SECONDS_PER_MINUTE;

    minutes = totalTicks / CLOCKS_PER_SEC / SECONDS_PER_MINUTE % MINUTES_PER_HOUR;

    hours = totalTicks / CLOCKS_PER_SEC / SECONDS_PER_MINUTE / MINUTES_PER_HOUR;
	
	days = totalTicks / CLOCKS_PER_SEC / SECONDS_PER_MINUTE / MINUTES_PER_HOUR / HOURS_PER_DAY;}

	Duration(string time){
	string temp;
	stringstream ss(time);
    getline(ss,temp,':');
    stringstream(temp) >> days;
    getline(ss,temp,':');
    stringstream(temp) >> hours;
	getline(ss,temp,':');
    stringstream(temp) >> minutes;
    getline(ss,temp,':');
    stringstream(temp) >> seconds;
    getline(ss,temp);
    stringstream(temp) >> ticks;}
    
	Duration():clockVal(clock()){}
	
	Duration &operator +=(const Duration &other);
	Duration &operator -=(const Duration &other);
};
string asString(Duration);

#endif
