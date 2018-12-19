#include "StdAfx.h"
#include "ShowMenu.h"
#include "BookManage.h"

ShowMenu::ShowMenu(void)
{
	isInit = 0;//未初始化
	isQuit = 0;//未退出
}


ShowMenu::~ShowMenu(void)
{
}


void ShowMenu::showTitle()
{
	printf("*****************************************************************\n\n");
	printf("                           图书管理系统\n\n		        1、列出当前库存\n			2、删除一本书\n			3、增添一本书\n			4、取出一本书\n			5、搜索\n			6、查看菜单\n			7、修改图书\n			8、统计\n			9、清屏\n\n");
	printf("*****************************************************************\n\n\n");
	if(isInit == 0)
	{
		bm.head = bm.readDataByTxt();//读取数据
		isInit = 1;//设置标识
	}
	ChoiceMenu();
	
}
void ShowMenu::ChoiceMenu()
{
	int functionCode;//函数代码
	char input[20];
	while(isQuit == 0)
	{
		printf("请输入您所需要的操作:");
		scanf("%d",&functionCode);//选择菜单代码
		switch(functionCode)
		{
			case 1 ://选择菜单项1
				printf("\n以下为当前图书列表:\n%8s    %10s   %10s     %s     %s\n\n","书名","作者","种类","价钱","页数");
				bm.showList(bm.head);//显示图书列表--列出当前库存
				printf("\n\n");
				break;
			case 2 ://选择菜单项2
				bm.head = bm.deleteBook(bm.head);//case 2--删除一本书
				printf("删除成功\n\n");
				break;
			case 3 ://选择菜单项3
				bm.head = bm.addBook(bm.head);//3、增添一本书
				printf("添加成功\n\n");
				break;
			case 4 ://选择菜单项4
				printf("\n输入需要查找的书的名字:");//取出一本书
				scanf("%s",input);
				printf("\n\n");
				bm.showBookByName(bm.head,input);
				printf("\n\n");
				break;
			case 5 ://选择菜单项5
				printf("\n输入需要查找的书的种类:");//搜索
				scanf("%s",input);
				printf("\n\n");
				bm.searchList = bm.searchBookByKind(bm.head,input);
				bm.showList(bm.searchList);
				printf("\n\n");
				break;
			case 6 ://选择菜单项6
				showTitle();//查看菜单
				system("pause");
				break;
			case 7 ://修改信息
				bm.alterBook(bm.head);
				break;
			case 8 ://统计信息
				bm.statiscs(bm.head);
				break;
			case 9 ://选择菜单项7
				system("cls");//清屏函数
				showTitle();//查看菜单选项
				break;
			default:
				printf("\n\n");
				printf("请输入1~7的数字\n");
				printf("\n\n");
				system("pause");
				break;
		}
	}
	
}
