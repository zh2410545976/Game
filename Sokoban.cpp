#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define ROW 9
#define COL 11

int map[ROW][COL] =
{
	{0,1,1,1,1,1,1,1,1,1,0},//空白(0)，墙(1)，目的地(3)，箱子(4)，人（5)
	{0,1,0,0,0,1,0,0,0,1,0},
	{0,1,0,4,4,4,4,4,0,1,0},
	{0,1,0,4,0,4,0,4,0,1,1},
	{0,1,0,0,0,5,0,0,4,0,1},
	{1,1,0,1,1,1,1,0,4,0,1},
	{1,0,3,3,3,3,3,1,0,0,1},
	{1,0,3,3,3,3,3,0,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,0},
};

void Drawmap()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			switch (map[i][j])
			{
			case 0:		//空白
				printf("  ");
				break;
			case 1:		//墙
				printf("■");
				break;
			case 3:		//目的地
				printf("○");
				break;
			case 4:		//箱子
				printf("□");
				break;
			case 5:		//人
				printf("♀");
				break;
			case 7:			//箱子在目的地中
				printf("★");
				break;
			case 8:			//人在目的地中
				printf("●");
				break;
			}
		}
		printf("\n");
	}
}
void BeginGame()
{
	//接受键盘
	int r, c;//人的行列
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] == 5||map[i][j]==8)//找到人的位置
			{
				r = i;
				c = j;
			}
		}
	}
	//===============接受键盘的输入===============
	int ch;
	ch = _getch();
	switch (ch)
	{
	case'W':		//上
	case'w':
	case 72:
		if (map[r-1][c] == 0 || map[r-1][c] == 3)//如果人前面时空地0或目的地3
		{
			map[r][c] -= 5;//人的ID有肯能是5或8
			map[r-1][c] += 5;
		}
		else if (map[r-1][c] == 4 || map[r-1][c] == 7)//人的前面是箱子或目的地里的箱子
		{
			if (map[r-2][c] == 0 || map[r-2][c] == 3)//如果箱子的前面是空地或目的地
			{
				map[r-2][c] += 4;//变成箱子4或箱子在目的地7
				map[r-1][c] += 1;//变成人5和人在目的地8
				map[r][c] -= 5;//变成空地0或目的地3
			}
		}
		break;
	case'S':		//下
	case's':
	case 80:
		if (map[r + 1][c] == 0 || map[r +1][c] == 3)//如果人前面时空地0或目的地3
		{
			map[r][c] -= 5;//人的ID有肯能是5或8
			map[r +1][c] += 5;
		}
		else if (map[r + 1][c] == 4 || map[r + 1][c] == 7)//人的前面是箱子或目的地里的箱子
		{
			if (map[r + 2][c] == 0 || map[r + 2][c] == 3)//如果箱子的前面是空地或目的地
			{
				map[r + 2][c] += 4;
				map[r + 1][c] += 1;
				map[r][c] -= 5;
			}
		}
		break;
	case'A':		//左
	case'a':
	case 75:
		if (map[r][c - 1] == 0 || map[r][c - 1] == 3)//如果人前面时空地0或目的地3
		{
			map[r][c] -= 5;//人的ID有肯能是5或8
			map[r][c-1] += 5;
		}
		else if (map[r][c - 1] == 4 || map[r][c-1] == 7)//人的前面是箱子或目的地里的箱子
		{
			if (map[r][c - 2] == 0 || map[r][c - 2] == 3)//如果箱子的前面是空地或目的地
			{
				map[r][c - 2] += 4;
				map[r][c - 1] += 1;
				map[r][c] -= 5;
			}
		}
		break;
	case'D':		//右
	case'd':
	case 77:
		if (map[r][c + 1] == 0 || map[r][c + 1] == 3)//如果人前面时空地0或目的地3
		{
			map[r][c] -= 5;//人的ID有肯能是5或8
			map[r][c + 1] += 5;
		}
		else if (map[r][c + 1] == 4 || map[r][c + 1] == 7)//人的前面是箱子或目的地里的箱子
		{
			if (map[r][c + 2] == 0 || map[r][c + 2] == 3)//如果箱子的前面是空地或目的地
			{
				map[r][c + 2] += 4;
				map[r][c + 1] += 1;
				map[r][c] -= 5;
			}
		}
		
		break;
	default:		//所有其他情况
		break;
	}
}
int main()
{	
	while (1)
	{	
		system("cls");//清屏
		Drawmap();
		BeginGame();
	}
	
	return 0;
}
