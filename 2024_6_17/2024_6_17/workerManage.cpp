#include "workerManage.h"

workerManage::workerManage() {

}
workerManage::~workerManage() {

}

//菜单
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

//退出
void workerManage::exitP() {
	cout << "退出程序 " << endl;

	exit(0);
}