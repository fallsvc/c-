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

/////��Ա��������Ԫ����Ա��������д�����ⶨ�壬�����ڶ���ᱨ��
//class country;//��������ࣨ��ΪUSAʹ���������ʱ����δ�������������
//class USA
//{
//public:
//	USA();//Ĭ�Ϲ��캯��
//	void visit(); //ֻ��visit������Ϊcountry�ĺ����ѣ����Է�����country��˽������(private)
//	void visit2();
//private:
//	country* china;//����һ��ָ�������ĵ�ָ��
//};
//class country
//{
//	//���߱�����  usA���е�visit��Ա���� ��country�����ѣ����Է���˽������
//	friend void USA::visit();//��������������ĳ�Ա���������Խ�����Ԫ
//	//friend void visit()��ȫԱ����
//public:
//	country();
//public:
//	string m_SittingRoom; //��������
//private:
//	string m_BedRoom;//˽������
//};
//
//country::country()
//{
//	this->m_SittingRoom = "�п�Ժ";
//	this->m_BedRoom = "�˻���";
//}
//USA::USA()
//{
//	china = new country;//�ڶ�������һ������
//}
//void USA::visit()
//{
//	cout << "�������ڷ���" << china->m_SittingRoom << endl;
//	cout << "�������ڷ���" << china->m_BedRoom << endl;
//}
//void USA::visit2()//���û��������Ԫ���������ԾͲ��ܷ���˽������
//{
//	cout << "�������ڷ���" << china->m_SittingRoom << endl;
//}
//void test01()
//{
//	USA  gg;//����һ������
//	cout << "==============" << endl;
//	gg.visit();//��������������
//	cout << "================" << endl;
//	gg.visit2();
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}