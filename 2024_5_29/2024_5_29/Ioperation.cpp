#include "Ioperation.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void BorrowView::doWork(MYSQL* con) {

	//ִ��sql���
	if (mysql_query(con, "select * from bookborrow")) {
		cout << "warming," << mysql_error(con) << endl;
	}
	//��ȡsql����ִ�н��
	MYSQL_RES* res = mysql_use_result(con);
	//��ȡ������ֶ�
	MYSQL_FIELD* fieldName = mysql_fetch_field(res);
	for (unsigned int i = 0; i < mysql_num_fields(res); i++) {
		cout << std::left << setw(20)<<fieldName[i].name;
	}
	cout << endl;
	MYSQL_ROW row;
	while (row = mysql_fetch_row(res)) {	//���ж�ȡ�����
		for (int i = 0; i < mysql_num_fields(res); i++) {	//����ȡ���н��һ��һ�����
			cout << std::left << setw(20)<< row[i];
		}
		cout << endl;
	}
	mysql_free_result(res);	//�ͷŽ������Դ
	cout << endl;
}

//�˳�����
void Exit::doWork(MYSQL* con) {
	exit(0);
}
//�û�չʾͼ��
void ShowBooks::doWork(MYSQL* con) {
	//ִ��sql���
	if (mysql_query(con, "select * from vw_books_with_series")) {
		cout << "warming," << mysql_error(con) << endl;
	}
	//��ȡsql����ִ�н��
	MYSQL_RES* res = mysql_use_result(con);
	//��ȡ������ֶ�
	MYSQL_FIELD* fieldName = mysql_fetch_field(res);
	for (unsigned int i = 0; i < mysql_num_fields(res); i++) {
		cout << std::left << setw(20)<<fieldName[i].name;
	}
	cout << endl;
	MYSQL_ROW row;
	while (row = mysql_fetch_row(res)) {	//���ж�ȡ�����
		for (int i = 0; i < mysql_num_fields(res); i++) {	//����ȡ���н��һ��һ�����
			cout << std::left << setw(20)<< row[i];
		}
		cout << endl;
	}
	mysql_free_result(res);	//�ͷŽ������Դ
	cout << endl;
}

void BorrowBook::doWork(MYSQL* con) {
	//��ӡ�鼮
	ShowBooks s;
	s.ShowBooks::doWork(con);
	//����ID
	string ID;
	cout << "��������Ҫ�����ID" << endl;
	cin >> ID;
	//�ı���״̬����
	stringstream ss;
	ss << "UPDATE books set status='�ѽ��' where BookID ="<<ID ;
	string query = ss.str();
	//ִ��sql���
	if (mysql_query(con, query.c_str())) {
		cout << "����ʧ��" << mysql_error(con) << endl;
	}
	cout << endl;
}

//�黹ͼ��

void ReturnBook::doWork(MYSQL* con) {
	int ID=0;
	cout << "��������Ҫ�黹ͼ��ID��" << endl;
	cin >> ID;
	//

	stringstream ss;
	ss << "UPDATE bookborrow SET isReturn = '�ѹ黹' WHERE BookID = " << ID;
	string query = ss.str();

	if (mysql_query(con, query.c_str())) {
		cout << "warming," << mysql_error(con) << endl;
	}
	cout << "�黹�ɹ�" << endl;
	cout << endl;
};

//�û�
void ShowInformation::doWork(MYSQL* con) {

	//ִ��sql���
	if (mysql_query(con, "select * from vw_books_with_suppliers")) {
		cout << "warming," << mysql_error(con) << endl;
		return;
	}
	//��ȡsql����ִ�н��
	MYSQL_RES* res = mysql_use_result(con);
	//��ȡ������ֶ�
	MYSQL_FIELD* fieldName = mysql_fetch_field(res);
	for (unsigned int i = 0; i < mysql_num_fields(res); i++) {
		cout << std::left << setw(20) << fieldName[i].name;
	}
	cout << endl;
	MYSQL_ROW row;
	while (row = mysql_fetch_row(res)) {	//���ж�ȡ�����
		for (int i = 0; i < mysql_num_fields(res); i++) {	//����ȡ���н��һ��һ�����
			cout << std::left << setw(20) << row[i];
		}
		cout << endl;
	}
	mysql_free_result(res);	//�ͷŽ������Դ
	cout << endl;
}


void AddBuyBook::doWork(MYSQL* con) {
	string Title, Authors, Publisher;
	int	Price, SupplierID, SeriesID;

	cout << "������������" << endl;
	cin >> Title;

	cout << "���������ߣ�" << endl;
	cin >> Authors;
	cout << "����������̣�" << endl;
	cin >> Publisher;
	cout << "������۸�" << endl;
	cin >> Price;
	cout << "�����빩Ӧ��ID��" << endl;
	cin >> SupplierID;
	cout << "���������ID��" << endl;
	cin >> SeriesID;

	stringstream s1;
	s1 << "INSERT INTO books (Title, Authors, Publisher, Price, SupplierID, SeriesID, status)VALUES ('"
		<< Title << "', '" << Authors<< "', '" << Publisher << "'," << Price << "," << SupplierID << "," 
		<< SeriesID << ",'�ڿ�')";
	string query = s1.str();

	if (mysql_query(con, query.c_str())) {
		cout << "warming," << mysql_error(con) << endl;
		return;
	}

	cout << "��ӳɹ�" << endl;
	cout << endl;
}

//ɾ��ͼ��

void DeleteBook::doWork(MYSQL* con) {
	//չʾͼ��
	ShowInformation s;
	s.doWork(con);
	
	int ID = 0;
	cout << "��������Ҫɾ��ͼ��ID��" << endl;
	cin >> ID;

	stringstream ss;
	ss << "DELETE FROM books where BookID="<<ID;
	string query = ss.str();

	if (mysql_query(con, query.c_str())) {
		cout << "warming," << mysql_error(con) << endl;
		return;
	}
	cout << "ɾ���ɹ�" << endl;

	cout << endl;
}

//�޸��鼮
void AlterBook::doWork(MYSQL* con) {
	string Title, Authors, Publisher;
	int	Price, SupplierID, SeriesID;

	cout << "��������Ҫ�޸�������" << endl;
	cin >> Title;
	cout << "���������ߣ�" << endl;
	cin >> Authors;
	cout << "����������̣�" << endl;
	cin >> Publisher;
	cout << "������۸�" << endl;
	cin >> Price;
	cout << "�����빩Ӧ��ID��" << endl;
	cin >> SupplierID;
	cout << "���������ID��" << endl;
	cin >> SeriesID;

	//������Ϣ
	stringstream s1;
	s1 << "UPDATE books SET Title='" << Title
		<< "', Authors='" << Authors
		<< "', Publisher='" << Publisher
		<< "', Price=" << Price
		<< ", SupplierID=" << SupplierID
		<< ", SeriesID=" << SeriesID
		<< ", status='�ڿ�' WHERE Title='" << Title << "'";
	string query = s1.str();

	if (mysql_query(con, query.c_str())) {
		cout << "warming," << mysql_error(con) << endl;
		return;
	}

	cout << "�޸ĳɹ�" << endl;
	cout << endl;
}
