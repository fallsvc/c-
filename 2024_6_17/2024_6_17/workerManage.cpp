#include "workerManage.h"

workerManage::workerManage() {

}
workerManage::~workerManage() {

}

//�˵�
int workerManage::showMenu() {
	cout << "************************" << endl;
	cout << "****** 0.exit  *********" << endl;
	cout << "****** 1.add   *********" << endl;
	cout << "****** 2.show  *********" << endl;
	cout << "****** 3.del   *********" << endl;
	cout << "****** 4.modify**********" << endl;
	cout << "****** 5.find  *********" << endl;
	cout << "****** 6.sort   ********" << endl;
	cout << "****** 7.destroy*********" << endl;
	cout << "************************" << endl;
	int n = 0;
	cin >> n;
	return n;
}

//�˳�
void workerManage::exitP() {
	cout << "�˳����� " << endl;

	exit(0);
}