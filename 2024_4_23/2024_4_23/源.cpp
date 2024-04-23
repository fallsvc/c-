
#include <iostream>
#include <string>
using namespace std;

int& Fin(int& a)
{
	a = 20;
	return a;
}
int add(int x = 10, int y = 20)
{
	return x + y;
}

int main()
{
	int a = 10;
	int& b = a;
	int& c = Fin(a);

	cout << a << endl;
	cout << b << endl;	
	cout << c << endl;
	a = add();
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	system("pause");
	return 0;
}

