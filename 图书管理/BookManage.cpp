#include "StdAfx.h"
#include "BookManage.h"

BookManage::BookManage(void)
{
	head = NULL;//定义头指针
}


BookManage::~BookManage(void)
{
}
//从记事本读入数据
Book * BookManage::readDataByTxt()
{
	char allChar[100];
	char bookName[20] ;//书名
	char authorName[20] ;//作者名
	float price ;//价格
	int pageNumber;//页数
	char kind[10]; //种类

	Book *head = NULL ;//头指针
	Book *prev = NULL ;//当前指针
	Book *bookP = NULL ;//本函数里需要使用的指针
	FILE *fp ;
	int temp = 0 , i , flag ;
	if((fp = fopen("data.txt","r"))==NULL)
	{
		printf("**********************从本地文档加载数据失败****************************\n");
	}
	else
	{
		while(1)
		{
			if(fscanf(fp,"%s%s%s%f%d",bookName,authorName,kind,&price,&pageNumber)==5)
			{
				bookP = (Book*)malloc(sizeof(Book));
				if(prev!=NULL)//如果当前指针指向空
				{
					prev->next = bookP;
				}
				if(head==NULL)
				{
					head = bookP;
				}
				//把从记事本读入的数据存到链表里
				strcpy(bookP->bookName,bookName);
				strcpy(bookP->kind,kind);
				strcpy(bookP->authorName,authorName) ;
				bookP->price = price ;
				bookP->pageNumber=pageNumber ;
				bookP->next = NULL ;
				//变换指针
				prev = bookP ;
			}else
			{
				break;
			}
		}
	}
	//showList(head);
	printf("**********************已成功从本地文档加载数据*******************\n\n");
	fclose(fp);//关闭文件
	return head ;
}

//显示列表--case1调用
void BookManage::showList(Book *Book)
{
	do
    {	//输出图书信息
        printf("%10s    %10s %10s     %.1f     %4d\n",Book->bookName,Book->authorName,Book->kind,Book->price,Book->pageNumber);
    }while(Book = Book->next);
}

//删除书籍---输入名字，按照书名删除
Book * BookManage::deleteBook(Book * head)
{
	Book *prev = NULL ;
	Book *returnP;
	char name[20];
	printf("\n输入要删的书的名字\n");
	scanf("%s",name);
	returnP = head;
	do
    {
       if(strcmp(head->bookName,name)==0&&(prev == NULL))//如果链表里存在该书，且当前指针为空
       {
       		printf("删除OK1\n");
       		head = head->next;//指针指向头结点的下一个
       		returnP = head ;
       		break ;
	   }
	   if(strcmp(head->bookName,name)==0&&(prev != NULL))//如果链表里存在该书，且当前指针不为空
	   {
	   		printf("删除OK2\n");
       		prev->next = head->next;//指针指向结点的下一个
       		break;
	   }
	   prev = head ;
    }while(head = head->next);
	return returnP ;
}

//按照种类查询书籍
Book * BookManage::searchBookByKind(Book * head , char * kind)
{
	Book * returnP = NULL , *temp = NULL ;
	do
    {
       if(strcmp(head->kind,kind)==0)//按照种类查询
       {
       		if(temp == NULL)
       		{
       			temp = head;
       			returnP = temp ;//查询的是头结点
			}
			else
			{
				temp->next = head ;//查询的不是头结点
				temp = temp->next ;
			}
	   }
    }while(head = head->next);//结点没有知道空节点
    temp->next = NULL ;
	return returnP ;
}

//添加书籍
Book * BookManage::addBook(Book *head )
{
	char bookName[20] ;//书名
	char authorName[20] ;//作者名字
	int pageNumber ;//书页数
	float price ;//价格
	char kind[100] ;//种类
	Book *book = (Book*)malloc(sizeof(Book));
	printf("\n输入书的名字:");
	scanf("%s",bookName);
	printf("输入作者的名字:");
	scanf("%s",authorName);
	printf("输入书的种类:");
	scanf("%s",kind);
	printf("输入书的价格（浮点数）:");
	scanf("%f",&price);
	printf("输入书的页数:");
	scanf("%d",&pageNumber);

	//赋值
	strcpy(book->bookName,bookName);
	strcpy(book->authorName,authorName);
	strcpy(book->kind,kind);
	book->price = price ;
	book->pageNumber = pageNumber ;
	book->next = head ;

	return book;
}

//修改图书信息
Book * BookManage::alterBook(Book *head )
{
    Book *prev = NULL ;
	Book *returnP;
	char name[20];
	printf("\n输入要修改的书的名字\n");
	scanf("%s",name);
	returnP = head;

	char bookName[20] ;//书名
	char authorName[20] ;//作者名字
	int pageNumber ;//书页数
	float price ;//价格
	char kind[100] ;//种类
	do
    {
        if(strcmp(head->bookName,name)==0)//如果链表里存在该书，修改该书信息
        {

            printf("\n输入书的名字:");
            scanf("%s",bookName);
            printf("输入作者的名字:");
            scanf("%s",authorName);
            printf("输入书的种类:");
            scanf("%s",kind);
            printf("输入书的价格（浮点数）:");
            scanf("%f",&price);
            printf("输入书的页数:");
            scanf("%d",&pageNumber);

       		//赋值
	strcpy(head->bookName,bookName);
	strcpy(head->authorName,authorName);
	strcpy(head->kind,kind);
	head->price = price ;
	head->pageNumber = pageNumber ;

	printf("tip:图书信息修改成功！\n");

       	return	returnP;
        }
    }while(head = head->next);

    printf("error:没有找到该书，请重新输入！\n");
	return returnP ;
}

int BookManage::showSelf(Book Book)
{
	printf("%s   %s   %s   %.1f   %d\n",Book.bookName,Book.authorName,Book.kind,Book.price,Book.pageNumber);
	return 0;
}
//显示书籍---按照名字显示
void BookManage::showBookByName(Book * head, char name[])
{
	do
	{
		if(strcmp(name,head->bookName)==0)
		{
			showSelf(*head);
			break;
		}
		if(head->next == NULL)
		{
			printf("没有找到\n");
		}
	}while(head = head->next);
}




//统计书的信息
void BookManage::statiscs(Book *Book)
{
    printf("\n以下为当前图书统计:\n%8s    %10s   %10s\n","图书数量","图书总价格","图书总页数");
    int book_num = 0;
    double book_price = 0.0;
    int book_pagenum = 0;
	do
    {	//输出图书信息
        //printf("%10s    %10s %10s     %.1f     %4d\n",Book->bookName,Book->authorName,Book->kind,Book->price,Book->pageNumber);
        book_num ++;
        book_price += Book->price;
        book_pagenum += Book->pageNumber;
    }while(Book = Book->next);
    printf("%5d        %.1f        %4d\n",book_num,book_price,book_pagenum);
}