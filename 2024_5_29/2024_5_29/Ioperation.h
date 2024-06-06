#pragma once
#include <mysql.h>
//接口类
class Ioperation
{
public:
	virtual void doWork(MYSQL* con) = 0;
};

//借书表
class BorrowView:public Ioperation {
public:
	void doWork(MYSQL* con);
};
//退出
class Exit:public Ioperation
{
public:
	void doWork(MYSQL* con);
};
//用户展示书
class ShowBooks:public Ioperation{
public:
	void doWork(MYSQL* con);
};

//用户借书
class BorrowBook:public Ioperation{
public:
	void doWork(MYSQL* con);
};
//用户还书
class ReturnBook:public Ioperation {
public:
	void doWork(MYSQL* con);
};

//管理员

//书籍信息
class ShowInformation :public Ioperation {
public:
	void doWork(MYSQL* con);
};
//增加图书
class AddBuyBook :public Ioperation {
public:
	void doWork(MYSQL* con);

};

//删除图书
class DeleteBook:public Ioperation {
public:
	void doWork(MYSQL* con);
};

//修改书籍
class AlterBook:public Ioperation {
public:
	void doWork(MYSQL* con);
};