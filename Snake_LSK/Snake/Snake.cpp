#include"pch.h"
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
using namespace std;
typedef struct node
{
	int x;
	int y;
	struct node *next;
}NODE;
int menu()
{
	setbkmode(TRANSPARENT);
	IMAGE background, title, titleWhenClicked;
	loadimage(&background, ".\\相关图片\\background.jpg", 640, 360);
	loadimage(&title, ".\\相关图片\\title.jpg", 300, 56);
	loadimage(&titleWhenClicked, ".\\相关图片\\titleWhenClicked.jpg", 300, 56);
	putimage(0, 0, &background);
	putimage(290, 100, &title);
	putimage(290, 200, &title);
	settextcolor(BLACK);
	settextstyle(48, 0, "宋体");
	outtextxy(320, 30, "贪  吃  蛇");
	settextstyle(36, 0, "宋体");
	outtextxy(368, 110, "开始游戏");
	outtextxy(368, 210, "  帮助  ");
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && m.x > 290 && m.x < 590 && m.y>100 && m.y < 156)//选择开始游戏功能。
		{
			putimage(290, 100, &titleWhenClicked);
			outtextxy(368, 110, "开始游戏");
			Sleep(100);
			putimage(290, 100, &title);
			outtextxy(368, 110, "开始游戏");
			Sleep(100);
			return 1;
		}
		else if (m.uMsg == WM_LBUTTONDOWN && m.x > 290 && m.x < 590 && m.y>200 && m.y < 256)//选择帮助功能。
		{
			putimage(290, 200, &titleWhenClicked);
			outtextxy(368, 210, "  帮助  ");
			Sleep(100);
			putimage(290, 200, &title);
			outtextxy(368, 210, "  帮助  ");
			Sleep(100);
			return 2;
		}
		else if (m.x > 290 && m.x < 590 && m.y>100 && m.y < 156)
		{
			settextcolor(RED);
			settextstyle(36, 0, "宋体");
			outtextxy(368, 110, "开始游戏");
		}
		else if (m.x > 290 && m.x < 590 && m.y>200 && m.y < 256)
		{
			settextcolor(RED);
			settextstyle(36, 0, "宋体");
			outtextxy(368, 210, "  帮助  ");
		}
		else
		{
			settextcolor(BLACK);
			settextstyle(36, 0, "宋体");
			outtextxy(368, 110, "开始游戏");
			outtextxy(368, 210, "  帮助  ");
		}
	}
}
void help()
{
	setbkmode(TRANSPARENT);
	cleardevice();
	IMAGE background, title, textbox, titleWhenClicked;
	loadimage(&background, ".\\相关图片\\background.jpg", 640, 360);
	loadimage(&title, ".\\相关图片\\title.jpg", 128, 36);
	loadimage(&textbox, ".\\相关图片\\textbox.jpg", 410, 250);
	loadimage(&titleWhenClicked, ".\\相关图片\\titleWhenClicked.jpg", 128, 36);
	putimage(0, 0, &background);
	putimage(472, 300, &title);
	putimage(115, 30, &textbox);
	settextcolor(BLACK);
	settextstyle(32, 0, "宋体");
	outtextxy(288, 35, "帮助");
	outtextxy(504, 300, "返回");
	settextstyle(20, 0, "宋体");
	Sleep(200);
	outtextxy(120, 80, "    游戏开始后，玩家使用W、A、S、D来操控");
	Sleep(500);
	outtextxy(120, 110, "一条贪吃蛇。每次在随机地点会出现一颗豆子");
	Sleep(500);
	outtextxy(120, 140, ",玩家操控贪吃蛇不断吞下豆子，同时蛇身不");
	Sleep(500);
	outtextxy(120, 170, "断变长，当蛇头撞到蛇身或障壁时游戏结束。");
	Sleep(500);
	outtextxy(120, 200, "游戏结束前，贪吃蛇吃到的豆子越多，分数");
	Sleep(500);
	outtextxy(120, 230, "就越高。");
	FlushMouseMsgBuffer();
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		settextstyle(32, 0, "宋体");
		if (m.uMsg == WM_LBUTTONDOWN && m.x > 504 && m.x < 568 && m.y>300 && m.y < 332)
		{
			putimage(472, 300, &titleWhenClicked);
			outtextxy(504, 300, "返回");
			Sleep(100);
			putimage(472, 300, &title);
			outtextxy(504, 300, "返回");
			Sleep(100);
			return;
		}
		else if (m.x > 504 && m.x < 568 && m.y>300 && m.y < 332)
		{
			settextcolor(RED);
			outtextxy(504, 300, "返回");
		}
		else
		{
			settextcolor(BLACK);
			outtextxy(504, 300, "返回");
		}
	}
}
void background_print()
{
	cleardevice();
	IMAGE background_white;
	loadimage(&background_white, ".\\相关图片\\background_white.jpg", 640, 360);
	putimage(0, 0, &background_white);
	setcolor(BLACK);
	line(0, 19, 640, 19);
}
NODE* add_front(NODE *h,int X,int Y)
{
	NODE *p;
	if (h == NULL)
	{
		h = (NODE *)malloc(sizeof(NODE));
		p = h;
		p->x = X;
		p->y = Y;
		p->next = NULL;
	}
	else
	{
		p = (NODE *)malloc(sizeof(NODE));
		p->x = X;
		p->y = Y;
		p->next = h;
		h = p;
	}
	return h;
}
NODE* add_back(NODE *h, int X, int Y)
{
	NODE *p, *s, *q=NULL;
	if (h == NULL)
	{
		h = (NODE *)malloc(sizeof(NODE));
		p = h;
		p->x = X;
		p->y = Y;
		p->next = NULL;
	}
	else
	{
		q = (NODE *)malloc(sizeof(NODE));
		q->x = X;
		q->y = Y;
		for (p = h;; p = p->next)
		{
			if (p->next == NULL)
			{
				s = p;
				break;
			}
		}
		s->next = q;
		q->next = NULL;
	}
	return h;
}
void print_snake(NODE *h)
{
	NODE *p;
	IMAGE snake_head, snake_body, repaint;
	loadimage(&snake_head, ".\\相关图片\\snake_head.jpg", 10, 10);
	loadimage(&snake_body, ".\\相关图片\\snake_body.jpg", 10, 10);
	loadimage(&repaint, ".\\相关图片\\repaint.jpg", 10, 10);
	for (p = h; p; p = p->next)
	{
		if (p == h)
		{
			putimage(p->x, p->y, &repaint);
		}
		else if(p->next)
		{
			putimage(p->x, p->y, &snake_body);
		}
		else
		{
			putimage(p->x, p->y, &snake_head);
		}
	}
}
int run(NODE *h,int direction,int apple_x,int apple_y)
{
	NODE *p, *q;
	for (p = h; p->next; p = p->next);
	if (!((apple_x - p->x == 10 && apple_y == p->y&&direction == 4) || (apple_x - p->x == -10 && apple_y == p->y&&direction == 3) || (apple_x == p->x&&apple_y - p->y == 10 && direction == 2) || (apple_x == p->x&&apple_y - p->y == -10 && direction == 1)))
	{
		for (p = h; p->next; p = p->next)
		{
			q = p->next;
			p->x = q->x;
			p->y = q->y;
		}
		switch (direction)
		{
			case 1:p->y -= 10; break;
			case 2:p->y += 10; break;
			case 3:p->x -= 10; break;
			case 4:p->x += 10; break;
		}
		if (p->x < 0 || p->x>640 || p->y < 20 || p->y>360)
		{
			return 0;
		}
		for (p = h; p->next; p = p->next);
		for (q = h; q->next; q = q->next)
		{
			if (p->x == q->x&&p->y == q->y)
			return 0;
		}
		return 1;
	}
	else
	{
		add_back(h, apple_x, apple_y);
		return 2;
	}
}
 bool judge(NODE *h,int X, int Y)
{
	NODE *p;
	for (p = h; p; p = p->next)
	{
		if (p->x == X || p->y == Y)
		return false;
	}
	return true;
}
 void game_over()
 {
	 cleardevice();
	 IMAGE background_gameover;
	 loadimage(&background_gameover, ".\\相关图片\\background_gameover.jpg", 640, 360);
	 putimage(0, 0, &background_gameover);
	 settextcolor(BLACK);
	 settextstyle(64, 0, "宋体");
	 outtextxy(340, 100, "失败！");
	 Sleep(2000);
 }
void play()
{
	IMAGE apple;
	IMAGE temp_1;
	IMAGE temp_2;
	loadimage(&apple, ".\\相关图片\\apple.jpg", 10, 10);
	NODE *h = NULL;
	NODE *p = NULL;
	bool isAppleExist = true;
	int direction = 4;
	int apple_x, apple_y;
	int condition = 1;
	int score=0;
	int best_score;
	bool new_record = false;
	FILE* fp;
	h = add_front(h, 40, 160);
	h = add_front(h, 30, 160);
	h = add_front(h, 20, 160);
	h = add_front(h, 10, 160);
	h = add_front(h, 0, 160);
	background_print();
	while (1)
	{
		apple_x = rand() % 64 * 10;
		apple_y = rand() % 34 * 10 + 20;
		if (judge(h, apple_x, apple_y))
		{
			putimage(apple_x, apple_y, &apple);
			break;
		}
	}
	print_snake(h);
	TCHAR Score[4],Best_Score[4];
	fp = fopen(".\\best_score.txt", "r");
	fscanf(fp, "%d", &best_score);
	fclose(fp);
	_stprintf(Score, _T("%d"), score);
	_stprintf(Best_Score, _T("%d"), best_score);
	settextstyle(18, 0, "宋体");
	settextcolor(BLACK);
	outtextxy(50, 0, "Best Score:");
	getimage(&temp_1, 150, 0, 250, 20);
	outtextxy(150, 0, Best_Score);
	outtextxy(500, 0, "Score:");
	getimage(&temp_2, 560, 0, 640, 20);
	outtextxy(560, 0, Score);
	for(int i=1;;i++)
	{
		if (new_record)
		{
			settextcolor(RED);
			outtextxy(260, 0, "A NEW RECORD !");
			settextcolor(BLACK);
		}
		if(!isAppleExist)
		{
			while (1)
			{
				apple_x = rand() % 64 * 10;
				apple_y = rand() % 34 * 10 + 20;
				if (judge(h, apple_x, apple_y))
				{
					putimage(apple_x, apple_y, &apple);
					break;
				}
			}
			isAppleExist = true;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == 'w') direction = 1;
			else if (c == 's') direction = 2;
			else if (c == 'a') direction = 3;
			else if (c == 'd') direction = 4;
		}
		Sleep(100);
		condition = run(h, direction, apple_x, apple_y);
		if (condition == 2)
		{
			score += 10;
			_stprintf(Score, _T("%d"), score);
			putimage(560, 0, &temp_2);
			if (score > best_score)
			{
				new_record = true;
				best_score = score;
				putimage(150, 0, &temp_1);
				outtextxy(150, 0, Score);
			}
			outtextxy(560, 0, Score);
			isAppleExist = false;
		}
		else if (condition == 0)
		{
			break;
		}
		print_snake(h);
	}
	fp = fopen(".\\best_score.txt", "w");
	fprintf(fp, "%d", best_score);
	fclose(fp);
	Sleep(1000);
	game_over();
}
int main()
{
	initgraph(640, 360);
	int choice;
	srand(time(0));
	while (1)
	{
		choice = menu();
		switch (choice)
		{
		case 1:play(); break;
		case 2:help(); break;
		}
	}
}