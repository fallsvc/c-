#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//class ZouBiao {
//public:
//	ZouBiao() :m_x(0), m_y(0) {
//		cout<<"zb wuchan\n"<<endl;
//	}
//	void setX(int x) {
//		this->m_x = x;//m_x=x;
//	}
//	void setY(int y) {
//		this->m_y = y;
//	}
//
//private:
//	int m_x;
//	int m_y;
//};
//class Circle {
//public:
//	Circle() {
//		m_r = 0.0;
//		cout << "Circle wuchan" << endl;
//	}
//	void setR(double x) {
//		m_r = x;
//	}
//	ZouBiao zb;
//private:
//	double m_r;
//};
//
//int main()
//{
//	Circle a,*b=&a;
//	a.setR(3.3);
//	a.zb.setX(2);
//	a.zb.setY(3);
//
//	return 0;
//}
//
//class Ts {
//public:
//	Ts() {
//		b=10;
//	}
//	Ts& add(const Ts& a) {
//		this->b += a.b;
//		return *this;
//	}
//private:
//	int b;
//};
//
//int main() {
//	Ts ts;
//	Ts a;
//	ts.add(a).add(a).add(a).add(a);
//	return 0;
//}

//class Test {
//public:
//	void print()const {
//		cout << "diaoyong" << endl;
//	}
//
//};
//
//int main() {
//	const Test t;//常对象只能调用常含数
//	Test const t1;
//	t.print();
//	t1.print();
//	Test t2;
//	t2.print();
//	return 0;
//}

class T1 {
	friend class T2;
public:
	void add();
	void print1() {
		cout << "T1 print" << endl;
	};

private:
	int m_A;
	int m_B;
	
};

void T1::add() {
	m_A += m_B;
}

class T2 {
	
public:
	void show();
	void del();
private:
	int m_H;
	T1* t;
};
void T2::show() {
	cout << t->m_A << endl;
}

void T2::del() {

}

int main() {
	T1 t1;
	T2 t2;
	return 0;
}