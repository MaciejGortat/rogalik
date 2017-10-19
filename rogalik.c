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
	int amount = (rand() % 7) + 7;
	int tempx;
	int tempy;
	int test = 0;
	int* obstaclesSizes = (int*)malloc(amount * sizeof(int));
	for (int i = 0; i < amount; ++i) {
		obstaclesSizes[i] = (rand() % 3) + 3 + i;
		tempx = (rand() % 42) + (rand() % 10);
		tempy = (rand() % 21) + (rand() % 10);
		//printf("Am: %d OS: %d : %d %d\n", amount, obstaclesSizes[i], tempx, tempy);
		for (int j = tempx; j < tempx + obstaclesSizes[i]; ++j) {
			for (int k = tempy; k < tempy + obstaclesSizes[i]; ++k) {
				map[j][k] = '#';
				//printf("%d\n", ++test);
			}
		}
	}
	free(obstaclesSizes);
}

char** mapCpy(char** source) {
	char** map = (char**)malloc(sizeof(char*) * 64);
	for (int i = 0; i < 64; ++i) {
		*(map + i) = (char*)malloc(sizeof(char) * 32);
		memcpy(*(map + i), *(source + i), 32);
	}
	return map;
}

int main() {
	system("cls");
	hero me;
	me.x = 1;
	me.y = 1;
	char** map = createMap();
	for (int i = 0; i < 3; ++i) {
		makeSomeObstacles(map);	
	}
	refresh(map);
	char** mapCopy = mapCpy(map);
	//system("PAUSE>nul");
	for (short action; action != 'q'; action = _getch()) {
		switch (action) {
			case ('w'): {
				if (map[me.x][me.y - 1] != '#') {
					gotoxy(me.x, me.y);
					printf("%c", map[me.x][me.y] = mapCopy[me.x][me.y]);
					gotoxy(me.x, --me.y);
					printf("%c", map[me.x][me.y] = '@');
				}
				break;
			}
			case ('a'): {
				if (map[me.x - 1][me.y] != '#') {
					gotoxy(me.x, me.y);
					printf("%c", map[me.x][me.y] = mapCopy[me.x][me.y]);
					gotoxy(--me.x, me.y);
					printf("%c", map[me.x][me.y] = '@');
				}
				break;
			}
			case ('d'): {
				if (map[me.x + 1][me.y] != '#') {
					gotoxy(me.x, me.y);
					printf("%c", map[me.x][me.y] = mapCopy[me.x][me.y]);
					gotoxy(++me.x, me.y);
					printf("%c", map[me.x][me.y] = '@');
				}
				break;
			}
			case ('s'): {
				if (map[me.x][me.y + 1] != '#') {
					gotoxy(me.x, me.y);
					printf("%c", map[me.x][me.y] = mapCopy[me.x][me.y]);
					gotoxy(me.x, ++me.y);
					printf("%c", map[me.x][me.y] = '@');
				}
				break;
			}
			case ('r'): {
				map = createMap();
				for (int i = 0; i < 3; ++i) {
					makeSomeObstacles(map);	
				}
				refresh(map);
				mapCopy = mapCpy(map);
				me.x = 1;
				me.y = 1;
				break;
			}
		}
		gotoxy(0, 32);
	}
	for (int i = 0; i < 64; ++i) {
		free(*(map + i));
		free(*(mapCopy + i));
	}
	free(map);
	free(mapCopy);
	//system("PAUSE>nul");
	return 0;
}