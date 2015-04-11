#ifndef CLOCK_UTILS_H
#define CLOCK_UTILS_H

#include <ctime>
#include <string>

using namespace std;

const int
SECONDS_PER_MINUTE = 60,
MINUTES_PER_HOUR = 60;
HOURS_PER_DAY = 24;

struct Duration
{
	friend Duration &operator +(const Duration &obj1,const Duration &obj2);
	friend Duration &operator -(const Duration &obj1,const Duration &obj2);
	friend ostream &operator <<(ostream &os,const Duration &obj);
	friend istream &operator >>(istream &in,const Duration &obj);
	
	
	int days;
    int hours;
    int minutes;
    int seconds;
    int ticks;
	string time;
	
	Duration(int days=0,int hours=0, int minutes=0,int seconds=0,int ticks=0): 
	days(days),hours(hours),minutes(minutes),seconds(seconds),ticks(ticks) {}
	
	Duration(): ticks(totalTicks){
	Duration obj;
    ticks = totalTicks % CLOCKS_PER_SEC;

    seconds = totalTicks / CLOCKS_PER_SEC % SECONDS_PER_MINUTE;

    minutes = totalTicks / CLOCKS_PER_SEC / SECONDS_PER_MINUTE % MINUTES_PER_HOUR;

    hours = totalTicks / CLOCKS_PER_SEC / SECONDS_PER_MINUTE / MINUTES_PER_HOUR;
	
	days = totalTicks / CLOCKS_PER_SEC / SECONDS_PER_MINUTE / MINUTES_PER_HOUR / HOURS_PER_DAY;}




	Duration(string time): time(time){
    stringstream ss;
    ss << days << hours << ":" << minutes << ":" << seconds << ":" << ticks;
    ss >> time;
	}
	
	
	Duration &operator +=(const Duration &other);
	Duration &operator -=(const Duration &other);
    Duration buildDuration(clock_t);
};
string asString(Duration);

#endif
