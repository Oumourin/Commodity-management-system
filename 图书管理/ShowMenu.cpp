#include "StdAfx.h"
#include "ShowMenu.h"
#include "BookManage.h"

ShowMenu::ShowMenu(void)
{
	isInit = 0;//δ��ʼ��
	isQuit = 0;//δ�˳�
}


ShowMenu::~ShowMenu(void)
{
}


void ShowMenu::showTitle()
{
	printf("*****************************************************************\n\n");
	printf("                           ͼ�����ϵͳ\n\n		        1���г���ǰ���\n			2��ɾ��һ����\n			3������һ����\n			4��ȡ��һ����\n			5������\n			6���鿴�˵�\n			7���޸�ͼ��\n			8��ͳ��\n			9������\n\n");
	printf("*****************************************************************\n\n\n");
	if(isInit == 0)
	{
		bm.head = bm.readDataByTxt();//��ȡ����
		isInit = 1;//���ñ�ʶ
	}
	ChoiceMenu();
	
}
void ShowMenu::ChoiceMenu()
{
	int functionCode;//��������
	char input[20];
	while(isQuit == 0)
	{
		printf("������������Ҫ�Ĳ���:");
		scanf("%d",&functionCode);//ѡ��˵�����
		switch(functionCode)
		{
			case 1 ://ѡ��˵���1
				printf("\n����Ϊ��ǰͼ���б�:\n%8s    %10s   %10s     %s     %s\n\n","����","����","����","��Ǯ","ҳ��");
				bm.showList(bm.head);//��ʾͼ���б�--�г���ǰ���
				printf("\n\n");
				break;
			case 2 ://ѡ��˵���2
				bm.head = bm.deleteBook(bm.head);//case 2--ɾ��һ����
				printf("ɾ���ɹ�\n\n");
				break;
			case 3 ://ѡ��˵���3
				bm.head = bm.addBook(bm.head);//3������һ����
				printf("��ӳɹ�\n\n");
				break;
			case 4 ://ѡ��˵���4
				printf("\n������Ҫ���ҵ��������:");//ȡ��һ����
				scanf("%s",input);
				printf("\n\n");
				bm.showBookByName(bm.head,input);
				printf("\n\n");
				break;
			case 5 ://ѡ��˵���5
				printf("\n������Ҫ���ҵ��������:");//����
				scanf("%s",input);
				printf("\n\n");
				bm.searchList = bm.searchBookByKind(bm.head,input);
				bm.showList(bm.searchList);
				printf("\n\n");
				break;
			case 6 ://ѡ��˵���6
				showTitle();//�鿴�˵�
				system("pause");
				break;
			case 7 ://�޸���Ϣ
				bm.alterBook(bm.head);
				break;
			case 8 ://ͳ����Ϣ
				bm.statiscs(bm.head);
				break;
			case 9 ://ѡ��˵���7
				system("cls");//��������
				showTitle();//�鿴�˵�ѡ��
				break;
			default:
				printf("\n\n");
				printf("������1~7������\n");
				printf("\n\n");
				system("pause");
				break;
		}
	}
	
}
