#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 10
#define OBSTACLE 'O'
#define PLAYER 'D'

void draw(char map[HEIGHT][WIDTH], int playerPos, int score) {
    system("cls");
    printf("Score: %d\n", score);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == playerPos && j == 2)
                printf("%c", PLAYER);
            else
                printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int updateObstacles(char map[HEIGHT][WIDTH], int *score) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH - 1; j++) {
            map[i][j] = map[i][j + 1];
        }
        map[i][WIDTH - 1] = ' ';
    }

    if (rand() % 20 == 0) {
        map[HEIGHT - 1][WIDTH - 2] = OBSTACLE;
    }

    if (map[HEIGHT - 2][2] == OBSTACLE) {
        return 0;
    }

    (*score)++;
    return 1;
}

void gameOver(int score) {
    system("cls");
    printf("Game Over!\n");
    printf("Your score: %d\n", score);
    printf("Press any key to try again...\n");
}

int main() {
    while (1) {
        char map[HEIGHT][WIDTH];
        int playerPos = HEIGHT - 2;
        int score = 0;

        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++)
                map[i][j] = ' ';

        while (1) {
            if (_kbhit()) {
                char ch = _getch();
                if (ch == ' ') {
                    if (playerPos > 0) playerPos--;
                }
            } else {
                playerPos = HEIGHT - 2;
            }

            draw(map, playerPos, score);

            if (!updateObstacles(map, &score)) {
                gameOver(score);
                break;
            }

            Sleep(100);
        }

        while (!_kbhit()) {
            Sleep(100);
        }
    }

    return 0;
}
