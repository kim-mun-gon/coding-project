#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#pragma comment(lib, "Kernel32.lib")
#pragma warning(disable: 4996)

struct melody{    //구조체 선언 
	char name[20];  //노래 제목을 저장할 배열 공간 20개 
	char song[200]; //음계를 저장할 배열 공간 200개 
	char pwd[4]; // 비밀번호를 저장할 배열공간 4개 
};

void music(char *); // 피아노 함수 선언 

int main(void)  //메인 함수 선언 
{
	struct melody a[3] = {}; //구조체 선언. 
	int tones[] = {262, 294, 330, 349, 392, 440, 494, 523}; // 음계 별 주파수 배열 선언 
	int select, num, sing; //메뉴 선택 변수 
	char input[200]; //음계를 입력 받을 배열 200개 선언 
	char PD[4]; //비밀번호 4가지 선언 
	int cnt, m; // 반복 변수 
	 
	printf("===피아노 프로그램===\n\n");
	printf("++++한곡당 최대 음수 100개++++\n");
	printf("++++계이름 입력++++\n");
	printf("++++Example : 미레도레미미미 ++++\n"); //메뉴얼 출력 
	
	while(1)
	{
		printf("===============\n");
		printf("저장된 곡 목록\n"); //저장된 곡 목록 출력 
		for(int j = 0; j < 3; j++) //저장된 곡 목록을 3번 출력 
		{
			if(a[j].name[0] == 0) //배열에 저장된 것이 없다면 
			{
				printf("%d. 없음\n", j+1); // 없음을 출력 
			}
			else
				printf("%d. %s\n", j + 1, a[j].name); // 저장된 노래 제목을 출력 
		}
		printf("\n");
		printf("메뉴\n");
		printf("1. 곡 입력\n");
		printf("2. 곡 듣기\n");
		printf("3. 곡 삭제\n\n");
		printf("메뉴 선택 : ");
		
		scanf("%d", &select); //메뉴 선택 입력 
		switch(select) //메뉴 선택 조건문 
		{
			case 1:
			printf("================\n");
			printf("저장된 곡 목록\n"); //저장된 곡 목록 출력 
			for(int j = 0; j < 3; j++)
			{
				if(a[j].name[0] == 0)
				{
					printf("%d. 없음\n", j+1);
				}
				else
					printf("%d. %s\n", j+1, a[j].name);
			}
			printf("===================\n\n"); 
			printf("저장번지 선택 : ");  //노래를 저장할 곳을 선택한다 
			scanf("%d", &num);			//노래를 저장할 번호를 입력받는다 
			memset(a[num - 1].song, 0, 200); //입력 받는 번호 -1 배열의 음계를 초기화 한다.   
			printf("곡 명 : ");
			scanf("%s", a[num - 1].name); //저장할 노래 이름을 입력받는다 
			printf("비밀번호 : ");
			scanf("%s", &a[num - 1].pwd); //비밀번호를 입력 받는다 
			printf("입력 종료키 : x\n\n");
			printf("------------------------------------------------\n");
			printf("\n     연주하고 싶은 계이름을 입력하세요\n");
			printf("\n----------------------------------------------\n");
			
			for(int i = 0; i < 200; i++) //음계를 입력받아 반복 
			{
				input[i] = getch(); // 문자 하나를 입력 받는다 
				if(input[i] == '1')
				{
					printf("도"); //1를 누르면 도가 나오고 도 소리가 난다. 
					Beep(tones[0], 125);
				}
				else if(input[i] == '2')
				{
					printf("레");
					Beep(tones[1], 125);
				}
				else if(input[i] == '3')
				{
					printf("미");
					Beep(tones[2], 125);
				}
				else if(input[i] == '4')
				{
					printf("파");
					Beep(tones[3], 125);
				}
				else if(input[i] == '5')
				{
					printf("솔");
					Beep(tones[4], 125);
				}
				else if(input[i] == '6')
				{
					printf("라");
					Beep(tones[5], 125);
				}
				else if(input[i] == '7')
				{
					printf("시");
					Beep(tones[6], 125);
				}
				else if(input[i] == '8')
				{
					printf("도#");
					Beep(tones[7], 125);
				}
				else if(input[i] == 'x')
				{
					printf("x"); //x를 누르면 x가 출력되거 반복문을 빠져나간다. 
					break;
				}
				a[num - 1].song[i] = input[i]; //구조체 배열에 입력 된 것들을 저장한다. 
			}
			break;
			
			case 2:
			printf("===========\n");
			printf("저장된 곡 목록\n"); //저장된 곡 목록을 출력한다. 
			for(int j = 0; j < 3; j++) //3번 반복한다. 저장될 수 있는 곡이 3곡이기 때문이다 
			{
				if(a[j].name[0] == 0) //아무것도 저장되지 않은 경우에는 없음을 출력 
				{
					printf("%d. 없음\n", j + 1);
				}
				else
				{
					printf("%d. %s\n", j + 1, a[j].name); //무언가가 저장되 있는 경우에는 그 배열에 저장된 이름을 출력한다. 
				}
			}
			printf("=============\n\n");
			printf("곡 번호 선택 : ");
			scanf("%d", &sing); //곡 번호를 입력받는다. 
			if(a[sing - 1].name[0] == NULL)
			{
				printf("선택하신 곳에 저장된 곡이 없습니다.\n");
			}
			else
			{
				printf("비밀번호 입력 : ");
				scanf("%s", &PD);
				if(strcmp(a[sing - 1].pwd, PD) == 0) //비밀번호가 참인지 거짓인지 판별 
				{
					printf("반복 횟수를 입력하세요 : "); //비밀번호가 맞다면 반복횟수를 입력받는다. 
					scanf("%d", &cnt);
					for(int i = 0; i < cnt; i++)
					{
						printf("총%d회 반복중 %d번째\n", cnt, i+1); //반복횟수를 출력한다. 
						music(a[sing - 1].song);
						printf("\n");
					} 
				}
				else
				{
					printf("비밀번호 입력 오류\n"); //비밀번호가 틀릴경우 에러 메세지 출력 
				} 
			}
			break;
			
			case 3:
			printf("============\n");
			printf("저장된 곡 목록\n");
			for(int j = 0; j < 3; j++)
			{
				if(a[j].name[0] == 0)
				{
					printf("%d. 없음\n", j + 1);
				}
				else
					printf("%d %s\n", j + 1, a[j].name);
			}
			printf("삭제할 곡을 선택하세요 : ");
			scanf("%d", &m);
			
			if(a[m - 1].name[0] == NULL)
			{
				printf("선택하신곳에 저장된 곡이 없습니다.\n");
				break;
			}
			
			if(a[m-1].song != 0)
			{
				for(int n = 0; n < 200; n++)
				{
					a[m-1].song[n] = NULL;
				}
				for(int n = 0; n < 20; n++)
				{
					a[m-1].name[n] = NULL;
				}
				for(int n = 0; n < 4; n++)
				{
					a[m-1].pwd[n] = NULL;
				}
				
			}
			printf("곡이 초기화 되었습니다.\n");
			break; 
		}
	}
	return 0;
}

void music(char *input) //피아노 연주 함수 
{
	int tones[] = {262, 294, 330, 349, 392, 440, 494, 523};
	for(int i = 0; i < 200; i++)
	{
		if(input[i] == '1') //1을 입력받으면 도를 출력하고 그에 맞는 소리를 출력 
		{
			printf("도");
			Beep(tones[0], 350);
		}
		else if(input[i] == '2')
		{
			printf("레");
			Beep(tones[1], 350);
		}
		else if(input[i] == '3')
		{
			printf("미");
			Beep(tones[2], 350);
		}
		else if(input[i] == '4')
		{
			printf("파");
			Beep(tones[3], 350);
		}
		else if(input[i] == '5')
		{
			printf("솔");
			Beep(tones[4], 350);
		}
		else if(input[i] == '6')
		{
			printf("라");
			Beep(tones[5], 350);
		}
		else if(input[i] == '7')
		{
			printf("시");
			Beep(tones[6], 350);
		}
		else if(input[i] == '8')
		{
			printf("도#");
			Beep(tones[7], 350);
		}
	}
}
