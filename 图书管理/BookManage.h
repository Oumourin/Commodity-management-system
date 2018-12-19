#pragma once
//������ṹ��
typedef struct book{
	char bookName[20] ;//����
	char authorName[20] ;//������
	int pageNumber;//���ҳ��
	float price ;//�۸�
	char kind[100] ;	//����
	struct book * next ;
}Book;
class BookManage//ͼ�����
{
public:
	BookManage(void);
	~BookManage(void);
	Book * readDataByTxt();//�Ӽ��±���������
	void showList(Book *Book);//��ʾ�б�--case1����
	Book * BookManage::deleteBook(Book * head);//ɾ���鼮---�������֣���������ɾ��
	Book * searchBookByKind(Book * head , char * kind);//���������ѯ�鼮
	Book * addBook(Book *head );//����鼮
	Book * alterBook(Book *head );//�޸�ͼ����Ϣ
	int showSelf(Book Book);
	void showBookByName(Book * head, char name[]);//��ʾ�鼮---����������ʾ
	void statiscs(Book *Book);//ͳ�������Ϣ
public:
	Book *head;//����ͷָ��
	Book *searchList;//�����ѯ����
};

