#include <windows.h>  
#include <stdio.h>  
#include <WinUser.h>
#include<time.h>

const int numBullet = 50,numEnemy=10,numT=10;

struct Plane {
	short int posX = 0;
	short int posY = 0;
	int kind = 1;
	int t = 0;
	int Tmax = 3;
	COORD BulletArray[numT][numBullet];
};

Plane Enemy[numEnemy];

void HideCursor()//隐藏控制台的光标 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int main(void)
{
	HideCursor();
	// 获取标准输入输出设备句柄  
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	INPUT_RECORD	mouseRec;
	DWORD			res;
	COORD			crPos, crHome, crEnemy ,Zero= { 0, 0 };
	SetConsoleTitle("ThouhouCProject v0.1");
	printf("[Cursor Position] X: %2lu  Y: %2lu\n", 0, 0);	// 初始状态

	WORD att1 = FOREGROUND_RED, att2 = FOREGROUND_BLUE;


	int i, x1, y1;
	long start;
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	//	x1 = rand() % 20 + 1;
	//	y1 = rand() % 20 + 1;

	Enemy[0].BulletArray[0][0] = { -1,-1 };
	Enemy[0].BulletArray[0][1] = { -1,0 };
	Enemy[0].BulletArray[0][2] = { -1,+1 };
	Enemy[0].BulletArray[0][3] = { 0,-1 };
	Enemy[0].BulletArray[0][4] = { 0,+1 };
	Enemy[0].BulletArray[0][5] = { +1,-1 };
	Enemy[0].BulletArray[0][6] = { +1,0 };
	Enemy[0].BulletArray[0][7] = { +1,1 };

	Enemy[0].BulletArray[1][0] = { -2,-2 };
	Enemy[0].BulletArray[1][1] = { -2,0 };
	Enemy[0].BulletArray[1][2] = { -2,+2 };
	Enemy[0].BulletArray[1][3] = { 0,-2 };
	Enemy[0].BulletArray[1][4] = { 0,+2 };
	Enemy[0].BulletArray[1][5] = { +2,-2 };
	Enemy[0].BulletArray[1][6] = { +2,0 };
	Enemy[0].BulletArray[1][7] = { +2,2 };

	Enemy[0].BulletArray[2][0] = { -3,-3 };
	Enemy[0].BulletArray[2][1] = { -3,0 };
	Enemy[0].BulletArray[2][2] = { -3,+3 };
	Enemy[0].BulletArray[2][3] = { 0,-3 };
	Enemy[0].BulletArray[2][4] = { 0,+3 };
	Enemy[0].BulletArray[2][5] = { +3,-3 };
	Enemy[0].BulletArray[2][6] = { +3,0 };
	Enemy[0].BulletArray[2][7] = { +3,3 };





	while (1) {
//		start = clock();
//		while (clock() - start <= 1000);延时
		x1 = 60;
		y1 = 15;
		Enemy[0].posX = x1;
		Enemy[0].posY = y1;

//		DWORD dwBytesWritten;

		int n=0,i = 0,j=0;
		while ((Enemy[n].posX != 0) || (Enemy[n].posY != 0)) {

			for (i = 0; i < Enemy[n].Tmax; i++) {
				
				FillConsoleOutputAttribute(hOut, att1, 1, { Enemy[0].posX, Enemy[0].posY }, &res);
				FillConsoleOutputCharacter(hOut, '|', 1, { Enemy[0].posX, Enemy[0].posY }, &res);
				//set敌机

				while (!((Enemy[n].BulletArray[i][j].Y == 0)&& (Enemy[n].BulletArray[i][j].X == 0))) {
					FillConsoleOutputAttribute(hOut, att2, 1, { Enemy[0].posX+ Enemy[n].BulletArray[i][j].X, Enemy[0].posY + Enemy[n].BulletArray[i][j].Y }, &res);
					FillConsoleOutputCharacter(hOut, '*', 1,  { Enemy[0].posX + Enemy[n].BulletArray[i][j].X, Enemy[0].posY + Enemy[n].BulletArray[i][j].Y }, &res);
					  j++;
				}
				j = 0;
				start = clock();
				while (clock() - start <= 2000);
			//	if (i>0)	
				while (!((Enemy[n].BulletArray[i][j].Y == 0) && (Enemy[n].BulletArray[i][j].X == 0))) {
					FillConsoleOutputCharacter(hOut, ' ', 1, { Enemy[n].posX + Enemy[n].BulletArray[i][j].X, Enemy[n].posY + Enemy[n].BulletArray[i][j].Y }, &res);//清除上一次弹幕
					j++;
				}
				j = 0;
				FillConsoleOutputCharacter(hOut, ' ', 1, { Enemy[0].posX, Enemy[0].posY }, &res);//清除上一次敌机
				int direct = rand() % 9;
				switch (direct) {
					case 1: Enemy[0].posX--; Enemy[0].posY--; break;
					case 2: Enemy[0].posX--;  break;
					case 3: Enemy[0].posX--; Enemy[0].posY++; break;
					case 4:  Enemy[0].posY--; break;
					case 5: Enemy[0].posX++; break;
					case 6: Enemy[0].posX++; Enemy[0].posY--; break;
					case 7: Enemy[0].posX++; break;
					case 8: Enemy[0].posX++; Enemy[0].posY++; break;
				default:
					break;
				}

			}
			n++;
		}

	}
	system("pause");
}
