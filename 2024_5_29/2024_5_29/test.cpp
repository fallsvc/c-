#define _CRT_SECURE_NO_WARNINGS

#include "BookSystem.h"

#include <iostream>
#include <sstream>
#include <mysql.h>

using namespace std;

const char* host = "127.0.0.1";//���������صġ�127.0.0.1�� ��
const char* user = "root";//mysql �û�����
const char* password = "Mysql66@";//��Ӧ�û������롣
const char* database_name = "testdb";//��Ҫ���ӵ����ݿ�Ŀ�����
const int port = 3306;//mysql �Ķ˿ںţ�Ĭ�϶���3306��
 
int menu() {
	cout << "****************" << endl;
	cout << "****0.�˳�******" << endl;
	cout << "****1.��¼******" << endl;
	cout << "****************" << endl;
	cout << "****************" << endl;
	int n = 0;
	cin >> n;
	return n;
}

User* login(MYSQL* con) {
	string name;
	string password;
	cout << "�������˺���:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> password;
	//��ѯ���
	stringstream ss;
	ss << "SELECT * FROM users WHERE userName='" << name << "' AND userPassWord='" << password << "'";
	string query = ss.str();

	// ִ��sql���
	if (mysql_query(con, query.c_str())) {
		cout << "warning, " << mysql_error(con) << endl;
		return new User(); // ID Ϊ0��¼ʧ��
	}

	// ��ȡsql����ִ�н��
	MYSQL_RES* res = mysql_store_result(con);
	if (res == nullptr) {
		cout << "warning, " << mysql_error(con) << endl;
	
		return new User(); // ID Ϊ0��¼ʧ��
	}

	//�жϳɹ���¼
	MYSQL_ROW row = mysql_fetch_row(res);
	if (row) {
		int id = stoi(row[0]);
		string name = row[1];
		string password = row[2];
		mysql_free_result(res);

		if (id == 1) {
			return new Admin(id, name, password); // ����Admin����
		}
		else {
			return new NormalUser(id, name, password); // ����NormalUser����
		}
	}

	mysql_free_result(res); // �ͷŽ������Դ
	return new User(); // ID Ϊ0��¼ʧ��
}

int main(void) {

	
	//��ȡ���ݿ����Ӿ��
	MYSQL* con = mysql_init(NULL);
	//��������ѡ��
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");
	//����GBK����,�Է�����
	mysql_set_character_set(con, "gbk");
	//���ӵ����ݿ�
	if (!mysql_real_connect(con, host, user, password, database_name, port, NULL, 0)) {
		perror("warming");
		return -1;
	}

	////��¼ 
	User* s;
	while (true)
	{
		if (menu() == 1)
		{
			s = login(con);
			if (s->getID() == 0) {
				cout << "��¼ʧ�ܣ��˺Ż��������   " << endl;
				continue;       //��¼ʧ�ܺ����¿�ʼ
			}
			cout << "��¼�ɹ�" << endl;
			break;
		}
		else {
			exit(0);
		}
	}
	//ִ�в���
	while (true) {
		int ret=s->menu();
		s->doIO(ret, con);
	}

	mysql_close(con);		//�ͷ�mysql������Դ
	return 0;
}
