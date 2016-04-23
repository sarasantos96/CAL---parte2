#ifndef SRC_DATE_H_
#define SRC_DATE_H_

#include <iostream>

class Date{
private:
	int hour;
	int minutes;
public:
	Date();
	Date(int hour, int minutes);
	int getDay() const;
	void setDay(int day);
	int getHour() const;
	void setHour(int hour);
	int getMinutes() const;
	void setMinutes(int minutes);
	int getMonth() const ;
	void setMonth(int month);
	int getYear() const;
	void setYear(int year);
	friend bool operator ==(const Date &d1, const Date &d2){
		if((d1.getDay() == d2.getDay()) && (d1.getMonth() == d2.getMonth()) && (d1.getHour() == d2.getHour()) && (d1.getMinutes() == d2.getMinutes()))
			return true;
		return false;
	}
	friend bool operator <(const Date &d1, const Date &d2){
		if(d1.getHour() > d2.getHour()) return false;
		if(d1.getMinutes() > d2.getMinutes()) return false;
		return true;
	}
};




#endif
