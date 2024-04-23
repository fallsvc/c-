
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	/*int a=0;
//	string b = "abcdfg";
//	cout << a << "\n" << b << endl;
//
//	cin >> a;
//	cin >> b;
//	cout << a << "\n" << b << endl;*/
//
//
//	system("pause");
//	return 0;
//}

//vs 2022
//项目属性使用多字节字符集

#include <iostream>
#include <graphics.h>
#include <ctime>
using namespace std;

//生成n个随机1-8 
void setNumberBoard(int* arr, int r, int c, int n)
{
	static unsigned s = time(0);
	srand(s);
	s = rand();
	initgraph(r * 40, c * 40, 0);
	setbkcolor(LIGHTBLUE);
	cleardevice();

	setlinecolor(BLACK);
	//行线
	for (int i = 0; i <= r * 40; i += 40)
	{
		line(0, i, c * 40, i);
	}
	//列线
	for (int i = 0; i <= c * 40; i += 40)
	{
		line(i, 0, i, r * 40);
	}
	//数字大小
	settextstyle(30, 30, "微软雅黑");
	settextcolor(BLACK);

	while (n)
	{
		int i = rand() % r;
		int j = rand() % c;
		if (*(arr + c * i + j) == 0)
		{
			*(arr + c * i + j) = (rand() % 8 + 1);
			char a = *(arr + c * i + j) + 48;
			outtextxy(5 + 40 * i, 5 + 40 * j, a);
			n--;
		}
	}
	system("pause");
	closegraph();
}

int main()
{
	int n = 10;
	int arr[10][10] = { 0 };
	/*cout<<"输入要添加的随机数数:";
	cin >> n;*/

	setNumberBoard(*arr, 10, 10, n);

	system("pause");
	return 0;
}