#pragma once
#include "BookManage.h"
class ShowMenu//菜单显示
{
public:
	ShowMenu(void);
	~ShowMenu(void);
	void showTitle();
	void ChoiceMenu();
public:
	BookManage bm;//图书管理类
	int isInit;//是否初始化
	int isQuit;//是否退出

};

