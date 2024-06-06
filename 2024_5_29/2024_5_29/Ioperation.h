#pragma once
#include <mysql.h>
//�ӿ���
class Ioperation
{
public:
	virtual void doWork(MYSQL* con) = 0;
};

//�����
class BorrowView:public Ioperation {
public:
	void doWork(MYSQL* con);
};
//�˳�
class Exit:public Ioperation
{
public:
	void doWork(MYSQL* con);
};
//�û�չʾ��
class ShowBooks:public Ioperation{
public:
	void doWork(MYSQL* con);
};

//�û�����
class BorrowBook:public Ioperation{
public:
	void doWork(MYSQL* con);
};
//�û�����
class ReturnBook:public Ioperation {
public:
	void doWork(MYSQL* con);
};

//����Ա

//�鼮��Ϣ
class ShowInformation :public Ioperation {
public:
	void doWork(MYSQL* con);
};
//����ͼ��
class AddBuyBook :public Ioperation {
public:
	void doWork(MYSQL* con);

};

//ɾ��ͼ��
class DeleteBook:public Ioperation {
public:
	void doWork(MYSQL* con);
};

//�޸��鼮
class AlterBook:public Ioperation {
public:
	void doWork(MYSQL* con);
};