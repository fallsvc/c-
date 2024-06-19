#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class A {
public:
	int age=20;
	void fun() {
		cout << "A "<<endl;
	}
};

class B :virtual public A {
public:
	void fun() {
		cout << "B " << endl;
	}
	int age=10;
};

class C :virtual public A {
public:
	int c;
	void fun() {
		cout << "C " << endl;
	}
};

class D :public B, public C {
public:
	void fun() {
		cout << "D " << endl;
	}
};

int main() {
	D d;
	cout << d.age << endl;
	d.age = 40;

	cout << d.age << endl;
	d.fun();
	d.A::fun();
	d.B::fun();
	d.C::fun();

	return 0;
}