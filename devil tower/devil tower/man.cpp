#include <math.h>
#include <graphics.h>
#include <conio.h>

extern int Health = 1000;                                  //Ѫ��
extern int Attack = 10;                                    //������
extern int Defense = 10;                                   //������
extern int Agility = 1;                                    //���ݶ�
extern int DodgeProbability;
extern bool HasTransfer = false;                           //����¥������
extern bool HasDictionary = false;                         //�й��ﱦ��
extern int YellowKey = 0;                                  //��Կ����Ŀ
extern int BlueKey = 0;                                    //��Կ����Ŀ
extern int RedKey = 0;                                     //��Կ����Ŀ
extern int yman;                                           //Ӣ�۵�y����
extern int xman;                                           //Ӣ�۵�x����
extern int z = 0;                                          //Ӣ�����ڵ�¥����
extern int Money = 0;                                      //��Ǯ��
extern int Experience = 0;                                 //������
extern int level = 1;                                      //�ȼ���


void AddAttack (int Increment)
{
    Attack += Increment;
}

void AddDefense (int Increment)
{
    Defense += Increment;
}

void AddHealth (int Increment)
{
    Health += Increment;
}

void AddAgility (int Increment)
{
    Agility += Increment;
    DodgeProbablity = (int)(10 * sqrt(Agility));
}

void AddMoney (int Increment)
{
    Money += Increment;
}

void AddExperience (int Increment)
{
    Experience += Increment;
}

void SetMap (int z,int x,int y,int ID)
{
    map[z][x][y] = ID;
}

void move (int z)
{
	char c;
	if (kbhit())
		c=_getch();
    switch (c)
    {
        case 'w':
            if (yman+1 <= 16)
            {
                SetMap(z,xman,yman,101);
                if (map[z][xman][yman+1] == 0)                                            //ǰ���ǿյ�
                {
                    yman += 1;
                    SetMap(z,xman,yman,101);
                    SetMap(z,xman,yman-1,0);
                }
                else if ((map[z][xman][yman+1] >= 300)&&(map[z][xman][yman+1] <= 500))        //ǰ���ǹ���
                {
                    fight(map[z][xman][yman+1]);
                    SetMap(z,xman,yman+1,0);
                }
                else if ((map[z][xman][yman+1] >= 200)&&(map[z][xman][yman+1] <= 299))         //ǰ���Ǳ�ʯ��Ѫҩ
                {
                    if(map[z][xman][yman+1] == 206)                                           //СѪƿ
                    {
                        AddHealth(200);
                    }
                    else if(map[z][xman][yman+1] == 207)                                      //��Ѫƿ
                    {
                        AddHealth(500);
                    }
                    else if(map[z][xman][yman+1] == 208)                                      //��Ѫƿ
                    {
                        AddHealth(1000);
                    }
                    else if(map[z][xman][yman+1] == 203)                                      //������ʯ���챦ʯ
                    {
                        AddAttack(3);
                    }
                    else if(map[z][xman][yman+1] == 204)                                      //������ʯ������ʯ
                    {
                        AddDefense(3);
                    }
                    else if(map[z][xman][yman+1] == 205)                                      //���ݱ�ʯ���̱�ʯ
                    {
                        AddAgility(1);
                    }
                    yman += 1;
                    SetMap(z,xman,yman-1,0);
                }
                else if ((map[z][xman][yman+1] >= 2)&&(map[z][xman][yman+1] <=4 ))         //ǰ������
                {
                    if ((map[z][xman][yman+1] == 2)&&(YellowKey>0))                          //����
                    {
                        YellowKey -= 1;
                    }
                    else if ((map[z][xman][yman+1] == 3)&&(BlueKey>0))                       //����
                    {
                        BlueKey -= 1;
                    }
                    else if ((map[z][xman][yman+1] == 4)&&(RedKey>0))                        //����
                    {
                        RedKey -= 1;
                    }
                    SetMap(z,xman,yman+1,0);
                }
                else if (map[z][xman][yman+1] == 209)                                          //�������
                {
                    HasTransfer = true;
                    yman += 1;
                    SetMap(z,xman,yman,101);
                    SetMap(z,xman,yman-1,0);
                }
                else if (map[z][xman][yman+1] == 210)                                          //�ֵ�
                {
                    HasDictionary = true;
                    yman += 1;
                    SetMap(z,xman,yman,101);
                    SetMap(z,xman,yman-1,0);
                }
                else if (map[z][xman][yman+1] == 211)                                           //����
                {
                    AddMoney(100);
                    yman += 1;
                    SetMap(z,xman,yman,101);
                    SetMap(z,xman,yman-1,0);
                }
                else if (map[z][xman][yman+1] == 10)                                             //��Ǯ�̵�
                {
                    MoneyPurchase();
                }
                else if (map[z][xman][yman+1] == 11)                                             //�����̵�
                {
                    ExperiencePurchase();
                }
                else if (map[z][xman][yman+1] == 8)                                              //��¥
                {
                    z += 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 9)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
                }
                else if (map[z][xman][yman+1] == 9)                                                //��¥
                {
                    z -= 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 10)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
                }
                else if (map[z][xman][yman+1] == 104)                                            //��׷����˽���
                {
                    TalkElder(z);
                }
                else if (map[z][xman][yman+1] == 105)                                            //������̸��
                {
                    TalkMerchant(z);
                }
                else if (map[z][xman][yman+1] == 106)                                            //�빫��̸��
                {
                    TalkPrincess();
                }
                else if (map[z][xman][yman+1] == 107)                                            //��Boss̸��
                {
                    TalkBoss();
                }
                else
                {
                    SetMap(z,xman,yman,101);
                }
            }
            else
            {
                SetMap(z,xman,yman,101);
            }
            display(z);
            break;


        case 's':
            if (yman-1 >= 0)
            {
                SetMap(z,xman,yman,100);
                if (map[z][xman][yman-1] == 0)                                            //ǰ���ǿյ�
                {
                    yman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman,yman+1,0);
                }
                else if ((map[z][xman][yman-1] >= 300)&&(map[z][xman][yman-1] <= 500))        //ǰ���ǹ���
                {
                    fight(map[z][xman][yman-1]);
                    SetMap(z,xman,yman-1,0);
                }
                else if ((map[z][xman][yman-1] >= 200)&&(map[z][xman][yman-1] <= 299))         //ǰ���Ǳ�ʯ��Ѫҩ
                {
                    if(map[z][xman][yman-1] == 206)                                           //СѪƿ
                    {
                        AddHealth(200);
                    }
                    else if(map[z][xman][yman-1] == 207)                                      //��Ѫƿ
                    {
                        AddHealth(500);
                    }
                    else if(map[z][xman][yman-1] == 208)                                      //��Ѫƿ
                    {
                        AddHealth(1000);
                    }
                    else if(map[z][xman][yman-1] == 203)                                      //������ʯ���챦ʯ
                    {
                        AddAttack(3);
                    }
                    else if(map[z][xman][yman-1] == 204)                                      //������ʯ������ʯ
                    {
                        AddDefense(3);
                    }
                    else if(map[z][xman][yman-1] == 205)                                      //���ݱ�ʯ���̱�ʯ
                    {
                        AddAgility(1);
                    }
                    yman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman,yman+1,0);
                }
                else if ((map[z][xman][yman-1] >= 2)&&(map[z][xman][yman-1] <=4 ))         //ǰ������
                {
                    if ((map[z][xman][yman-1] == 2)&&(YellowKey>0))                          //����
                    {
                        YellowKey -= 1;
                    }
                    else if ((map[z][xman][yman-1] == 3)&&(BlueKey>0))                       //����
                    {
                        BlueKey -= 1;
                    }
                    else if ((map[z][xman][yman-1] == 4)&&(RedKey>0))                        //����
                    {
                        RedKey -= 1;
                    }
                    SetMap(z,xman,yman-1,0);
                }
                else if (map[z][xman][yman-1] == 209)                                          //�������
                {
                    HasTransfer = true;
                    yman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman,yman+1,0);
                }
                else if (map[z][xman][yman-1] == 210)                                          //�ֵ�
                {
                    HasDictionary = true;
                    yman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman,yman+1,0);
                }
                else if (map[z][xman][yman-1] == 211)                                           //����
                {
                    AddMoney(100);
                    yman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman,yman-1,0);
                }
                else if (map[z][xman][yman-1] == 10)                                             //��Ǯ�̵�
                {
                    MoneyPurchase();
                }
                else if (map[z][xman][yman-1] == 11)                                             //�����̵�
                {
                    ExperiencePurchase();
                }
                else if (map[z][xman][yman-1] == 8)                                              //��¥
                {
                    z += 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 9)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
                }
                else if (map[z][xman][yman-1] == 9)                                               //��¥
                {
                    z -= 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 10)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
                }
                else if (map[z][xman][yman+1] == 104)                                            //��׷����˽���
                {
                    TalkElder(z);
                }
                else if (map[z][xman][yman+1] == 105)                                            //������̸��
                {
                    TalkMerchant(z);
                }
                else if (map[z][xman][yman+1] == 106)                                            //�빫��̸��
                {
                    TalkPrincess();
                }
                else if (map[z][xman][yman+1] == 107)                                            //��Boss̸��
                {
                    TalkBoss();
                }
                else
                {
                    SetMap(z,xman,yman,100);
                }
            }
            else
            {
                SetMap(z,xman,yman,100);
            }
            display(z);
            break;



        case 'a':
            if (xman-1 >= 0)
            {
                SetMap(z,xman,yman,100);
                if (map[z][xman-1][yman] == 0)                                            //ǰ���ǿյ�
                {
                    xman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman+1,yman,0);
                }
                else if ((map[z][xman-1][yman] >= 300)&&(map[z][xman-1][yman] <= 500))        //ǰ���ǹ���
                {
                    fight(map[z][xman-1][yman]);
                    SetMap(z,xman-1,yman,0);
                }
                else if ((map[z][xman-1][yman] >= 200)&&(map[z][xman-1][yman] <= 299))         //ǰ���Ǳ�ʯ��Ѫҩ
                {
                    if(map[z][xman-1][yman] == 206)                                           //СѪƿ
                    {
                        AddHealth(200);
                    }
                    else if(map[z][xman-1][yman] == 207)                                      //��Ѫƿ
                    {
                        AddHealth(500);
                    }
                    else if(map[z][xman-1][yman] == 208)                                      //��Ѫƿ
                    {
                        AddHealth(1000);
                    }
                    else if(map[z][xman-1][yman] == 203)                                      //������ʯ���챦ʯ
                    {
                        AddAttack(3);
                    }
                    else if(map[z][xman-1][yman] == 204)                                      //������ʯ������ʯ
                    {
                        AddDefense(3);
                    }
                    else if(map[z][xman-1][yman] == 205)                                      //���ݱ�ʯ���̱�ʯ
                    {
                        AddAgility(1);
                    }
                    xman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman+1,yman,0);
                }
                else if ((map[z][xman-1][yman] >= 2)&&(map[z][xman-1][yman] <=4 ))         //ǰ������
                {
                    if ((map[z][xman-1][yman] == 2)&&(YellowKey>0))                          //����
                    {
                        YellowKey -= 1;
                    }
                    else if ((map[z][xman-1][yman] == 3)&&(BlueKey>0))                       //����
                    {
                        BlueKey -= 1;
                    }
                    else if ((map[z][xman-1][yman] == 4)&&(RedKey>0))                        //����
                    {
                        RedKey -= 1;
                    }
                    SetMap(z,xman-1,yman,0);
                }
                else if (map[z][xman-1][yman] == 209)                                          //�������
                {
                    HasTransfer = true;
                    xman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman+1,yman,0);
                }
                else if (map[z][xman-1][yman] == 210)                                          //�ֵ�
                {
                    HasDictionary = true;
                    xman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman+1,yman,0);
                }
                else if (map[z][xman-1][yman] == 211)                                           //����
                {
                    AddMoney(100);
                    xman -= 1;
                    SetMap(z,xman-1,yman,100);
                    SetMap(z,xman,yman,0);
                }
                else if (map[z][xman-1][yman] == 10)                                             //��Ǯ�̵�
                {
                    MoneyPurchase();
                }
                else if (map[z][xman-1][yman] == 11)                                             //�����̵�
                {
                    ExperiencePurchase();
                }
                else if (map[z][xman-1][yman] == 8)                                              //��¥
                {
                    z += 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 9)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
                }
                else if (map[z][xman-1][yman] == 9)                                               //��¥
                {
                    z -= 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 10)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
                }
                else if (map[z][xman-1][yman] == 104)                                            //��׷����˽���
                {
                    TalkElder(z);
                }
                else if (map[z][xman-1][yman] == 105)                                            //������̸��
                {
                    TalkMerchant(z);
                }
                else if (map[z][xman-1][yman] == 106)                                            //�빫��̸��
                {
                    TalkPrincess();
                }
                else if (map[z][xman-1][yman] == 107)                                            //��Boss̸��
                {
                    TalkBoss();
                }
                else
                {
                    SetMap(z,xman,yman,100);
                }
            }
            else
            {
                SetMap(z,xman,yman,100);
            }
            display(z);
            break;



        case 'd':
            if (xman+1 >= 0)
            {
                SetMap(z,xman,yman,100);
                if (map[z][xman+1][yman] == 0)                                            //ǰ���ǿյ�
                {
                    xman += 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman-1,yman,0);
                }
                else if ((map[z][xman+1][yman] >= 300)&&(map[z][xman+1][yman] <= 500))        //ǰ���ǹ���
                {
                    fight(map[z][xman+1][yman]);
                    SetMap(z,xman+1,yman,0);
                }
                else if ((map[z][xman+1][yman] >= 200)&&(map[z][xman+1][yman] <= 299))         //ǰ���Ǳ�ʯ��Ѫҩ
                {
                    if(map[z][xman+1][yman] == 206)                                           //СѪƿ
                    {
                        AddHealth(200);
                    }
                    else if(map[z][xman+1][yman] == 207)                                      //��Ѫƿ
                    {
                        AddHealth(500);
                    }
                    else if(map[z][xman+1][yman] == 208)                                      //��Ѫƿ
                    {
                        AddHealth(1000);
                    }
                    else if(map[z][xman+1][yman] == 203)                                      //������ʯ���챦ʯ
                    {
                        AddAttack(3);
                    }
                    else if(map[z][xman+1][yman] == 204)                                      //������ʯ������ʯ
                    {
                        AddDefense(3);
                    }
                    else if(map[z][xman+1][yman] == 205)                                      //���ݱ�ʯ���̱�ʯ
                    {
                        AddAgility(1);
                    }
                    xman += 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman-1,yman,0);
                }
                else if ((map[z][xman+1][yman] >= 2)&&(map[z][xman+1][yman] <=4 ))         //ǰ������
                {
                    if ((map[z][xman+1][yman] == 2)&&(YellowKey>0))                          //����
                    {
                        YellowKey -= 1;
                    }
                    else if ((map[z][xman+1][yman] == 3)&&(BlueKey>0))                       //����
                    {
                        BlueKey -= 1;
                    }
                    else if ((map[z][xman+1][yman] == 4)&&(RedKey>0))                        //����
                    {
                        RedKey -= 1;
                    }
                    SetMap(z,xman+1,yman,0);
                }
                else if (map[z][xman+1][yman] == 209)                                          //�������
                {
                    HasTransfer = true;
                    xman += 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman-1,yman,0);
                }
                else if (map[z][xman+1][yman] == 210)                                          //�ֵ�
                {
                    HasDictionary = true;
                    xman += 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman-1,yman,0);
                }
                else if (map[z][xman+1][yman] == 211)                                           //����
                {
                    AddMoney(100);
                    xman += 1;
                    SetMap(z,xman+1,yman,100);
                    SetMap(z,xman,yman,0);
                }
                else if (map[z][xman+1][yman] == 10)                                             //��Ǯ�̵�
                {
                    MoneyPurchase();
                }
                else if (map[z][xman+1][yman] == 11)                                             //�����̵�
                {
                    ExperiencePurchase();
                }
                else if (map[z][xman+1][yman] == 8)                                              //��¥
                {
                    z += 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 9)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
                }
                else if (map[z][xman+1][yman] == 9)                                               //��¥
                {
                    z -= 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 10)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
                }
                else if (map[z][xman+1][yman] == 104)                                            //��׷����˽���
                {
                    TalkElder(z);
                }
                else if (map[z][xman+1][yman] == 105)                                            //������̸��
                {
                    TalkMerchant(z);
                }
                else if (map[z][xman+1][yman] == 106)                                            //�빫��̸��
                {
                    TalkPrincess();
                }
                else if (map[z][xman+1][yman] == 107)                                            //��Boss̸��
                {
                    TalkBoss();
                }
                else
                {
                    SetMap(z,xman,yman,100);
                }
            }
            else
            {
                SetMap(z,xman,yman,100);
            }
            display(z);
            break;
    }
}
