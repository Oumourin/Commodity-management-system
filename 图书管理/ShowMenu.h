#pragma once
#include "BookManage.h"
class ShowMenu//�˵���ʾ
{
public:
	ShowMenu(void);
	~ShowMenu(void);
	void showTitle();
	void ChoiceMenu();
public:
	BookManage bm;//ͼ�������
	int isInit;//�Ƿ��ʼ��
	int isQuit;//�Ƿ��˳�

};

