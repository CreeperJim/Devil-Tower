#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <tchar.h>
#include "talk.h"
#include "man.h"

void TalkElder(int z)
{
	char waste1,waste2;
	if (z==1)
	{
		TCHAR str[]=_T("��ӭ����ħ��");
		outtextxy(10,400,str);
		Sleep(1000);
		while (kbhit())
		{
			waste1 = getch();
			if (!isascii(waste1))
				waste2 = getch();
		}
	}
	else if (z==3)
	{
		TCHAR str[]=_T("��ħ���ŵ�Կ����������������ǰ��");
		outtextxy(10,400,str);
		Sleep(2000);
		while (kbhit())
		{
			waste1 = getch();
			if (!isascii(waste1))
				waste2 = getch();
		}
	}
	else if (z==8)
	{
		TCHAR str[]=_T("�ܸ����ټ����㣬������Ӧ�õĽ���");
		outtextxy(10,400,str);
		Sleep(2000);
		AddAttack(20);
		AddDefense(20);
		SetMap(8,16,14,1);
		while (kbhit())
		{
			waste1 = getch();
			if (!isascii(waste1))
				waste2 = getch();
		}
	}

}

void TalkMerchant(int z)
{
	TCHAR str[]=_T("���Ǽ���");
	outtextxy(10,400,str);
	Sleep(1000);
	char waste1,waste2;
	while (kbhit())
	{
		waste1 = getch();
		if (!isascii(waste1))
			waste2 = getch();
	}
}

void TalkPrincess(int z)
{
	TCHAR str[]=_T("����������");
	outtextxy(10,400,str);
	Sleep(1000);
	clearrectangle(0,400,156,425);
	TCHAR str1[]=_T("�����뿪�����");
	outtextxy(10,400,str1);
	Sleep(1000);
	char waste1,waste2;
	while (kbhit())
	{
		waste1 = getch();
		if (!isascii(waste1))
			waste2 = getch();
	}
	clearrectangle(0,0,700,544);
	RECT end = {0,0,700,544};
	drawtext(_T("You won!"),&end,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	Sleep(10000);
	closegraph();
}

void TalkBoss(int number)
{
	if(number == 1)
	{
		TCHAR str[]=_T("����YYJ");
		outtextxy(10,400,str);
		Sleep(1000);
		clearrectangle(0,400,156,425);
		TCHAR str1[]=_T("�������ҵ�");
		outtextxy(10,400,str1);
		Sleep(1000);
		clearrectangle(0,400,200,425);
		fight(108);
	}
	if(number == 2)
	{
		TCHAR str[]=_T("����LZH");
		outtextxy(10,400,str);
		Sleep(1000);
		clearrectangle(0,400,156,425);
		TCHAR str1[]=_T("�ٺٺٺٺ�");
		outtextxy(10,400,str1);
		Sleep(1000);
		clearrectangle(0,400,200,425);
		fight(109);
	}
}