#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <conio.h>
using namespace std;

bool game_over;
const int height = 28;
const int width = 117;
int x, y, fx, fy, nt, score;
int tx[100], ty[100];
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction d;
wchar_t* screen = new wchar_t[width * height];
HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
DWORD dwBytesWritten = 0;

void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void Setup() {
    game_over = false;
    d = STOP;
    x = width / 2;
    y = height / 2;
    fx = rand() % width;
    fy = rand() % height;
    score = 0;
    nt = 0;
}

void Draw_norm() {
    for (int i = 0; i < width + 2; i++) {
        SetColor(34);
        screen[i] = L'#';
        SetColor(7);
    }
    screen[width + 2] = L'\n';

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                SetColor(34);
                screen[i * width + j] = L'#';
                SetColor(7);
            }
            if (i == y && j == x) {
                SetColor(12);
                screen[i * width + j] = L'O'; // Corrected character
                SetColor(7);
            }
            else if (i == fy && j == fx) {
                SetColor(30);
                screen[i * width + j] = L'?';
                SetColor(7);
            }
            else {
                bool print = false;
                for (int k = 0; k < nt; k++) {
                    if (tx[k] == j && ty[k] == i) {
                        SetColor(12);
                        screen[i * width + j] = L'O'; // Corrected character
                        print = true;
                        SetColor(7);
                    }
                }
                if (!print)
                    screen[i * width + j] = L' ';
            }
            if (j == width - 1) {
                SetColor(34);
                screen[i * width + j] = L'#';
                SetColor(7);
            }
        }
        screen[i * width] = L'\n';
    }

    for (int i = 0; i < width + 2; i++) {
        SetColor(34);
        screen[i] = L'#';
        SetColor(7);
    }
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            d = LEFT;
            break;
        case 'd':
            d = RIGHT;
            break;
        case 'w':
            d = UP;
            break;
        case 's':
            d = DOWN;
            break;
        case 'x':
            game_over = true;
            break;
        }
    }
}


void Logic_norm()
{
    int px=tx[0];
    int py=ty[0];
    int p2x,p2y;
    tx[0]=x;
    ty[0]=y;
    for(int i=1; i<nt; i++)
    {
        p2x=tx[i];
        p2y=ty[i];
        tx[i]=px;
        ty[i]=py;
        px=p2x;
        py=p2y;
    }
    switch (d)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;

        //default:
        //break;
    }
    //if(x>width||x<0||y>height||y<0)game_over=true;
    if(x>=width)x=0;
    else if(x<0)x=width-1;
    if(y>=height)y=0;
    else if(y<0)y=height-1;
    for(int i=0; i<nt; i++) if(tx[i]==x && ty[i]==y)game_over=true;

    if(x==fx&&y==fy)
    {
        score+=10;
        fx=rand()%width;
        fy=rand()%height;
        nt++;
    }
}

int main() {
    SetConsoleActiveScreenBuffer(hConsole);
    for (int i = 0; i < width * height; i++) screen[i] = L' ';
    Setup();
    while (!game_over) {
        Draw_norm();
        Input();
        Logic_norm();
    }
}
