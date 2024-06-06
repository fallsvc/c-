#define _CRT_SECURE_NO_WARNINGS

#include "BookSystem.h"

#include <iostream>
#include <sstream>
#include <mysql.h>

using namespace std;

const char* host = "127.0.0.1";//主机，本地的“127.0.0.1” 。
const char* user = "root";//mysql 用户名。
const char* password = "Mysql66@";//对应用户的密码。
const char* database_name = "testdb";//需要连接的数据库的库名。
const int port = 3306;//mysql 的端口号，默认都是3306。
 
int menu() {
	cout << "****************" << endl;
	cout << "****0.退出******" << endl;
	cout << "****1.登录******" << endl;
	cout << "****************" << endl;
	cout << "****************" << endl;
	int n = 0;
	cin >> n;
	return n;
}

User* login(MYSQL* con) {
	string name;
	string password;
	cout << "请输入账号名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> password;
	//查询语句
	stringstream ss;
	ss << "SELECT * FROM users WHERE userName='" << name << "' AND userPassWord='" << password << "'";
	string query = ss.str();

	// 执行sql语句
	if (mysql_query(con, query.c_str())) {
		cout << "warning, " << mysql_error(con) << endl;
		return new User(); // ID 为0登录失败
	}

	// 获取sql语句的执行结果
	MYSQL_RES* res = mysql_store_result(con);
	if (res == nullptr) {
		cout << "warning, " << mysql_error(con) << endl;
	
		return new User(); // ID 为0登录失败
	}

	//判断成功登录
	MYSQL_ROW row = mysql_fetch_row(res);
	if (row) {
		int id = stoi(row[0]);
		string name = row[1];
		string password = row[2];
		mysql_free_result(res);

		if (id == 1) {
			return new Admin(id, name, password); // 返回Admin对象
		}
		else {
			return new NormalUser(id, name, password); // 返回NormalUser对象
		}
	}

	mysql_free_result(res); // 释放结果集资源
	return new User(); // ID 为0登录失败
}

int main(void) {

	
	//获取数据库连接句柄
	MYSQL* con = mysql_init(NULL);
	//设置连接选项
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");
	//设置GBK编码,以防乱码
	mysql_set_character_set(con, "gbk");
	//连接到数据库
	if (!mysql_real_connect(con, host, user, password, database_name, port, NULL, 0)) {
		perror("warming");
		return -1;
	}

	////登录 
	User* s;
	while (true)
	{
		if (menu() == 1)
		{
			s = login(con);
			if (s->getID() == 0) {
				cout << "登录失败，账号或密码错误   " << endl;
				continue;       //登录失败后重新开始
			}
			cout << "登录成功" << endl;
			break;
		}
		else {
			exit(0);
		}
	}
	//执行操作
	while (true) {
		int ret=s->menu();
		s->doIO(ret, con);
	}

	mysql_close(con);		//释放mysql连接资源
	return 0;
}
