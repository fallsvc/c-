#include "User.h"
#include <sstream>

User::User() {
	userID = 0;
	name = " ";
	password = " ";
}
User::User(int ID, string name, string password) {
	userID = ID;
	this->name = name;
	this->password = password;
}

void User::setUser(int ID, string name, string password) {
	userID = ID;
	this->name = name;
	this->password = password;
}

int User::getID() {
	return userID;
}
string User::getName() {
	return name;
}
string User::getPassword() {
	return password;
}


//������
void User::doIO(int index,MYSQL*con) {
	if (io[index] != nullptr) {
		io[index]->doWork(con);
	}
	//��ӽ����ID ���û���
	if (index == 3) {

		stringstream ss;
		ss << "UPDATE bookborrow SET userName = '" << name
			<< "', userID = " << userID << " WHERE userID IS NULL";
		string query = ss.str();
		// ִ��sql���
		if (mysql_query(con, query.c_str())) {
			cout << "warning, " << mysql_error(con) << endl;
		}

		cout << "����ɹ�" << endl;
	}
}

//���ܲ˵�
int User::menu() {
	return 0;
}

int NormalUser::menu() {
	cout << "**************************" << endl;
	cout << "*****0.exit 1.���ı� ******" << endl;
	cout << "*****2.��   3.����*********" << endl;
	cout << "*****4.����    ************" << endl;
	cout << "**************************" << endl;
	int n = 0;
	cout << "����ѡ�������" << endl;
	cin >> n;
	return n;
}

int Admin::menu() {
	cout << "***************************" << endl;
	cout << "*****0.exit 1.���ı� *******" << endl;
	cout << "****2.����Ϣ 3.������ ******" << endl;
	cout << "****4.ɾ���� 5.�޸���******" << endl;
	cout << "***************************" << endl;
	int n = 0;
	cout << "����ѡ�������" << endl;
	cin >> n;
	return n;
}

//���ù���

NormalUser::NormalUser():User() {
	io[0] = new Exit();          //���ù���
	io[1] = new BorrowView();
	io[2] = new ShowBooks();
	io[3] = new BorrowBook();
	io[4] = new ReturnBook();
}
NormalUser::NormalUser(int ID, string name, string password):User(ID, name, password) {
	io[0] = new Exit();
	io[1] = new BorrowView();
	io[2] = new ShowBooks();
	io[3] = new BorrowBook();
	io[4] = new ReturnBook();
}

Admin::Admin() :User() {
	io[0] = new Exit();
	io[1] = new BorrowView();
	io[2] = new ShowInformation();
	io[3] = new AddBuyBook();
	io[4] = new DeleteBook();
	io[5] = new AlterBook();
}
Admin::Admin(int ID, string name, string password) :User(ID, name, password) {
	io[0] = new Exit();
	io[1] = new BorrowView();
	io[2] = new ShowInformation();
	io[3] = new AddBuyBook();
	io[4] = new DeleteBook();
	io[5] = new AlterBook();
}