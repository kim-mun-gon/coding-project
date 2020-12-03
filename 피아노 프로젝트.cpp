#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#pragma comment(lib, "Kernel32.lib")
#pragma warning(disable: 4996)

struct melody{    //����ü ���� 
	char name[20];  //�뷡 ������ ������ �迭 ���� 20�� 
	char song[200]; //���踦 ������ �迭 ���� 200�� 
	char pwd[4]; // ��й�ȣ�� ������ �迭���� 4�� 
};

void music(char *); // �ǾƳ� �Լ� ���� 

int main(void)  //���� �Լ� ���� 
{
	struct melody a[3] = {}; //����ü ����. 
	int tones[] = {262, 294, 330, 349, 392, 440, 494, 523}; // ���� �� ���ļ� �迭 ���� 
	int select, num, sing; //�޴� ���� ���� 
	char input[200]; //���踦 �Է� ���� �迭 200�� ���� 
	char PD[4]; //��й�ȣ 4���� ���� 
	int cnt, m; // �ݺ� ���� 
	 
	printf("===�ǾƳ� ���α׷�===\n\n");
	printf("++++�Ѱ�� �ִ� ���� 100��++++\n");
	printf("++++���̸� �Է�++++\n");
	printf("++++Example : �̷������̹̹� ++++\n"); //�޴��� ��� 
	
	while(1)
	{
		printf("===============\n");
		printf("����� �� ���\n"); //����� �� ��� ��� 
		for(int j = 0; j < 3; j++) //����� �� ����� 3�� ��� 
		{
			if(a[j].name[0] == 0) //�迭�� ����� ���� ���ٸ� 
			{
				printf("%d. ����\n", j+1); // ������ ��� 
			}
			else
				printf("%d. %s\n", j + 1, a[j].name); // ����� �뷡 ������ ��� 
		}
		printf("\n");
		printf("�޴�\n");
		printf("1. �� �Է�\n");
		printf("2. �� ���\n");
		printf("3. �� ����\n\n");
		printf("�޴� ���� : ");
		
		scanf("%d", &select); //�޴� ���� �Է� 
		switch(select) //�޴� ���� ���ǹ� 
		{
			case 1:
			printf("================\n");
			printf("����� �� ���\n"); //����� �� ��� ��� 
			for(int j = 0; j < 3; j++)
			{
				if(a[j].name[0] == 0)
				{
					printf("%d. ����\n", j+1);
				}
				else
					printf("%d. %s\n", j+1, a[j].name);
			}
			printf("===================\n\n"); 
			printf("������� ���� : ");  //�뷡�� ������ ���� �����Ѵ� 
			scanf("%d", &num);			//�뷡�� ������ ��ȣ�� �Է¹޴´� 
			memset(a[num - 1].song, 0, 200); //�Է� �޴� ��ȣ -1 �迭�� ���踦 �ʱ�ȭ �Ѵ�.   
			printf("�� �� : ");
			scanf("%s", a[num - 1].name); //������ �뷡 �̸��� �Է¹޴´� 
			printf("��й�ȣ : ");
			scanf("%s", &a[num - 1].pwd); //��й�ȣ�� �Է� �޴´� 
			printf("�Է� ����Ű : x\n\n");
			printf("------------------------------------------------\n");
			printf("\n     �����ϰ� ���� ���̸��� �Է��ϼ���\n");
			printf("\n----------------------------------------------\n");
			
			for(int i = 0; i < 200; i++) //���踦 �Է¹޾� �ݺ� 
			{
				input[i] = getch(); // ���� �ϳ��� �Է� �޴´� 
				if(input[i] == '1')
				{
					printf("��"); //1�� ������ ���� ������ �� �Ҹ��� ����. 
					Beep(tones[0], 125);
				}
				else if(input[i] == '2')
				{
					printf("��");
					Beep(tones[1], 125);
				}
				else if(input[i] == '3')
				{
					printf("��");
					Beep(tones[2], 125);
				}
				else if(input[i] == '4')
				{
					printf("��");
					Beep(tones[3], 125);
				}
				else if(input[i] == '5')
				{
					printf("��");
					Beep(tones[4], 125);
				}
				else if(input[i] == '6')
				{
					printf("��");
					Beep(tones[5], 125);
				}
				else if(input[i] == '7')
				{
					printf("��");
					Beep(tones[6], 125);
				}
				else if(input[i] == '8')
				{
					printf("��#");
					Beep(tones[7], 125);
				}
				else if(input[i] == 'x')
				{
					printf("x"); //x�� ������ x�� ��µǰ� �ݺ����� ����������. 
					break;
				}
				a[num - 1].song[i] = input[i]; //����ü �迭�� �Է� �� �͵��� �����Ѵ�. 
			}
			break;
			
			case 2:
			printf("===========\n");
			printf("����� �� ���\n"); //����� �� ����� ����Ѵ�. 
			for(int j = 0; j < 3; j++) //3�� �ݺ��Ѵ�. ����� �� �ִ� ���� 3���̱� �����̴� 
			{
				if(a[j].name[0] == 0) //�ƹ��͵� ������� ���� ��쿡�� ������ ��� 
				{
					printf("%d. ����\n", j + 1);
				}
				else
				{
					printf("%d. %s\n", j + 1, a[j].name); //���𰡰� ����� �ִ� ��쿡�� �� �迭�� ����� �̸��� ����Ѵ�. 
				}
			}
			printf("=============\n\n");
			printf("�� ��ȣ ���� : ");
			scanf("%d", &sing); //�� ��ȣ�� �Է¹޴´�. 
			if(a[sing - 1].name[0] == NULL)
			{
				printf("�����Ͻ� ���� ����� ���� �����ϴ�.\n");
			}
			else
			{
				printf("��й�ȣ �Է� : ");
				scanf("%s", &PD);
				if(strcmp(a[sing - 1].pwd, PD) == 0) //��й�ȣ�� ������ �������� �Ǻ� 
				{
					printf("�ݺ� Ƚ���� �Է��ϼ��� : "); //��й�ȣ�� �´ٸ� �ݺ�Ƚ���� �Է¹޴´�. 
					scanf("%d", &cnt);
					for(int i = 0; i < cnt; i++)
					{
						printf("��%dȸ �ݺ��� %d��°\n", cnt, i+1); //�ݺ�Ƚ���� ����Ѵ�. 
						music(a[sing - 1].song);
						printf("\n");
					} 
				}
				else
				{
					printf("��й�ȣ �Է� ����\n"); //��й�ȣ�� Ʋ����� ���� �޼��� ��� 
				} 
			}
			break;
			
			case 3:
			printf("============\n");
			printf("����� �� ���\n");
			for(int j = 0; j < 3; j++)
			{
				if(a[j].name[0] == 0)
				{
					printf("%d. ����\n", j + 1);
				}
				else
					printf("%d %s\n", j + 1, a[j].name);
			}
			printf("������ ���� �����ϼ��� : ");
			scanf("%d", &m);
			
			if(a[m - 1].name[0] == NULL)
			{
				printf("�����ϽŰ��� ����� ���� �����ϴ�.\n");
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
			printf("���� �ʱ�ȭ �Ǿ����ϴ�.\n");
			break; 
		}
	}
	return 0;
}

void music(char *input) //�ǾƳ� ���� �Լ� 
{
	int tones[] = {262, 294, 330, 349, 392, 440, 494, 523};
	for(int i = 0; i < 200; i++)
	{
		if(input[i] == '1') //1�� �Է¹����� ���� ����ϰ� �׿� �´� �Ҹ��� ��� 
		{
			printf("��");
			Beep(tones[0], 350);
		}
		else if(input[i] == '2')
		{
			printf("��");
			Beep(tones[1], 350);
		}
		else if(input[i] == '3')
		{
			printf("��");
			Beep(tones[2], 350);
		}
		else if(input[i] == '4')
		{
			printf("��");
			Beep(tones[3], 350);
		}
		else if(input[i] == '5')
		{
			printf("��");
			Beep(tones[4], 350);
		}
		else if(input[i] == '6')
		{
			printf("��");
			Beep(tones[5], 350);
		}
		else if(input[i] == '7')
		{
			printf("��");
			Beep(tones[6], 350);
		}
		else if(input[i] == '8')
		{
			printf("��#");
			Beep(tones[7], 350);
		}
	}
}
