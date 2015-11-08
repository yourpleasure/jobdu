#include <stdio.h>
#include <stdlib.h>
typedef struct date{
	unsigned int year;
	unsigned int month;
	unsigned int day;
}date;
static void longtodate(unsigned long a, struct date *datep);
static unsigned int isleap(unsigned int year);
static unsigned int dayofyear(struct date s);
static unsigned long diff(struct date first, struct date second);
unsigned int monthday[] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30
};
unsigned int yearday[] = {
	365, 366
};
int main()
{
	unsigned long a;
	unsigned long b;
	date first;
	date second;
	while(scanf("%lu%lu", &a, &b) != EOF){
		if(a < b){
			a ^= b;
			b ^= a;
			a ^= b;
		}
		longtodate(a, &first);
		longtodate(b, &second);
		printf("%lu\n", diff(first, second));
	}
	exit(0);
}

static void longtodate(unsigned long a, date *datep)
{
	datep->year = a / 10000;
	a %= 10000;
	datep->month = a / 100;
	datep->day = a % 100;
}

static unsigned int isleap(unsigned int year){
	return ((!(year % 4)) && (year % 100)) || (!(year % 400));
}

static unsigned int dayofyear(date s)
{
	unsigned int leap;
	unsigned int month = s.month;
	unsigned int day = s.day;
	unsigned int days = 0;
	unsigned int i;
	leap = isleap(s.year);
	for(i = 1; i < month; i++) days += monthday[i-1];
	if(month > 2) days += leap;
	days += day;
	return days;
}

static unsigned long diff(date first, date second)
{
	unsigned long day1, day2;
	unsigned int year;
	unsigned long days = 0;
	day1 = dayofyear(first);
	day2 = dayofyear(second);
	for(year = second.year; year < first.year; year++){
		days += yearday[isleap(year)];
	}
	days = days + day1 - day2 + 1;
	if(first.year < second.year)
		days += yearday[isleap(first.year)];
	return days;
}

