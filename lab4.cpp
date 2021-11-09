#include <iostream>
#include <string>
using namespace std;
class date {
	int day, month, year;
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	date(int Day, int Month, int Year) {
		day = Day;
		month = Month;
		year = Year;
	}
	
	friend std::ostream& operator<< (std::ostream& out, const date& obj);
	
	friend date operator+(const date& obj, const date& obj2);
	friend date operator+(int value, const date& obj);
	friend date operator-(const date& obj1, const date& obj2);
	friend date operator-(const date& obj, int value);
	date operator+(int value);

	date& operator++() {
		day += 1;
		if (day > days[month]) {
			day - days[month];
			month -= 1;
			if (month > 12) {
				month -= 12;
				year += 1;
			}
		}
		return *this;
	}
	
	date operator++(int) {
		date prev = *this;
		++* this;
		return prev;
	}
	
	date& operator--() {
		day -= 1;
		if (day <= 0) {
			day + days[month];
			month -= 1;
			if (month <= 0) {
				month += 12;
				year -= 1;
			}
		}
		return *this;
	}
	
	date operator--(int) {
		date prev = *this;
		--* this;
		return prev;
	}
	
	
};

std::ostream& operator<< (std::ostream& out, const date& obj) {
	
	out << obj.day << "." << obj.month << "." << obj.year << endl;
	return out;
}
date operator+(int value, const date& obj) {
	int day1 = obj.day + value;
	int month1 = obj.month;
	int year1 = obj.year;
	if (day1 > obj.days[obj.month]) {
		day1 -= obj.days[obj.month];
		month1 = obj.month + 1;
		if (month1 > 12) {
			year1 = obj.year + 1;
			month1 = month1 - 12;
		}
	}
	return date(day1, month1, year1);
}
date date::operator+(int value)
{
	int day1 = day + value;
	int month1 = month;
	int year1 = year;
	if (day1 > days[month]) {
		day1 -= days[month];
		month1 = month + 1;
		if (month1 > 12) {
			year1 = year + 1;
			month1 = month1 - 12;
		}
	}
	return date(day1, month1, year1);
};
date operator+(const date& obj, const date& obj2) {
	int day1 = obj.day + obj2.day;
	int month1 = obj.month+ obj2.month;
	int year1 = obj.year+ obj2.year;
	if (day1 > obj.days[obj.month]) {
		day1 -= obj.days[obj.month];
		month1 = obj.month + 1;
		if (month1 > 12) {
			year1 = obj.year + 1;
			month1 = month1 - 12;
		}
	}
	return date(day1, month1, year1);
};
date operator-(const date& obj1, const date& obj2) {
	int month1 = obj1.month- obj2.month;
	int year1 = obj1.year- obj2.year;
	int day1 = obj1.day - obj2.day;
	if (day1 <= 0) {
		month1--;
		day1 = obj1.day + day1;
		if (month1 <= 0) {
			year1--;
			month1 += 12;
		}
	}
	return date(day1, month1, year1);
}
date operator-(const date& obj, int value) {
	int month1 = obj.month;
	int year1 = obj.year;
	int day1 = obj.day - value;
	if (day1 <= 0) {
		month1--;
		day1 = obj.day + day1;
		if (month1 <= 0) {
			year1--;
			month1 += 12;
		}
	}
	return date(day1, month1, year1);
};


void main() {
	date data(26, 3, 2001);
	cout << "date + int (5)" << endl;
	cout << data;
	data = data + 5;
	cout << data;
	
	cout << "int (2) + date" << endl;
	data = 2 + data;
	cout << data;

	date data2(1, 1, 3);
	cout << "date + date (1,1,3)" << endl;
	data =data + data2;
	cout <<data;

	cout << "date - date (1,1,3)" << endl;
	data = data - data2;
	cout << data;
	cout << "date ++" << endl;
	data++;
	cout << data;

	cout << "date --" << endl;
	data--;
	cout << data;}
