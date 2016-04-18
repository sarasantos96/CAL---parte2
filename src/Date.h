#ifndef SRC_DATE_H_
#define SRC_DATE_H_

class Date{
private:
	int day;
	int month;
	int year;
	int hour;
	int minutes;
public:
	Date(int day, int month, int year, int hour, int minutes);
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
};




#endif
