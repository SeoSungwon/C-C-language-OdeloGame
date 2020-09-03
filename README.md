# C/C++-language-Odelo-

## 오델로 게임규칙
```
1. 백돌과 흑돌이 존재하며 2인 턴제로 진행된다.
2. 자신의 차례일 때 돌을 놓으면 자신의 색과 자신의 색 사이에 있는 모든 상대방 색깔의 돌을 자신의 색으로 바뀐다.
3. 2번의 규칙에서 자신의돌과 자신의 돌 사이에 상대방의 돌이 없다면 돌을 놓을 수 없다.
4. 2번 규칙은 상하좌우 대각선 모두 포함된다.
5. 돌이 일정개수 이상 만들어지거나 일정 시간이 지나면 게임이 종료된다.
6. 더 많은 돌을 가진 플레이어가 승리한다.
```

## 조작법
```
1. WASD의 입력을 통해 돌을 이동시킨다.
2. Enter키를 누르면 돌을 놓는다.
```

## 코드 설명
```C
int Odello() {
  //전역배열arr의 중심점의 초기화(흑돌2개 백돌2개)
	arr[10][10] = 1;
	arr[11][11] = 1;
	arr[10][11] = 2;
	arr[11][10] = 2;
	start = clock();
	while (1) {
		b_n = 0;
		w_n = 0;
		system("cls");
		for (i = 0; i < 21; i++) {  //바둑판 생성(CMD의 버전에 따라 모양이 달라질 수 있음)
			for (j = 0; j < 21; j++) {
				switch (arr[i][j]) {
        //바둑판 base
				case 0:
					printf(" ┼");
					break;
				case 1: //코드상으로는 검정색이지만 cmd창에서는 하얀색으로 보임 case 1은 백돌
					printf("●");
					b_n++;
					break;
				case 2: //흑돌
					printf("○");
					w_n++;
					break;
				case 3: //플레이어가 돌을 이동시킬 때 현재 위치가 백돌 위에 있을경우
					printf("★");
					b_n++;
					break;
				case 4: //현재 위치가 흑돌 위에있을 경우
					printf("☆");
					w_n++;
					break;
				case 5:
					printf("●");
					b_n++;
					break;
				case 6:
					printf("○");
					w_n++;
					break;

				}
			}
			printf("\n");
		}
		printf("\t 백돌 vs 흑돌\n");
		mid = clock();

		printf("\t  %d vs  %d\t%d초 경과", b_n, w_n, (int)((mid - start) / 1000)); //이 부분은 Thread로 돌리면 실시간으로 바뀜, 현재는 버튼이 눌릴 때마다 

		if (turn % 2 == 0)
			b_n--;
		else
			w_n--;

		if ((int)((mid - start) / 1000) > 10 * 30) { //승리 조건1
			system("cls");
			printf("\t 흑돌 vs 백돌\n");
			printf("\t  %d vs  %d\n", b_n, w_n);
			if (b_n > w_n)
				printf("흑돌 승!\n");
			else
				printf("백돌 승!\n");
		}
		if (b_n > 70) {                                          // 승리 조건2
			system("cls");
			printf("흑돌 승리!");
		}
		else if (w_n > 70) {
			system("cls");
			printf("백돌 승리!");
		}
```
