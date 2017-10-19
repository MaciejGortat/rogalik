#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

typedef struct {
	int x;
	int y;
} hero;

void gotoxy(int x, int y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

char** createMap() {
	char** map = (char**)malloc(sizeof(char*) * 64);
	for (int i = 0; i < 64; ++i) {
		*(map + i) = (char*)malloc(sizeof(char) * 32);
		memset(*(map + i), 241, 32);
	}
	for (int i = 0; i < 64; ++i) {
		map[i][0] = map[i][31]= '#';
	}
	for (int i = 1; i < 32; ++i) {
		map[0][i] = map[63][i]= '#';
	}
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 64; ++j) {
			printf("%c", map[j][i]);
		}
		printf("\n");
	}
	return map;
}

void refresh(char** map) {
	system("cls");
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 64; ++j) {
			printf("%c", map[j][i]);
		}
		printf("\n");
	}
}

void makeSomeObstacles(char** map) {
	srand(time(NULL));
	char** bul = (char**)malloc(sizeof(char*) * 64);
	for (char i = 0; i < 64; ++i) {
		*(map + i) = (char*)malloc(sizeof(char) * 32);
		memset(*(map + i), 0, 32 * sizeof(char));
	}
	int amount = (rand() % 4) + 3;
	int* obstaclesSizes = (int*)malloc(amount * sizeof(int));
	for (int i = 0; i < amount; ++i) {
		obstaclesSizes = (rand() % 3) + 3;
	}
	for (int i = 0; i < amount; ++i) {
		
	}
	map[(rand() % 10) + 3][(rand() % 10) + 3] = 

}

int main() {
	system("cls");
	char** map = createMap();
	hero me;
	me.x = 1;
	me.y = 1;
	for (short action; action != 'q'; action = _getch()) {
		switch (action) {
			case ('w'): {
				if (me.y > 1) {
					gotoxy(me.x, me.y);
					printf("%c", map[me.x][me.y] = 241);
					gotoxy(me.x, --me.y);
					printf("%c", map[me.x][me.y] = '@');
				}
				break;
			}
			case ('a'): {
				if (me.x > 1) {
					gotoxy(me.x, me.y);
					printf("%c", map[me.x][me.y] = 241);
					gotoxy(--me.x, me.y);
					printf("%c", map[me.x][me.y] = '@');
				}
				break;
			}
			case ('d'): {
				if (me.x < 62) {
					gotoxy(me.x, me.y);
					printf("%c", map[me.x][me.y] = 241);
					gotoxy(++me.x, me.y);
					printf("%c", map[me.x][me.y] = '@');
				}
				break;
			}
			case ('s'): {
				if (me.y < 30) {
					gotoxy(me.x, me.y);
					printf("%c", map[me.x][me.y] = 241);
					gotoxy(me.x, ++me.y);
					printf("%c", map[me.x][me.y] = '@');
				}
				break;
			}
		}
		gotoxy(0, 32);
	}
	











	// for (int i = 0; i < 256; ++i){
	// 	printf("%d %c\n", i, i);
	// }
	for (int i = 0; i < 64; ++i) {
		free(*(map + i));
	}
	free(map);
	//system("PAUSE>nul");
	return 0;
}