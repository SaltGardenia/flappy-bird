#include <iostream>
#include <graphics.h> //EasyX 头文件
#include <windows.h>
#include <conio.h>
#include <random>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#pragma comment(lib, "winmm.lib"); //多媒体接口

void ShowMenu();
void GameReady();
void GameStart();
void ShowCoins(int x, int y);
void ShowPip();

int main(int argc, char** argv) {
	GameReady();
	GameStart();
	return 0;
}

#define MENU_GAME_START 0
#define MENU_GAME_SET 1
#define MENU_GAME_HELP 2
#define MENU_GAME_EXIT 3

int MenuSelect = 0;

void ShowMenu() {
	//绘制菜单
	setfillcolor(BLUE);

	rectangle(200, 120, 450, 170);
	fillrectangle(200, 120, 450, 170);
	RECT RectangleOfGameStart = {200, 120, 450, 170};
	char *StringOfGameStart = "游戏开始";
	drawtext(StringOfGameStart, &RectangleOfGameStart, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	rectangle(200, 170, 450, 220);
	fillrectangle(200, 170, 450, 220);
	RECT RectangleOfGameSet = {200, 170, 450, 220};
	char *StringOfGameSet = "游戏设置";
	drawtext(StringOfGameSet, &RectangleOfGameSet, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	rectangle(200, 220, 450, 270);
	fillrectangle(200, 220, 450, 270);
	RECT RectangleOfGameHelp = {200, 220, 450, 270};
	char *StringOfGameHelp = "游戏帮助";
	drawtext(StringOfGameHelp, &RectangleOfGameHelp, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	rectangle(200, 270, 450, 320);
	fillrectangle(200, 270, 450, 320);
	RECT RectangleOfGameExit = {200, 270, 450, 320};
	char *GameExit = "游戏退出";
	drawtext(GameExit, &RectangleOfGameExit, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//动态菜单
	setfillcolor(RED);
	fillrectangle(200, 120, 450, 170);
	drawtext(StringOfGameStart, &RectangleOfGameStart, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	while(1) {
		Sleep(100); //睡眠100ms，防止检测按键过快
		if(kbhit()) {
			//向下识别
			if(GetAsyncKeyState(VK_DOWN)) {
				switch(MenuSelect) {
					case MENU_GAME_START:
						setfillcolor(BLUE);
						fillrectangle(200, 120, 450, 170);
						drawtext(StringOfGameStart, &RectangleOfGameStart, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						setfillcolor(RED);
						fillrectangle(200, 170, 450, 220);
						drawtext(StringOfGameSet, &RectangleOfGameSet, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						MenuSelect = 1;
						break;
					case MENU_GAME_SET:
						setfillcolor(BLUE);
						fillrectangle(200, 170, 450, 220);
						drawtext(StringOfGameSet, &RectangleOfGameSet, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						setfillcolor(RED);
						fillrectangle(200, 220, 450, 270);
						drawtext(StringOfGameHelp, &RectangleOfGameHelp, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						MenuSelect = 2;
						break;
					case MENU_GAME_HELP:
						setfillcolor(BLUE);
						fillrectangle(200, 220, 450, 270);
						drawtext(StringOfGameHelp, &RectangleOfGameHelp, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						setfillcolor(RED);
						fillrectangle(200, 270, 450, 320);
						drawtext(GameExit, &RectangleOfGameExit, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						MenuSelect = 3;
						break;
					case MENU_GAME_EXIT:
						setfillcolor(BLUE);
						fillrectangle(200, 270, 450, 320);
						drawtext(GameExit, &RectangleOfGameExit, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						setfillcolor(RED);
						fillrectangle(200, 120, 450, 170);
						drawtext(StringOfGameStart, &RectangleOfGameStart, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						MenuSelect = 0;
						break;
				}
			}
			//向上识别
			if(GetAsyncKeyState(VK_UP)) {
				switch(MenuSelect) {
					case MENU_GAME_START:
						setfillcolor(BLUE);
						fillrectangle(200, 120, 450, 170);
						drawtext(StringOfGameStart, &RectangleOfGameStart, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

						setfillcolor(RED);
						fillrectangle(200, 270, 450, 320);
						drawtext(GameExit, &RectangleOfGameExit, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						MenuSelect = 3;
						break;

					case MENU_GAME_SET:
						setfillcolor(BLUE);
						fillrectangle(200, 170, 450, 220);
						drawtext(StringOfGameSet, &RectangleOfGameSet, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						
						setfillcolor(RED);
						fillrectangle(200, 120, 450, 170);
						drawtext(StringOfGameStart, &RectangleOfGameStart, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						MenuSelect = 0;
						break;

					case MENU_GAME_HELP:
						setfillcolor(BLUE);
						fillrectangle(200, 220, 450, 270);
						drawtext(StringOfGameHelp, &RectangleOfGameHelp, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

						setfillcolor(RED);
						fillrectangle(200, 170, 450, 220);
						drawtext(StringOfGameSet, &RectangleOfGameSet, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						MenuSelect = 1;
						break;

					case MENU_GAME_EXIT:
						setfillcolor(BLUE);
						fillrectangle(200, 270, 450, 320);
						drawtext(GameExit, &RectangleOfGameExit, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

						setfillcolor(RED);
						fillrectangle(200, 220, 450, 270);
						drawtext(StringOfGameHelp, &RectangleOfGameHelp, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						MenuSelect = 2;
						break;
				}
			}
			if(GetAsyncKeyState(VK_RETURN)) {
				switch(MenuSelect) {
					case MENU_GAME_START:
						return;
						break;
					case MENU_GAME_SET:
						break;
					case MENU_GAME_HELP:
						break;
					case MENU_GAME_EXIT:
						break;
				}
			}
		}
	}
}

IMAGE BackImage;
IMAGE BirdImage;
IMAGE BirdBackImage;
IMAGE PipUpImage;
IMAGE PipUpBackImage;
IMAGE PipDownImage;
IMAGE PipDownBackImage;
IMAGE CoinsImage;

void GameReady() {
	//初始化窗口
	initgraph(685, 800, EX_SHOWCONSOLE);

	//显示菜单
	ShowMenu();

	//设置背景
	loadimage(&BackImage, "./img/back12.jpg");

	//读入小鸟图片并完成抠图
	loadimage(&BirdImage, "./img/bird1_2.jpg");
	loadimage(&BirdBackImage, "./img/bird1_1.jpg");

	//读入水管图片
	loadimage(&PipUpImage, "./img/stone_down2.gif");
	loadimage(&PipUpBackImage, "./img/stone_down1.gif");
	loadimage(&PipDownImage, "./img/stone_up1.gif");
	loadimage(&PipDownBackImage, "./img/stone_up2.gif");

	//读入金币图片
	loadimage(&CoinsImage, "./img/ani.bmp");
}

#define COIN_WIDTH 32
#define COIN_HEIGHT 32

void ShowCoins(int x, int y) {
	static int index = 0;
	if(index >= 4) index = 0;
	putimage(x, y, COIN_WIDTH, COIN_HEIGHT, &CoinsImage, (0 + index) * COIN_WIDTH, 9 * COIN_HEIGHT, SRCAND);
	putimage(x, y, COIN_WIDTH, COIN_HEIGHT, &CoinsImage, (0 + index) * COIN_WIDTH, 8 * COIN_HEIGHT, SRCPAINT);
	index++;
}

int PipUpY[4] = { 0 };
int PipDownY[4] = { 0 };
int PipX[4] = {700, 900, 1100, 1300};

void ShowPip() {
    // 实现水管随机
    srand((unsigned)time(NULL));
    
    // 初始化水管位置
    for (int i = 0; i < 4; i++) {
		if (PipDownY[i] == 0) {
			PipDownY[i] = rand() % 400 + 200;  // 随机生成200到600之间的高度
			PipUpY[i] = PipDownY[i] - 670;  // 上下水管间距70像素
		}
    }
    
    // 绘制水管和金币
    for (int i = 0; i < 4; i++) {
        // 绘制上水管
        putimage(PipX[i], PipUpY[i], &PipUpBackImage, NOTSRCERASE);
        putimage(PipX[i], PipUpY[i], &PipUpImage, SRCINVERT);
        
        // 绘制下水管
        putimage(PipX[i], PipDownY[i], &PipDownBackImage, NOTSRCERASE);
        putimage(PipX[i], PipDownY[i], &PipDownImage, SRCINVERT);
        
        // 在水管间隙绘制金币
        ShowCoins(PipX[i], PipUpY[i] - 35);  // 金币位于上下水管中间
        
        // 水管向左移动
        PipX[i] -= 2;
        
        // 如果水管移出屏幕左侧，重置到右侧
        if (PipX[0] < -50) {
            for (int j = 0; j < 3; j++) {
                PipX[j] = PipX[j + 1];
                PipDownY[j] = PipDownY[j + 1];
                PipUpY[j] = PipUpY[j + 1];
            }
            PipX[i] = 1300;
            PipDownY[i] = 0;
            PipUpY[i] = 0;
        }
    }
}

int BirdX = 100;
int BirdY = 200;

void GameStart() {
	//游戏开始
	mciSendString("open sound//bgm1.mp3 alias bgm", NULL, 0, NULL);
	mciSendString("play bgm from 0", NULL, 0, NULL);
	printf("游戏正式开始了\n");
	char key;
	bool GamePause = false;
	bool GameOver = false;
	while(1) {
		if(!GamePause) {
			//缓冲图片
			BeginBatchDraw();
			putimage(0, 0, &BackImage);
			putimage(BirdX, BirdY, &BirdBackImage, NOTSRCERASE);
			putimage(BirdX, BirdY, &BirdImage, SRCINVERT);
			ShowPip();
			EndBatchDraw();
			BirdY += 3;
			if(BirdY >= 800) BirdY = 0;
		}
		Sleep(50);
		//游戏结束检测
		if (GameOver) break;
		//碰撞检测
		bool isPip = false;
		for (int i = 0; i < 4; i++) {
			if (PipX[i] > 100 && PipX[i] < 164) {
				isPip = true;
			}
		}
		if(isPip && abs(BirdY - PipUpY) < 20) GameOver = true;
		//小鸟跳跃，暂停
		if(kbhit()) {
			key = getch();
			if(key == 32) //32表示空格键
				BirdY -= 50;
			else if(key == 'p') {
				if(GamePause == false) GamePause = true;
				else if(GamePause == true) GamePause = false;
			}
		}
	}
}