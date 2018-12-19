#pragma once
//定义书结构体
typedef struct book{
	char bookName[20] ;//书名
	char authorName[20] ;//作者名
	int pageNumber;//书的页数
	float price ;//价格
	char kind[100] ;	//种类
	struct book * next ;
}Book;
class BookManage//图书管理
{
public:
	BookManage(void);
	~BookManage(void);
	Book * readDataByTxt();//从记事本读入数据
	void showList(Book *Book);//显示列表--case1调用
	Book * BookManage::deleteBook(Book * head);//删除书籍---输入名字，按照书名删除
	Book * searchBookByKind(Book * head , char * kind);//按照种类查询书籍
	Book * addBook(Book *head );//添加书籍
	Book * alterBook(Book *head );//修改图书信息
	int showSelf(Book Book);
	void showBookByName(Book * head, char name[]);//显示书籍---按照名字显示
	void statiscs(Book *Book);//统计书的信息
public:
	Book *head;//定义头指针
	Book *searchList;//定义查询链表
};

