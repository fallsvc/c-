//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//#include <string>
//
//class Student {
//protected:
//	int b=10;
//public :
//
//	string name;
//	int* a;
//
//	Student& operator=(Student& s){
//
//		this->name = s.name;
//		if (a != NULL) {
//			delete a;
//			a = NULL;
//		}
//		a = new int(*s.a);
//
//		return *this;
//	}
//	bool operator==(Student& s) {
//		if (*a == *s.a && name == s.name) {
//			return true;
//		}
//		return false;
//	}
//	bool operator!=(Student& s) {
//		if (*a == *s.a && name == s.name) {
//			return false;
//		}
//		return true;
//	}
//
//	int operator()(int x, int y) {
//		return x + y;
//	}
//
//};
//
//int main() {
//	Student student1;
//	
//	cout << Student()(10, 10) << endl;
//	//Student student2;
//	//Student student3;
//	//student1.name = "zs";
//	//student1.a = new int(10);
//	////cout << *student1.a << endl;
//
//	//Student b = student1;
//	//student2 =student3= student1;
//	//*student2.a = 20;
//	//if (student2 != student1) {
//	//	cout << "xd" << endl;
//	//}
//	/*cout << *student1.a << endl;
//	cout << *student2.a << endl;
//	*b.a = 20;
//	cout << *student1.a << endl;
//	cout << *b.a << endl;*/
//	return 0;
//}