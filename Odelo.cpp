#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>             
#include <stdlib.h>
#include <time.h>


int place(int, int, int, int(*)[21]);
int Odello();


int arr[21][21] = { 0 };
char ch;
int turn = 0;
int x = 8, y = 8;
int i, j;
int num;
int a = 1, b = 1, c = 0;
int b_n = 0;
int w_n = 0;

clock_t  start, mid, end;
int place(int, int, int, int(*)[21]);

void main() {
	Odello();
}



int Odello() {
	//�����迭arr�� �߽����� �ʱ�ȭ(�浹2�� �鵹2��)
	arr[10][10] = 1;
	arr[11][11] = 1;
	arr[10][11] = 2;
	arr[11][10] = 2;
	start = clock();
	while (1) {
		b_n = 0;
		w_n = 0;
		system("cls");
		//�ٵ��� ����(CMD�� ������ ���� ����� �޶��� �� ����)
		for (i = 0; i < 21; i++) {
			for (j = 0; j < 21; j++) {
				switch (arr[i][j]) {
				//�ٵ��� base
				case 0:
					printf(" ��");
					break;
				//�ڵ�����δ� ������������ cmdâ������ �Ͼ������ ���� case 1�� �鵹
				case 1:
					printf("��");
					b_n++;
					break;
				//�浹
				case 2:
					printf("��");
					w_n++;
					break;
				//�÷��̾ ���� �̵���ų �� ���� ��ġ�� �鵹 ���� �������
				case 3:
					printf("��");
					b_n++;
					break;
				//���� ��ġ�� �浹 �������� ���
				case 4:
					printf("��");
					w_n++;
					break;
				//enter�� ������ �� ���� ��ġ�� �鵹�� �����ϱ� ���� case 5
				case 5:
					printf("��");
					b_n++;
					break;
				//enter�� ������ �� ���� ��ġ�� �浹�� �����ϱ� ���� case 6
				case 6:
					printf("��");
					w_n++;
					break;

				}
			}
			printf("\n");
		}
		printf("\t �鵹 vs �浹\n");
		mid = clock();

		//���� �ڵ�� Ű�� ���� ������ ����ð��� �� -> Thread�� ���� ������ �ǽð����� �ð������� �ٲ�
		printf("\t  %d vs  %d\t%d�� ���", b_n, w_n, (int)((mid - start) / 1000));

		if (turn % 2 == 0)
			b_n--;
		else
			w_n--;

		if ((int)((mid - start) / 1000) > 10 * 30) { //�¸� ����1
			system("cls");
			printf("\t �浹 vs �鵹\n");
			printf("\t  %d vs  %d\n", b_n, w_n);
			if (b_n > w_n)
				printf("�浹 ��!\n");
			else
				printf("�鵹 ��!\n");
		}
		if (b_n > 70) {                                          // �¸� ����2
			system("cls");
			printf("�浹 �¸�!");
		}
		else if (w_n > 70) {
			system("cls");
			printf("�鵹 �¸�!");
		}


		ch = getch();

		if (turn % 2 == 0) {	//ù ������ �鵹��
			switch (ch) {
			case 'a':
				if (x == 0)
					break;
				switch (arr[y][x - 1]) {
				//���� �̵� ���� �� ���ʿ� ���� ���ٸ� �鵹��, �鵹�� �ִٸ� ��, �浹�� �ִٸ� �ٷ� ǥ��
				case 0:
					arr[y][x - 1] = 1;
					break;
				case 1:
					arr[y][x - 1] = 3;
					break;
				case 2:
					arr[y][x - 1] = 4;
					break;
				}
				//���ʿ� ���� ó���� ������ ���� �ִ��ڸ� ó���� ���־����
				/*
					case 1 ���� �����ִ� �ڸ��� �鵹�� �־��ٸ� ���� �̵��Ѱ��̹Ƿ� �ƹ��͵� ���� ���·� ����
					case 2 ���� �ִ� �ڸ��� �浹�� �ִٸ� �ƹ��͵� ���� ���·� ����� ���ε� �̺κ��� ���� ������(�浹���϶� ó�����ָ� ��)
					case 3 ���� �ִ��ڸ��� �鵹���� ���� �ִٴ� ǥ�� : �� �̰��� ��� �鵹�� �ٲ���
					case 4 ���� �ִ��ڸ��� �浹���� ���� �ִٴ� ǥ�� :	�� �̰��� ��� �浹�� �ٲ���

					�̷��� ó���� �鵹�� �浹 ���� wasdó���� ����
				*/
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				x--;
				num = 1;
				break;
			case 'd':
				if (x == 20)
					break;

				switch (arr[y][x + 1]) {
				case 0:
					arr[y][x + 1] = 1;
					break;
				case 1:
					arr[y][x + 1] = 3;
					break;
				case 2:
					arr[y][x + 1] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				x++;
				num = 2;
				break;
			case 'w':
				if (y == 0)
					break;
				switch (arr[y - 1][x]) {
				case 0:
					arr[y - 1][x] = 1;
					break;
				case 1:
					arr[y - 1][x] = 3;
					break;
				case 2:
					arr[y - 1][x] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				num = 3;
				y--;
				break;
			case 's':
				if (y == 20)
					break;
				switch (arr[y + 1][x]) {
				case 0:
					arr[y + 1][x] = 1;
					break;
				case 1:
					arr[y + 1][x] = 3;
					break;
				case 2:
					arr[y + 1][x] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				num = 4;
				y++;
				break;
			case 13: //������ ������� �� �� ���̿� ���̰Բ� ����� ��
				if (arr[y][x] == 1) {
					if (place(x, y, turn, arr)) {
						//-------------------------------------------------------------------------------------
						//����
						while (x - a >= 0) {                        // ����//a�� 1���� �ϴϱ� a-1�� �ؾߵ�
							if (arr[y][x - a] == 1) {
								break;
							}
							else if (arr[y][x - a] == 2) {
								a++;
							}
							else {
								a = 1;
								break;
							}
						}
						for (; a > 1; a--)
							arr[y][x - (a - 1)] = 1;
						a = 1;
						//-------------------------------------------------------------------------------------
						//������
						while (x + a <= 20) {		// ����, a�� 1���� �ϴϱ� a-1�� �ؾߵ�
							if (arr[y][x + a] == 1) {
								break;
							}
							else if (arr[y][x + a] == 2) {
								a++;
							}
							else {
								a = 1;
								break;
							}
						}
						for (; a > 1; a--)
							arr[y][x + (a - 1)] = 1;
						a = 1;
						//-------------------------------------------------------------------------------------
						//�Ʒ�
						while (y + b <= 20) {
							if (arr[y + b][x] == 1) {
								break;
							}
							else if (arr[y + b][x] == 2) {
								b++;
							}
							else {
								b = 1;
								break;
							}
						}
						for (; b > 1; b--)
							arr[y + (b - 1)][x] = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//��
						while (y - b >= 0) {
							if (arr[y - b][x] == 1) {
								break;
							}
							else if (arr[y - b][x] == 2) {
								b++;
							}
							else {
								b = 1;
								break;
							}
						}
						for (; b > 1; b--)
							arr[y - (b - 1)][x] = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//1-7�� �밢��
						while (y + b <= 20) {
							if (arr[y + b][x - a] == 1) {
								break;
							}
							else if (arr[y + b][x - a] == 2) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y + (b - 1)][x - (a - 1)] = 1;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//7-1�� �밢��
						while (y - b >= 0) {
							if (arr[y - b][x + a] == 1) {
								break;
							}
							else if (arr[y - b][x + a] == 2) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y - (b - 1)][x + (a - 1)] = 1;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//11-5�� �밢��
						while (y + b <= 20) {
							if (arr[y + b][x + a] == 1) {
								break;
							}
							else if (arr[y + b][x + a] == 2) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y + (b - 1)][x + (a - 1)] = 1;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//5-11�� �밢��
						while (y - b >= 0) {
							if (arr[y - b][x - a] == 1) {
								break;
							}
							else if (arr[y - b][x - a] == 2) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y - (b - 1)][x - (a - 1)] = 1;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//turn++;
						arr[y][x] = 5;
						turn = 1;
					}
					break;
				}
			}
		}
		else {
			switch (ch) {
			case 'a':
				if (x == 0)
					break;
				switch (arr[y][x - 1]) {
				case 0:
					arr[y][x - 1] = 2;
					break;
				case 1:
					arr[y][x - 1] = 3;
					break;
				case 2:
					arr[y][x - 1] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				x--;
				num = 1;
				break;
			case 'd':
				if (x == 20)
					break;

				switch (arr[y][x + 1]) {
				case 0:
					arr[y][x + 1] = 2;
					break;
				case 1:
					arr[y][x + 1] = 3;
					break;
				case 2:
					arr[y][x + 1] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				x++;
				num = 2;
				break;
			case 'w':
				if (y == 0)
					break;
				switch (arr[y - 1][x]) {
				case 0:
					arr[y - 1][x] = 2;
					break;
				case 1:
					arr[y - 1][x] = 3;
					break;
				case 2:
					arr[y - 1][x] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				num = 3;
				y--;
				break;
			case 's':
				if (y == 20)
					break;
				switch (arr[y + 1][x]) {
				case 0:
					arr[y + 1][x] = 2;
					break;
				case 1:
					arr[y + 1][x] = 3;
					break;
				case 2:
					arr[y + 1][x] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				num = 4;
				y++;
				break;
			case 13:
				if (arr[y][x] == 2) {

					//enter�� ������ �� ���� ���� �� ���� �����ε� ���� �Ѿ���� ������ ���� ���� place�Լ��� ���� ���� ���� �� �ִ��� �˻���
					if (place(x, y, turn, arr)) {	
						//-------------------------------------------------------------------------------------
						//����
						while (x - a >= 0) {		//a�� 1���� �ϴϱ� a-1�� �ؾߵ�
							if (arr[y][x - a] == 2) {		//(�浹��) ���ʿ� �浹�� ������ ��������
								break;
							}
							else if (arr[y][x - a] == 1) {		//(�浹��) ���ʿ� �鵹�� ������ a�� ����
								a++;
							}
							else {
								a = 1;
								break;
							}
						}
						for (; a > 1; a--)		//������ a����ŭ �浹�� ������
							arr[y][x - (a - 1)] = 2;
						a = 1;
						//-------------------------------------------------------------------------------------
						//������
						while (x + a <= 20) {
							if (arr[y][x + a] == 2) {
								break;
							}
							else if (arr[y][x + a] == 1) {
								a++;
							}
							else {
								a = 1;
								break;
							}
						}
						for (; a > 1; a--)
							arr[y][x + (a - 1)] = 2;
						a = 1;
						//-------------------------------------------------------------------------------------
						//�Ʒ�
						while (y + b <= 20) {
							if (arr[y + b][x] == 2) {
								break;
							}
							else if (arr[y + b][x] == 1) {
								b++;
							}
							else {
								b = 1;
								break;
							}
						}
						for (; b > 1; b--)
							arr[y + (b - 1)][x] = 2;
						b = 1;
						//-------------------------------------------------------------------------------------
						//��
						while (y - b >= 0) {
							if (arr[y - b][x] == 2) {
								break;
							}
							else if (arr[y - b][x] == 1) {
								b++;
							}
							else {
								b = 1;
								break;
							}
						}
						for (; b > 1; b--)
							arr[y - (b - 1)][x] = 2;
						b = 1;
						//-------------------------------------------------------------------------------------
						//1-7�� �밢��
						while (y + b <= 20) {
							if (arr[y + b][x - a] == 2) {
								break;
							}
							else if (arr[y + b][x - a] == 1) {
								a++;
								b++;
							}
							else {
								b = 1;
								a = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y + (b - 1)][x - (a - 1)] = 2;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//7-1�� �밢��
						while (y - b >= 0) {
							if (arr[y - b][x + a] == 2) {
								break;
							}
							else if (arr[y - b][x + a] == 1) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y - (b - 1)][x + (a - 1)] = 2;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//11-5�� �밢��
						while (y + b <= 20) {
							if (arr[y + b][x + a] == 2) {
								break;
							}
							else if (arr[y + b][x + a] == 1) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y + (b - 1)][x + (a - 1)] = 2;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//5-11�� �밢��
						while (y - b >= 0) {
							if (arr[y - b][x - a] == 2) {
								break;
							}
							else if (arr[y - b][x - a] == 1) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y - (b - 1)][x - (a - 1)] = 2;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//turn++;
						arr[y][x] = 6;
						turn = 0;
					}
				}
				break;
			}
		}
	}
}


int place(int x, int y, int tern, int(*arr)[21]) {

	int a = 1;
	int b = 1;
	if (tern % 2 == 0) {
		//-------------------------------------------------------------------------------------
		//����
		while (x - a >= 0) {                        // ����//a�� 1���� �ϴϱ� a-1�� �ؾߵ�
			if (arr[y][x - a] == 1) {
				if (a == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y][x - a] == 2) {
				a++;
			}
			else {
				break;
			}
		}
		a = 1;
		//-------------------------------------------------------------------------------------
		//������
		while (x + a <= 20) {
			if (arr[y][x + a] == 1) {
				if (a == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y][x + a] == 2) {
				a++;
			}
			else {
				break;
			}
		}
		a = 1;
		//-------------------------------------------------------------------------------------
		//�Ʒ�
		while (y + b <= 20) {                        // ����//a�� 1���� �ϴϱ� a-1�� �ؾߵ�
			if (arr[y + b][x] == 1) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y + b][x] == 2) {
				b++;
			}
			else {
				break;
			}
		}
		b = 1;
		//-------------------------------------------------------------------------------------
		//��
		while (y - b >= 0) {                        // ����//a�� 1���� �ϴϱ� a-1�� �ؾߵ�
			if (arr[y - b][x] == 1) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y - b][x] == 2) {
				b++;
			}
			else {
				break;
			}
		}
		b = 1;
		//-------------------------------------------------------------------------------------
		//1-7�� �밢��
		while (y + b <= 20) {
			if (arr[y + b][x - a] == 1) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y + b][x - a] == 2) {
				a++;
				b++;
			}
			else { //0�̸�
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
		//7-1�� �밢��
		while (y - b >= 0) {
			if (arr[y - b][x + a] == 1) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y - b][x + a] == 2) {
				a++;
				b++;
			}
			else {
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
		//11-5�� �밢��
		while (y + b <= 20) {
			if (arr[y + b][x + a] == 1) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y + b][x + a] == 2) {
				a++;
				b++;
			}
			else {
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
		//5-11�� �밢��
		while (y - b >= 0) {
			if (arr[y - b][x - a] == 1) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y - b][x - a] == 2) {
				a++;
				b++;
			}
			else {
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
	}
	else {
		//-------------------------------------------------------------------------------------
		//����
		while (x - a >= 0) {                        //a�� 1���� �ϴϱ� a-1�� �ؾߵ�
			if (arr[y][x - a] == 2) {
				if (a == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y][x - a] == 1) {
				a++;
			}
			else {
				break;
			}
		}
		a = 1;
		//-------------------------------------------------------------------------------------
		//������
		while (x + a <= 20) {                        // ����//a�� 1���� �ϴϱ� a-1�� �ؾߵ�
			if (arr[y][x + a] == 2) {
				if (a == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y][x + a] == 1) {
				a++;
			}
			else {
				break;
			}
		}
		a = 1;
		//-------------------------------------------------------------------------------------
		//�Ʒ�
		while (y + b <= 20) {                        // ����//a�� 1���� �ϴϱ� a-1�� �ؾߵ�
			if (arr[y + b][x] == 2) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y + b][x] == 1) {
				b++;
			}
			else {
				break;
			}
		}
		b = 1;
		//-------------------------------------------------------------------------------------
		//��
		while (y - b >= 0) {                        // ����//a�� 1���� �ϴϱ� a-1�� �ؾߵ�
			if (arr[y - b][x] == 2) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y - b][x] == 1) {
				b++;
			}
			else {
				break;
			}
		}
		b = 1;
		//-------------------------------------------------------------------------------------
		//1-7�� �밢��
		while (y + b <= 20) {
			if (arr[y + b][x - a] == 2) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y + b][x - a] == 1) {
				a++;
				b++;
			}
			else {
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
		//7-1�� �밢��
		while (y - b >= 0) {
			if (arr[y - b][x + a] == 2) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y - b][x + a] == 1) {
				a++;
				b++;
			}
			else {
				break;
			}
		}

		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
		//11-5�� �밢��
		while (y + b <= 20) {
			if (arr[y + b][x + a] == 2) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y + b][x + a] == 1) {
				a++;
				b++;
			}
			else {
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
		//5-11�� �밢��
		while (y - b >= 0) {
			if (arr[y - b][x - a] == 2) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y - b][x - a] == 1) {
				a++;
				b++;
			}
			else {
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------

	}
	return 0;
}
