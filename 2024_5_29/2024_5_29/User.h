#pragma once
#include <iostream>
#include "Ioperation.h"
using namespace std;

class User
{
protected:
	int userID;
	string name;
	string password;
	Ioperation* io[10];//功能接口

public:
	
	User();
	User(int ID, string name, string password);
	//释放资源
	~User() {
		int i = 0;
		while (io[i] != nullptr) {
			delete io[i];
			i++;
		}
	}

	void setUser(int ID, string name, string password);
	int getID();
	string getName();
	string getPassword();

	//运行功能
	void doIO(int index,MYSQL*con);

	virtual int menu();//功能菜单
	  
};

class NormalUser:public User {
public:
	NormalUser();
	NormalUser(int ID, string name, string password);
	int menu();
};

class Admin :public User {
public:
	Admin();
	Admin(int ID, string name, string password);
	int menu();

};