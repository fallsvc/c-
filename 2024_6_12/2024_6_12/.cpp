#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class AbstractDrink {
public:
	//��ˮ
	virtual void boilWater()=0;
	//������
	virtual void putMaterial() = 0;
	//����
	virtual void brew() = 0;
	//����
	void doWork() {
		boilWater();
		putMaterial();
		brew();
	}
};

class Coffee :public AbstractDrink {
public:
	//��ˮ
	virtual void boilWater() {
		cout << "kqs" << endl;
	}
	//������
	virtual void putMaterial() {
		cout << "coffee" << endl;
	}
	//����
	virtual void brew() {
		cout << "brew coffee" << endl;
	}
};

class Tea :public AbstractDrink {
public:
	//��ˮ
	virtual void boilWater() {
		cout << "nfsq " << endl;
	}
	//������
	virtual void putMaterial() {
		cout << "tea" << endl;
	}
	//����
	virtual void brew() {
		cout << "brew tealeaf" << endl;
	}
};

void doWork(AbstractDrink* s) {
	s->doWork();

}

void test1() {
	AbstractDrink* a[] = { new Coffee,new Tea,new Coffee };
	doWork(new Coffee);
	doWork(new Tea);
	for (int i = 0; i < 3; i++)
	{
		a[i]->doWork();
	}
}

#include <fstream>
#include <string>
//
//int main() {
//	//test1();
//
//	//ofstream ofs;
//	//ofs.open("test.txt", ios::out);
//
//	//ofs << " zhansg" << endl;
//	//ofs << " ��" << endl;
//	//ofs << "18" << endl;
//
//	//ofs.close();
//
//
//	ifstream ifs;
//	ifs.open("test.txt", ios::in);
//	if (!ifs.is_open()) {
//		return 1;
//	}
//	//1
//	//char buf[1024] = { 0 };
//	/*while (ifs >> buf) {
//		cout << buf << endl;
//	}*/
//	/*while (ifs.getline(buf, sizeof(buf))) {
//		cout << buf << endl;
//
//	}*/
//	string buf;
//	while (getline(ifs, buf)) {
//		cout << buf << endl;
//	}
//
//
//	ifs.close();
//
//	return 0;
//}



//template<typename T>
template<class T>
void myswap(T& x, T& y) {
	T tmp = x;
	x = y;
	y = tmp;
}

int main() {
	int a = 10;
	int b = 20;
	double c = 10.00;
	double d = 20.0;
	
	myswap<double>(c, d);
	myswap(c, d);

	cout << c << endl;
	cout << d << endl;
	return 0;
}