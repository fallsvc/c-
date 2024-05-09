#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class T1;
class T2 {
public:
	T2();
	void addT2(int x) {
		c += x;
	}
	void test11();
	
private:
	T1* t1;
	int c;
};
class T1 {
	friend void T2::test11();/*friend class T2;*/
public:
	T1() {
		a = 0;
		b = 0;
	}
	void addT1(int x) {
		a += x;
	}
private:
	int a;
	int b;

};

void T2::test11() {
	cout << t1->a << endl;
}
T2::T2() {
	c = 0;
	t1 = new T1;
}
void test1() {
	T2 t2;
	t2.test11();
}
int main() {
	test1();
	return 0;
}

/////成员函数做友元，成员函数必须写在类外定义，在类内定义会报错。
//class country;//声明这个类（因为USA使用这个函数时，还未定义这个函数）
//class USA
//{
//public:
//	USA();//默认构造函数
//	void visit(); //只让visit函数作为country的好朋友，可以发访问country中私有内容(private)
//	void visit2();
//private:
//	country* china;//创建一个指向类对象的的指针
//};
//class country
//{
//	//告诉编译器  usA类中的visit成员函数 是country好朋友，可以访问私有内容
//	friend void USA::visit();//这个是类对象里面的成员函数，可以进行友元
//	//friend void visit()是全员函数
//public:
//	country();
//public:
//	string m_SittingRoom; //公有属性
//private:
//	string m_BedRoom;//私有属性
//};
//
//country::country()
//{
//	this->m_SittingRoom = "中科院";
//	this->m_BedRoom = "核基地";
//}
//USA::USA()
//{
//	china = new country;//在堆区创建一个对象
//}
//void USA::visit()
//{
//	cout << "美国正在访问" << china->m_SittingRoom << endl;
//	cout << "美国正在访问" << china->m_BedRoom << endl;
//}
//void USA::visit2()//这个没有声明友元函数，所以就不能访问私有属性
//{
//	cout << "美国正在访问" << china->m_SittingRoom << endl;
//}
//void test01()
//{
//	USA  gg;//创建一个对象
//	cout << "==============" << endl;
//	gg.visit();//对象访问这个函数
//	cout << "================" << endl;
//	gg.visit2();
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}