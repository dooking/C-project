#include <conio.h> 
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int num, bet, more, a;
int cash = 1000000;
int win = 0;
int lose = 0;
int com[3] = { 101,113,119 };

void mystate();
void rsp();
void end();

int main()
{
	while (1)
	{
		printf("---------------------------\n");
		printf("       1. My state\n");
		printf("       2. RSP\n");
		printf("       3. End\n");
		printf("---------------------------\n");
		printf("Enter the number: ");
		scanf_s("%d", &num);
		system("cls");
			
		if (num == 1)
			mystate();
		if (num == 2)
			rsp();
		if (num == 3)
		{
			end();
			break;
		}
	}
}

void mystate()
{
	printf("---------------------------\n");
	printf("       User's State\n");
	printf("       Cash: %d\n", cash);
	printf("       win: %d\n", win);
	printf("       lose: %d\n", lose);
	printf("---------------------------\n");
	printf("please enter any key to return!");
	_getch();
	system("cls");
}
void rsp()
{
	printf("---------------------------\n");
	printf("    Rock Scissors Paper\n");
	printf("---------------------------\n");
	printf("    Cash: %d\n", cash);
	printf("    How much do you want to bet?\n");
	printf("    : ");
	scanf_s("%d", &bet);
	if (cash < bet)
	{
		printf("    돈 있는만큼만 걸어요\n");
		printf("    How much do you want to bet?\n");
		printf("    : ");
		scanf_s("%d", &bet);
	}
	if (bet < 0)
	{
		printf("    베팅은 0원 이상으로 걸어요\n");
		printf("    How much do you want to bet?\n");
		printf("    : ");
		scanf_s("%d", &bet);
	}

	printf("    Ok!\n");
	Sleep(2000);
	printf("    then Now start!\n");
	Sleep(2000);
	system("cls");
	while (1)
	{
		printf("---------------------------\n");
		printf("    Rock Scissors Paper\n\n");
		printf("    Start?\n");
		printf("---------------------------\n");
		_getch();
		printf("    3...\n");
		Sleep(1000);
		printf("    2..\n");
		Sleep(1000);
		printf("    1.\n");
		Sleep(1000);
		printf("    Rock, ");
		Sleep(500);
		printf("Scissors, ");
		Sleep(500);
		printf("Paper!\n\n");
		Sleep(500);

		if (_kbhit())
		{
			char player = _getch();
			if (player == 113) // Q=113 <주먹>
			{
				a = com[rand() % 3];
				switch (a)
				{
				case 101:
					printf("    User: Rock\tCom: Paper\n");
					printf("    Lose..\n");
					printf("    -%d\n\n", bet);
					cash -= bet;
					lose++;
					printf("    Cash: %d\n\n", cash);
					if (cash <= 0)
					{
						Sleep(1000);
						system("cls");
						printf("돈이 0원입니다\n");
						printf("돈이 부족해서 게임을 종료합니다");
						exit(0);
					}
					printf("    One more?\n");
					printf("    1.yes\n");
					printf("    2.no\n");
					scanf_s("%d", &more);
					if (more == 1)
					{
						printf("    Restart");
						system("cls");
						continue;
					}
					else if (more == 2)
					{
						system("cls");
						return;
					}

				case 113:
					printf("    User: Rock\tCom: Rock\n");
					printf("    Draw!!\n\n\n");
					printf("    Restart\n\n\n");
					continue;

				case 119:
					printf("    User: Rock\tCom: Scissors\n");
					printf("    Win ^^\n");
					printf("    +%d\n\n", bet);
					cash += bet;
					win++;
					if (cash <= 0)
					{
						Sleep(1000);
						system("cls");
						printf("돈이 0원입니다\n");
						printf("돈이 부족해서 게임을 종료합니다");
						exit(0);
					}
					printf("    Cash: %d\n", cash);
					printf("    One more?\n");
					printf("    1.yes\n");
					printf("    2.no\n");
					scanf_s("%d", &more);
					if (more == 1)
					{
						printf("\n\n");
						printf("    Restart");
						system("cls");
						continue;
					}
					else if (more == 2)
					{
						system("cls");
						return;
					}
				}
			}
			if (player == 119) // W=119 <가위>
			{
				a = com[rand() % 3];
				switch (a)
				{
				case 101:
					printf("    User: Scissors\tCom: Paper\n");
					printf("    Win ^^\n");
					printf("    +%d\n\n", bet);
					cash += bet;
					win++;
					if (cash <= 0)
					{
						Sleep(1000);
						system("cls");
						printf("돈이 0원입니다\n");
						printf("돈이 부족해서 게임을 종료합니다");
						exit(0);
					}
					printf("    Cash: %d\n", cash);
					printf("    One more?\n");
					printf("    1.yes\n");
					printf("    2.no\n");
					scanf_s("%d", &more);
					if (more == 1)
					{
						printf("\n\n");
						printf("    Restart");
						system("cls");
						continue;
					}
					else if (more == 2)
					{
						system("cls");
						return;
					}
				case 113:
					printf("    User: Scissors\tCom: Rock\n");
					printf("    Lose..\n");
					printf("    -%d\n\n", bet);
					cash -= bet;
					lose++;
					if (cash <= 0)
					{
						Sleep(1000);
						system("cls");
						printf("돈이 0원입니다\n");
						printf("돈이 부족해서 게임을 종료합니다");
						exit(0);
					}
					printf("    Cash: %d\n\n", cash);
					printf("    One more?\n");
					printf("    1.yes\n");
					printf("    2.no\n");
					scanf_s("%d", &more);
					if (more == 1)
					{
						printf("    Restart");
						system("cls");
						continue;
					}
					else if (more == 2)
					{
						system("cls");
						return;
					}
				case 119:
					printf("    User: Scissors\tCom: Scissors\n");
					printf("    Draw!!\n\n\n");
					printf("    Restart\n\n\n");
					continue;
				}
			}
			if (player == 101)  // E=101 <보자기>
			{
				a = com[rand() % 3];
				switch (a)
				{
				case 101:
					printf("    User: Paper\tCom: Paper\n");
					printf("    Draw!!\n\n\n");
					printf("    Restart\n\n\n");
					continue;
				case 113:
					printf("    User: Paper\tCom: Rock\n");
					printf("    Win ^^\n");
					printf("    +%d\n\n", bet);
					cash += bet;
					win++;
					if (cash <= 0)
					{
						Sleep(1000);
						system("cls");
						printf("돈이 0원입니다\n");
						printf("돈이 부족해서 게임을 종료합니다");
						exit(0);
					}
					printf("    Cash: %d\n", cash);
					printf("    One more?\n");
					printf("    1.yes\n");
					printf("    2.no\n");
					scanf_s("%d", &more);
					if (more == 1)
					{
						printf("\n\n");
						printf("    Restart");
						system("cls");
						continue;
					}
					else if (more == 2)
					{
						system("cls");
						return;
					}
				case 119:
					printf("    User: Paper\tCom: Scissors\n");
					printf("    Lose..\n");
					printf("    -%d\n\n", bet);
					cash -= bet;
					lose++;
					if (cash <= 0)
					{
						Sleep(1000);
						system("cls");
						printf("돈이 0원입니다\n");
						printf("돈이 부족해서 게임을 종료합니다");
						exit(0);
					}
					printf("    Cash: %d\n\n", cash);
					printf("    One more?\n");
					printf("    1.yes\n");
					printf("    2.no\n");
					scanf_s("%d", &more);
					if (more == 1)
					{
						printf("    Restart");
						system("cls");
						continue;
					}
					else if (more == 2)
					{
						system("cls");
						return;
					}
				}
			}
		}

		else
		{
			printf("    Do not Enter any key\n");
			printf("    Lose..\n");
			printf("    -%d\n\n", bet);
			cash -= bet;
			lose++;
			if (cash <= 0)
			{
				Sleep(1000);
				system("cls");
				printf("돈이 0원입니다\n");
				printf("돈이 부족해서 게임을 종료합니다");
				exit(0);
			}
			printf("    Cash: %d\n\n", cash);
			printf("    One more?\n");
			printf("    1.yes\n");
			printf("    2.no\n");
			scanf_s("%d", &more);
			if (more == 1)
			{
				printf("    Restart");
				system("cls");
				continue;
			}
			else if (more == 2)
			{
				system("cls");
				return;
			}
		} //if
	
	} // while
} //void

void end()
{
	system("cls");
	printf("bye");
	return 0;
}