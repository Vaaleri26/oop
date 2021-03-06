#include <iostream>
#include <string>
using namespace std;
class BASE {

private:

	double d;

 protected:

	long l;

	void ff() {
		cout << "ff BASE" << endl;
	};

public:
	int i;

	BASE(int _i, double _d, long _l) {
		i = _i;
		d = _d;
		l = _l;
		cout << "конуструктор BASE" << endl;
	}


	~BASE() {
		cout << "деструктор BASE" << endl;
	}


	int* getAdri() {
		return &i;
	}
	double* getAdrd() {
		return &d;
	}
	long* getAdrl() {
		return &l;
	}


	void setd(double value) {
		d = value;
	}
	double getd() {
		return d;
	}


};

class DERIVED : public BASE {
private:

	float f;

public:

	DERIVED() = default;
	DERIVED(int _i, double _d, long _l, float _f) : BASE(_i, _d, _l) {
		f = _f;
		cout << "конструктор DERIVED" << endl;
	}

	~DERIVED() {
		cout << "деструктор DERIVED" << endl;
	}

		float* getAdrf() {
		return &f;
	}
protected:
	void ff() {
		cout << "ff DERIVED" << endl;
	};
};

class DERIVED_l : public DERIVED {
public:
	DERIVED_l() = default;
	DERIVED_l(int _i, double _d, long _l, float _f) : DERIVED(_i, _d, _l, _f) {};


	void foo() {
		i++;
		l += l;
		ff();
	}

};

ostream& operator << (ostream& out, DERIVED& obj) {//перегрузка операции вставки
	out << "i - " << obj.getAdri() << endl;
	out << "d - " << obj.getAdrd() << endl;
	out << "l - " << obj.getAdrl() << endl;
	out << "f - " << obj.getAdrf() << endl;

	return out;
};

ostream& operator << (ostream& out, DERIVED_l& obj) {
	out << "i - " << obj.getAdri() << endl;
	out << "d - " << obj.getAdrd() << endl;
	out << "l - " << obj.getAdrl() << endl;
	out << "f - " << obj.getAdrf() << endl;

	return out;
};

void ff() {
	cout << "ff global" << endl;
};

void main() {
	setlocale(LC_ALL, "Russian");

	DERIVED ob(14, 7, 10, 1);
	cout << ob;

	DERIVED_l ob1(26, 3, 20, 1);
	cout << ob1;

	ob1.foo();

}
