#include "Ioperation.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void BorrowView::doWork(MYSQL* con) {

	//执行sql语句
	if (mysql_query(con, "select * from bookborrow")) {
		cout << "warming," << mysql_error(con) << endl;
	}
	//获取sql语句的执行结果
	MYSQL_RES* res = mysql_use_result(con);
	//获取结果的字段
	MYSQL_FIELD* fieldName = mysql_fetch_field(res);
	for (unsigned int i = 0; i < mysql_num_fields(res); i++) {
		cout << std::left << setw(20)<<fieldName[i].name;
	}
	cout << endl;
	MYSQL_ROW row;
	while (row = mysql_fetch_row(res)) {	//按行读取结果集
		for (int i = 0; i < mysql_num_fields(res); i++) {	//将读取的行结果一个一个输出
			cout << std::left << setw(20)<< row[i];
		}
		cout << endl;
	}
	mysql_free_result(res);	//释放结果集资源
	cout << endl;
}

//退出功能
void Exit::doWork(MYSQL* con) {
	exit(0);
}
//用户展示图书
void ShowBooks::doWork(MYSQL* con) {
	//执行sql语句
	if (mysql_query(con, "select * from vw_books_with_series")) {
		cout << "warming," << mysql_error(con) << endl;
	}
	//获取sql语句的执行结果
	MYSQL_RES* res = mysql_use_result(con);
	//获取结果的字段
	MYSQL_FIELD* fieldName = mysql_fetch_field(res);
	for (unsigned int i = 0; i < mysql_num_fields(res); i++) {
		cout << std::left << setw(20)<<fieldName[i].name;
	}
	cout << endl;
	MYSQL_ROW row;
	while (row = mysql_fetch_row(res)) {	//按行读取结果集
		for (int i = 0; i < mysql_num_fields(res); i++) {	//将读取的行结果一个一个输出
			cout << std::left << setw(20)<< row[i];
		}
		cout << endl;
	}
	mysql_free_result(res);	//释放结果集资源
	cout << endl;
}

void BorrowBook::doWork(MYSQL* con) {
	//打印书籍
	ShowBooks s;
	s.ShowBooks::doWork(con);
	//借书ID
	string ID;
	cout << "请输入你要借书的ID" << endl;
	cin >> ID;
	//改变书状态借书
	stringstream ss;
	ss << "UPDATE books set status='已借出' where BookID ="<<ID ;
	string query = ss.str();
	//执行sql语句
	if (mysql_query(con, query.c_str())) {
		cout << "借书失败" << mysql_error(con) << endl;
	}
	cout << endl;
}

//归还图书

void ReturnBook::doWork(MYSQL* con) {
	int ID=0;
	cout << "请输入您要归还图书ID：" << endl;
	cin >> ID;
	//

	stringstream ss;
	ss << "UPDATE bookborrow SET isReturn = '已归还' WHERE BookID = " << ID;
	string query = ss.str();

	if (mysql_query(con, query.c_str())) {
		cout << "warming," << mysql_error(con) << endl;
	}
	cout << "归还成功" << endl;
	cout << endl;
};

//用户
void ShowInformation::doWork(MYSQL* con) {

	//执行sql语句
	if (mysql_query(con, "select * from vw_books_with_suppliers")) {
		cout << "warming," << mysql_error(con) << endl;
		return;
	}
	//获取sql语句的执行结果
	MYSQL_RES* res = mysql_use_result(con);
	//获取结果的字段
	MYSQL_FIELD* fieldName = mysql_fetch_field(res);
	for (unsigned int i = 0; i < mysql_num_fields(res); i++) {
		cout << std::left << setw(20) << fieldName[i].name;
	}
	cout << endl;
	MYSQL_ROW row;
	while (row = mysql_fetch_row(res)) {	//按行读取结果集
		for (int i = 0; i < mysql_num_fields(res); i++) {	//将读取的行结果一个一个输出
			cout << std::left << setw(20) << row[i];
		}
		cout << endl;
	}
	mysql_free_result(res);	//释放结果集资源
	cout << endl;
}


void AddBuyBook::doWork(MYSQL* con) {
	string Title, Authors, Publisher;
	int	Price, SupplierID, SeriesID;

	cout << "请输入书名：" << endl;
	cin >> Title;

	cout << "请输入作者：" << endl;
	cin >> Authors;
	cout << "请输入出版商：" << endl;
	cin >> Publisher;
	cout << "请输入价格：" << endl;
	cin >> Price;
	cout << "请输入供应商ID：" << endl;
	cin >> SupplierID;
	cout << "请输入丛书ID：" << endl;
	cin >> SeriesID;

	stringstream s1;
	s1 << "INSERT INTO books (Title, Authors, Publisher, Price, SupplierID, SeriesID, status)VALUES ('"
		<< Title << "', '" << Authors<< "', '" << Publisher << "'," << Price << "," << SupplierID << "," 
		<< SeriesID << ",'在库')";
	string query = s1.str();

	if (mysql_query(con, query.c_str())) {
		cout << "warming," << mysql_error(con) << endl;
		return;
	}

	cout << "添加成功" << endl;
	cout << endl;
}

//删除图书

void DeleteBook::doWork(MYSQL* con) {
	//展示图书
	ShowInformation s;
	s.doWork(con);
	
	int ID = 0;
	cout << "请输入您要删除图书ID：" << endl;
	cin >> ID;

	stringstream ss;
	ss << "DELETE FROM books where BookID="<<ID;
	string query = ss.str();

	if (mysql_query(con, query.c_str())) {
		cout << "warming," << mysql_error(con) << endl;
		return;
	}
	cout << "删除成功" << endl;

	cout << endl;
}

//修改书籍
void AlterBook::doWork(MYSQL* con) {
	string Title, Authors, Publisher;
	int	Price, SupplierID, SeriesID;

	cout << "请输入需要修改书名：" << endl;
	cin >> Title;
	cout << "请输入作者：" << endl;
	cin >> Authors;
	cout << "请输入出版商：" << endl;
	cin >> Publisher;
	cout << "请输入价格：" << endl;
	cin >> Price;
	cout << "请输入供应商ID：" << endl;
	cin >> SupplierID;
	cout << "请输入丛书ID：" << endl;
	cin >> SeriesID;

	//更新信息
	stringstream s1;
	s1 << "UPDATE books SET Title='" << Title
		<< "', Authors='" << Authors
		<< "', Publisher='" << Publisher
		<< "', Price=" << Price
		<< ", SupplierID=" << SupplierID
		<< ", SeriesID=" << SeriesID
		<< ", status='在库' WHERE Title='" << Title << "'";
	string query = s1.str();

	if (mysql_query(con, query.c_str())) {
		cout << "warming," << mysql_error(con) << endl;
		return;
	}

	cout << "修改成功" << endl;
	cout << endl;
}
