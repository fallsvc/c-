#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char* myStrchr(char* a, char b) {
	while (*a) {
		if (*a == b) {
			return a;
		}
		a++;
	}
	return NULL;
}

int main()
{
	char arr[] = "abcfdgh";
	char b = 'c';
	char* p = myStrchr(arr, b);
	if (p){
		cout << "zhaodao:" << *p << endl;
	}
	else {
		cout << "my" << endl;
	}

	return 0;
}