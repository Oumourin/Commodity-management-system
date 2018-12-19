#include "StdAfx.h"
#include "BookManage.h"

BookManage::BookManage(void)
{
	head = NULL;//����ͷָ��
}


BookManage::~BookManage(void)
{
}
//�Ӽ��±���������
Book * BookManage::readDataByTxt()
{
	char allChar[100];
	char bookName[20] ;//����
	char authorName[20] ;//������
	float price ;//�۸�
	int pageNumber;//ҳ��
	char kind[10]; //����

	Book *head = NULL ;//ͷָ��
	Book *prev = NULL ;//��ǰָ��
	Book *bookP = NULL ;//����������Ҫʹ�õ�ָ��
	FILE *fp ;
	int temp = 0 , i , flag ;
	if((fp = fopen("data.txt","r"))==NULL)
	{
		printf("**********************�ӱ����ĵ���������ʧ��****************************\n");
	}
	else
	{
		while(1)
		{
			if(fscanf(fp,"%s%s%s%f%d",bookName,authorName,kind,&price,&pageNumber)==5)
			{
				bookP = (Book*)malloc(sizeof(Book));
				if(prev!=NULL)//�����ǰָ��ָ���
				{
					prev->next = bookP;
				}
				if(head==NULL)
				{
					head = bookP;
				}
				//�ѴӼ��±���������ݴ浽������
				strcpy(bookP->bookName,bookName);
				strcpy(bookP->kind,kind);
				strcpy(bookP->authorName,authorName) ;
				bookP->price = price ;
				bookP->pageNumber=pageNumber ;
				bookP->next = NULL ;
				//�任ָ��
				prev = bookP ;
			}else
			{
				break;
			}
		}
	}
	//showList(head);
	printf("**********************�ѳɹ��ӱ����ĵ���������*******************\n\n");
	fclose(fp);//�ر��ļ�
	return head ;
}

//��ʾ�б�--case1����
void BookManage::showList(Book *Book)
{
	do
    {	//���ͼ����Ϣ
        printf("%10s    %10s %10s     %.1f     %4d\n",Book->bookName,Book->authorName,Book->kind,Book->price,Book->pageNumber);
    }while(Book = Book->next);
}

//ɾ���鼮---�������֣���������ɾ��
Book * BookManage::deleteBook(Book * head)
{
	Book *prev = NULL ;
	Book *returnP;
	char name[20];
	printf("\n����Ҫɾ���������\n");
	scanf("%s",name);
	returnP = head;
	do
    {
       if(strcmp(head->bookName,name)==0&&(prev == NULL))//�����������ڸ��飬�ҵ�ǰָ��Ϊ��
       {
       		printf("ɾ��OK1\n");
       		head = head->next;//ָ��ָ��ͷ������һ��
       		returnP = head ;
       		break ;
	   }
	   if(strcmp(head->bookName,name)==0&&(prev != NULL))//�����������ڸ��飬�ҵ�ǰָ�벻Ϊ��
	   {
	   		printf("ɾ��OK2\n");
       		prev->next = head->next;//ָ��ָ�������һ��
       		break;
	   }
	   prev = head ;
    }while(head = head->next);
	return returnP ;
}

//���������ѯ�鼮
Book * BookManage::searchBookByKind(Book * head , char * kind)
{
	Book * returnP = NULL , *temp = NULL ;
	do
    {
       if(strcmp(head->kind,kind)==0)//���������ѯ
       {
       		if(temp == NULL)
       		{
       			temp = head;
       			returnP = temp ;//��ѯ����ͷ���
			}
			else
			{
				temp->next = head ;//��ѯ�Ĳ���ͷ���
				temp = temp->next ;
			}
	   }
    }while(head = head->next);//���û��֪���սڵ�
    temp->next = NULL ;
	return returnP ;
}

//����鼮
Book * BookManage::addBook(Book *head )
{
	char bookName[20] ;//����
	char authorName[20] ;//��������
	int pageNumber ;//��ҳ��
	float price ;//�۸�
	char kind[100] ;//����
	Book *book = (Book*)malloc(sizeof(Book));
	printf("\n�����������:");
	scanf("%s",bookName);
	printf("�������ߵ�����:");
	scanf("%s",authorName);
	printf("�����������:");
	scanf("%s",kind);
	printf("������ļ۸񣨸�������:");
	scanf("%f",&price);
	printf("�������ҳ��:");
	scanf("%d",&pageNumber);

	//��ֵ
	strcpy(book->bookName,bookName);
	strcpy(book->authorName,authorName);
	strcpy(book->kind,kind);
	book->price = price ;
	book->pageNumber = pageNumber ;
	book->next = head ;

	return book;
}

//�޸�ͼ����Ϣ
Book * BookManage::alterBook(Book *head )
{
    Book *prev = NULL ;
	Book *returnP;
	char name[20];
	printf("\n����Ҫ�޸ĵ��������\n");
	scanf("%s",name);
	returnP = head;

	char bookName[20] ;//����
	char authorName[20] ;//��������
	int pageNumber ;//��ҳ��
	float price ;//�۸�
	char kind[100] ;//����
	do
    {
        if(strcmp(head->bookName,name)==0)//�����������ڸ��飬�޸ĸ�����Ϣ
        {

            printf("\n�����������:");
            scanf("%s",bookName);
            printf("�������ߵ�����:");
            scanf("%s",authorName);
            printf("�����������:");
            scanf("%s",kind);
            printf("������ļ۸񣨸�������:");
            scanf("%f",&price);
            printf("�������ҳ��:");
            scanf("%d",&pageNumber);

       		//��ֵ
	strcpy(head->bookName,bookName);
	strcpy(head->authorName,authorName);
	strcpy(head->kind,kind);
	head->price = price ;
	head->pageNumber = pageNumber ;

	printf("tip:ͼ����Ϣ�޸ĳɹ���\n");

       	return	returnP;
        }
    }while(head = head->next);

    printf("error:û���ҵ����飬���������룡\n");
	return returnP ;
}

int BookManage::showSelf(Book Book)
{
	printf("%s   %s   %s   %.1f   %d\n",Book.bookName,Book.authorName,Book.kind,Book.price,Book.pageNumber);
	return 0;
}
//��ʾ�鼮---����������ʾ
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
			printf("û���ҵ�\n");
		}
	}while(head = head->next);
}




//ͳ�������Ϣ
void BookManage::statiscs(Book *Book)
{
    printf("\n����Ϊ��ǰͼ��ͳ��:\n%8s    %10s   %10s\n","ͼ������","ͼ���ܼ۸�","ͼ����ҳ��");
    int book_num = 0;
    double book_price = 0.0;
    int book_pagenum = 0;
	do
    {	//���ͼ����Ϣ
        //printf("%10s    %10s %10s     %.1f     %4d\n",Book->bookName,Book->authorName,Book->kind,Book->price,Book->pageNumber);
        book_num ++;
        book_price += Book->price;
        book_pagenum += Book->pageNumber;
    }while(Book = Book->next);
    printf("%5d        %.1f        %4d\n",book_num,book_price,book_pagenum);
}