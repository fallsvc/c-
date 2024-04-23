#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//int* fin(int n)
//{
//	int* ret = new int(n);
//	return ret;
//}
//
//int main()
//{
//	int* p = fin(10);
//	cout << *p << endl;
//	cin >> *p;
//	cout << *p << endl;
//	delete p;
//
//	return 0;
//}

int p = 2;

int main()
{
	::p;
	int p = 3;
	cout << p << endl;
	cout << ::p << endl;
	return 0;
}