#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "mmsystem.h"
#pragma comment(lib, "winmm.lib")


void print();
void begin();//����music��������First stone
void printstone();
void bird();//��������½�������
void judgement();
void scoleprint();
void endorretry();

int bird_x=150,bird_y=300,i=0,k=0;//������Ͻ�����
int scole=0,t=0;
int stone_x1,stone_y1;//�Ͻ�������������
int stone_x2,stone_y2;//�Ͻ�������������
IMAGE background,bird1[4],bird2[4],scole1[10],scole2[10],stone_up1,stone_up2,stone_down1,stone_down2
,stone_up3,stone_up4,stone_down3,stone_down4;//ͼƬ�������

MOUSEMSG m;		// ���������Ϣ



int main()
{
	if(t==0)
	{
		begin();
		t++;
	}	
	if(t)
	{	
		print();
	}
	getch();  //����ͣ��
	//��ʼ��
	bird_y=300;
	bird_x=150;
	i=0;
	k=0;
	scole=0;	
	while(1)
	{
		bird();
		print();
		judgement();
	}
	closegraph();
	system("pause");
	return 0;
}






void print()
{
	putimage(0, 0, &background);//����ͼ��
	printstone();//������
	putimage(bird_x, bird_y,&bird1[i%3],NOTSRCERASE);
	putimage(bird_x, bird_y,&bird2[i%3],SRCINVERT);
	if(k%5==0)
		i++;
	k++;
	scoleprint();
	FlushBatchDraw();		// ����	
}



void printstone()//�����ƶ�����/��
{
    Sleep(30);
	if(stone_x1>210)//��ʱ���������������
	{
		//����դ����
		putimage(stone_x1, stone_y1, &stone_up2,NOTSRCERASE);  //����ͼ
		putimage(stone_x1, stone_y1, &stone_up1,SRCINVERT);	//����ͼ
		putimage(stone_x1, stone_y1+750, &stone_down2,NOTSRCERASE);
		putimage(stone_x1, stone_y1+750, &stone_down1,SRCINVERT);
		putimage(stone_x2, stone_y2, &stone_up4,NOTSRCERASE);
		putimage(stone_x2, stone_y2, &stone_up3,SRCINVERT);
		putimage(stone_x2, stone_y2+750, &stone_down4,NOTSRCERASE);
		putimage(stone_x2, stone_y2+750, &stone_down3,SRCINVERT);
		stone_x1--;stone_x2--;
	}
	else if(stone_x1==210)//��������ʧ����stone_x2,stone_y2ֵ��λ
	{
		stone_x2=stone_x1;
		stone_y2=stone_y1;
		putimage(stone_x1, stone_y1, &stone_up2,NOTSRCERASE);
		putimage(stone_x1, stone_y1, &stone_up1,SRCINVERT);
		putimage(stone_x1, stone_y1+750, &stone_down2,NOTSRCERASE);
		putimage(stone_x1, stone_y1+750, &stone_down1,SRCINVERT);
		stone_x1--;
		stone_x2--;
	}
	else if(stone_x1<210&&stone_x1>0)//����ֻ����һ�����ӵ����
	{
		putimage(stone_x1, stone_y1, &stone_up2,NOTSRCERASE);
		putimage(stone_x1, stone_y1, &stone_up1,SRCINVERT);
		putimage(stone_x1, stone_y1+750, &stone_down2,NOTSRCERASE);
		putimage(stone_x1, stone_y1+750, &stone_down1,SRCINVERT);
		stone_x1--;
		stone_x2--;	 
	}
	if(stone_x1==0)//�������end������������
	{	  
		stone_y1=rand()%310-555;
		stone_x1=350;
		putimage(stone_x1, stone_y1, &stone_up2,NOTSRCERASE);
		putimage(stone_x1, stone_y1, &stone_up1,SRCINVERT);
		putimage(stone_x1, stone_y1+750, &stone_down2,NOTSRCERASE);
		putimage(stone_x1, stone_y1+750, &stone_down1,SRCINVERT);
		stone_x1--;
		stone_x2--;
	}
}



void begin()
{
	//
	PlaySound("000.wav", NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
	initgraph(350,600);
	// ��ȡ���ھ��
	HWND hwnd = GetHWnd();
	// ���ô��ڱ�������
	SetWindowText(hwnd, "����ӵ�Flappy bird!");
	IMAGE beforegame;
	loadimage(&beforegame,"D:\\flappybird\\source\\beforegame.jpg");
	putimage(0,0,&beforegame);
	Sleep(1000);
	getch();
	BeginBatchDraw();// ����������ͼģʽ
	loadimage(&background, "D:\\flappybird\\source\\bkgroundfb.jpg");//���뱳��ͼƬ
	//��
	loadimage(&bird2[0], "D:\\flappybird\\source\\bird1-2.gif");
	loadimage(&bird1[0], "D:\\flappybird\\source\\bird1-1.gif");
	loadimage(&bird2[1], "D:\\flappybird\\source\\bird2-2.gif");
	loadimage(&bird1[1], "D:\\flappybird\\source\\bird2-1.gif");
	loadimage(&bird2[2], "D:\\flappybird\\source\\bird3-2.gif");
	loadimage(&bird1[2], "D:\\flappybird\\source\\bird3-1.gif");
	loadimage(&bird2[3], "D:\\flappybird\\source\\bird4-2.gif");
	loadimage(&bird1[3], "D:\\flappybird\\source\\bird4-1.gif");
	//����
	loadimage(&stone_up1,"D:\\flappybird\\source\\stone_up1.gif");
	loadimage(&stone_up2,"D:\\flappybird\\source\\stone_up2.gif");
	loadimage(&stone_down1,"D:\\flappybird\\source\\stone_down1.gif");
	loadimage(&stone_down2,"D:\\flappybird\\source\\stone_down2.gif");
	loadimage(&stone_up3,"D:\\flappybird\\source\\stone_up1.gif");
	loadimage(&stone_up4,"D:\\flappybird\\source\\stone_up2.gif");
	loadimage(&stone_down3,"D:\\flappybird\\source\\stone_down1.gif");
	loadimage(&stone_down4,"D:\\flappybird\\source\\stone_down2.gif");
	//����
	loadimage(&scole1[0],"D:\\flappybird\\source\\0_1.jpg");
	loadimage(&scole2[0],"D:\\flappybird\\source\\0_2.jpg");
	loadimage(&scole1[1],"D:\\flappybird\\source\\1_1.jpg");
	loadimage(&scole2[1],"D:\\flappybird\\source\\1_2.jpg");
	loadimage(&scole1[2],"D:\\flappybird\\source\\2_1.jpg");
	loadimage(&scole2[2],"D:\\flappybird\\source\\2_2.jpg");
	loadimage(&scole1[3],"D:\\flappybird\\source\\3_1.jpg");
	loadimage(&scole2[3],"D:\\flappybird\\source\\3_2.jpg");
	loadimage(&scole1[4],"D:\\flappybird\\source\\4_1.jpg");
	loadimage(&scole2[4],"D:\\flappybird\\source\\4_2.jpg");
	loadimage(&scole1[5],"D:\\flappybird\\source\\5_1.jpg");
	loadimage(&scole2[5],"D:\\flappybird\\source\\5_2.jpg");
	loadimage(&scole1[6],"D:\\flappybird\\source\\6_1.jpg");
	loadimage(&scole2[6],"D:\\flappybird\\source\\6_2.jpg");
	loadimage(&scole1[7],"D:\\flappybird\\source\\7_1.jpg");
	loadimage(&scole2[7],"D:\\flappybird\\source\\7_2.jpg");
	loadimage(&scole1[8],"D:\\flappybird\\source\\8_1.jpg");
	loadimage(&scole2[8],"D:\\flappybird\\source\\8_2.jpg");
	loadimage(&scole1[9],"D:\\flappybird\\source\\9_1.jpg");
	loadimage(&scole2[9],"D:\\flappybird\\source\\9_2.jpg");
	srand(time(0));	//��ʼ������
	print();
	//��һ�����ӣ���ʼ��
	stone_y1=rand()%310-555;
	stone_x1=350;
	stone_x2=stone_y2=-9999;	//����һ��ʼ��ʾ���ܵ�
}



void bird()
{
	char space;
	
	if(kbhit())	//��ⰴ��
	{
		space=getch();
		if(space==' ')	//���ո�
		{
			bird_y-=80;	
		}
		else if(space==27)  //ESC
		{	
			getch();
		}
	}
	else
	{
		bird_y+=3;
	}
	while(MouseHit())
	{
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		switch(m.uMsg)
		{
		case WM_LBUTTONDOWN:
			bird_y-=80;
			break;
		case WM_RBUTTONDOWN:
			getch();
			break;
		}
	}
	
}



void judgement()
{
	if((stone_x1>10 && stone_x1<20)||(stone_x1>174&&stone_x1<184))
	{
		if((bird_y>(stone_y1+576)&&bird_y<(stone_y1+600))||((bird_y>(stone_y1+726))&&bird_y<(stone_y1+750)))
		{
			endorretry();//������Ϸ
		}
	}
	else if(stone_x1>=20 && stone_x1<=174)
	{
		if(!(bird_y>(stone_y1+600)&&bird_y<(stone_y1+726)))
		{
			endorretry();	//������Ϸ
		}
	}
	if(bird_y>576)
	{
		endorretry();//������Ϸ
	}
	if(stone_x1==150)
	{	
		scole++;
	}
}



void endorretry()
{
	if(bird_y<550 && stone_x1>160)
	{	
		while(bird_y<550)
		{
			putimage(0, 0, &background);//����ͼ��
			putimage(stone_x1, stone_y1, &stone_up2,NOTSRCERASE);
			putimage(stone_x1, stone_y1, &stone_up1,SRCINVERT);
			putimage(stone_x1, stone_y1+750, &stone_down2,NOTSRCERASE);
			putimage(stone_x1, stone_y1+750, &stone_down1,SRCINVERT);
			putimage(stone_x2, stone_y2, &stone_up4,NOTSRCERASE);
			putimage(stone_x2, stone_y2, &stone_up3,SRCINVERT);
			putimage(stone_x2, stone_y2+750, &stone_down4,NOTSRCERASE);
			putimage(stone_x2, stone_y2+750, &stone_down3,SRCINVERT);
			putimage(bird_x, bird_y,&bird1[3],NOTSRCERASE);
			putimage(bird_x, bird_y,&bird2[3],SRCINVERT);
			FlushBatchDraw();
			bird_y++;
		}
	}
	IMAGE gameover1,gameover2,atlast;
	loadimage(&gameover1, "D:\\flappybird\\source\\gameover1.gif");
	loadimage(&gameover2, "D:\\flappybird\\source\\gameover2.gif");
	putimage(80, 200, &gameover1,NOTSRCERASE);
	putimage(80, 200, &gameover2,SRCINVERT);
	FlushBatchDraw();
	Sleep(1000);
	loadimage(&atlast, "D:\\flappybird\\source\\atlast.jpg");
	putimage(0,0,&atlast);
	scoleprint();
	FlushBatchDraw();
	getch();	
	//��һ������
	stone_y1=rand()%310-555;
	stone_x1=350;
	stone_x2=stone_y2=-9999;
	bird_y=300;
	scole=0;
	main();	
	
}



void scoleprint()
{
	IMAGE *fen1[6],*fen2[6];
	int he,weishu=1,i=0,sdsf=scole;
	if(sdsf==0)
	{
		putimage(250,50,&scole1[0],NOTSRCERASE);
		putimage(250,50,&scole2[0],SRCINVERT);
		
	}
	while(sdsf>0)
	{
		he=sdsf%10;
		fen1[i]=&scole1[he];
		fen2[i]=&scole2[he]; 
		putimage(300-50*weishu,50,fen1[i],NOTSRCERASE);
		putimage(300-50*weishu,50,fen2[i],SRCINVERT);
		sdsf/=10;
		i++;
		weishu++;
	}
	
}