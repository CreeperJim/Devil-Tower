#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <tchar.h>
#include "talk.h"

void TalkElder(int z)
{
	TCHAR str[]=_T("��ӭ����ħ��");
	outtextxy(10,400,str);
	Sleep(1000);
}

void TalkMerchant(int z)
{
	TCHAR str[]=_T("���Ǽ���");
	outtextxy(10,400,str);
	Sleep(1000);
}

void TalkPrincess(int z)
{
	TCHAR str[]=_T("���ǹ���");
	outtextxy(10,400,str);
	Sleep(1000);
}

void TalkBoss(int z)
{
	TCHAR str[]=_T("����Boss");
	outtextxy(10,400,str);
	Sleep(1000);
}