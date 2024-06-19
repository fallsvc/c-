#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;


class A {
private :
	int a=1;
	int b=1;
protected:
	int c=1;
	static const int d=1;
public:
	void fun() {
		cout << "aa" << endl;
	};
};

class B :public A {
public:
	int E=1;

};

int main1() {
	string name = "hhhhhhhhhhh";
	name += "eeee";
	B b;
	A a = b;
	//B c = (B)a;//error
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	cout << name << endl;
	return 0;
}


class Animal {
public:
	int a;
	int b;

	virtual void fun()=0;
};

class Cat :public Animal {

public:
	void fun() {

	}
};

class Icalculator {
public:
	int a;
	int b;
	virtual int calOperator() = 0;
};

class AddCalculator:public Icalculator {
public:
	int calOperator() {
		return a + b;
	}
};
class SubCalculator :public Icalculator {
public:
	int calOperator() {
		return a - b;
	}
};

int main() {
	Icalculator* s=new AddCalculator;
	s->a = 10;
	s->b = 20;
	cout<<s->calOperator()<<endl;

	delete s;
	s = new SubCalculator;
	s->a = 10;
	s->b = 20;
	cout << s->calOperator() << endl;
	return 0;
}