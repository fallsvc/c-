#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//int& alter(int& a)
//{
//	a = 20;
//	return a;
//}
//
//int main()
//{
//	int a = 10;
//	int& b = a;
//	int&c=alter(a);
//	cout << a<<" " << b <<" " << c << " " << endl;
//	return 0;
//}

//class Person {
//public:
//	Person() : age(20){
//
//	}
//	Person(int x, int y) {
//		age = x;
//		high = new int(y);
//	}
//	Person(const Person &p){
//		age = p.age;
//		high = new int(*p.high);//深拷贝
//		//high = p.high;//浅拷贝会导致内存多次释放
//	};
//	int age;
//	int* high;
//	~Person() {
//		if (high != NULL) {
//			delete high;
//			high = NULL;
//		}
//	}
//};
//
//int main()
//{
//	//Person p1(20, 170);
//	//Person p2(p1);
//	//Person p3;
//	//cout << *p1.high << endl;
//	//cout << *p2.high << endl;
//	//cout << p3.age << endl;
//	string a = "adns";
//	string b = a;
//	cout << b << endl;
//	return 0;
//}

//class Phone {
//public:
//	Phone(string a) :pname(a) {
//		cout << "phone" << endl;
//	}
//	string pname;
//	~Phone() {
//		cout << "phone析构" << endl;
//	}
//};
//class Person {
//public:
//	Person(string x, string y) :name(x), pname(y) {
//		cout << "person" << endl;
//	}
//	string name;
//	Phone pname;
//};
//
//int main()
//{
//	Person p1("zs", "xiaomi");
//	cout << p1.name << endl;
//	cout << p1.pname.pname << endl;
//	return 0;
//}

class Test {
public:
	Test(int x) :age(x) {

	}
	static void fng() {
		a = 200;
	}
	static int a;

	Test& add(int age){
		this->age += age;
		return *this;
	}

	int age;
};

int Test::a = 100;

int main()
{
	//Test p1;
	/*cout << p1.a << endl;
	cout << Test::a << endl; 
	p1.fng();
	cout << p1.a << endl;
	cout << Test::a << endl;*/
	
	Test p1(10);
	Test p2(10);
	p2.add(p1.age).add(p1.age).add(p1.age);
	cout << p2.age << endl;
	return 0;
}