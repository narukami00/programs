#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

bool game_over;
const int height=20;
const int width=40;
int x,y,fx,fy,nt,score;
int  tx[100],ty[100];
enum Direction {STOP=0,LEFT,RIGHT,UP,DOWN};
Direction d;
//char screen[height][width];

void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void Setup()
{
    game_over=false;
    d=STOP;
    x=width/2;
    y=height/2;
    fx=rand()%width;
    fy=rand()%height;
    score=0;
    nt=0;

}
void Draw_norm()
{
    system("cls");
    for(int i=0; i<width+2; i++)
    {
        SetColor(34);cout<<"#";SetColor(7);
    }
    cout<<endl;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(j==0){SetColor(34);cout<<"#";SetColor(7);}
            if(i==y && j==x){SetColor(12);cout<<"O";SetColor(7);}
            else if(i==fy && j==fx){SetColor(30);cout<<"?";SetColor(7);}
            else
            {
                bool print=false;
                for(int k=0; k<nt; k++)
                {
                    if(tx[k]==j&&ty[k]==i)
                    {
                        SetColor(12);
                        cout<<"o";
                        print=true;
                        SetColor(7);
                    }

                }
                if(!print) cout<<" ";
            }
            if(j==width-1){SetColor(34);cout<<"#";SetColor(7);}
        }
        cout<<endl;
    }

    for(int i=0; i<width+2; i++)
    {
        SetColor(34);cout<<"#";SetColor(7);
    }
    cout<<endl;

    cout<<"Score :"<<score<<endl;
}

void Draw_hard()
{
    system("cls");
    for(int i=0; i<width+2; i++)
    {
        SetColor(30);cout<<".";SetColor(7);
    }
    cout<<endl;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(j==0){SetColor(30);cout<<".";SetColor(7);}
            if(i==y && j==x){SetColor(12);cout<<"O";SetColor(7);}
            else if(i==fy && j==fx){SetColor(32);cout<<"?";SetColor(7);}
            else
            {
                bool print=false;
                for(int k=0; k<nt; k++)
                {
                    if(tx[k]==j&&ty[k]==i)
                    {
                        SetColor(12);
                        cout<<"o";
                        print=true;
                        SetColor(7);
                    }

                }
                if(!print) cout<<" ";
            }
            if(j==width-1){SetColor(30);cout<<".";SetColor(7);}
        }
        cout<<endl;
    }

    for(int i=0; i<width+2; i++)
    {
        SetColor(30);cout<<".";SetColor(7);
    }
    cout<<endl;

    cout<<"Score :"<<score<<endl;
}

void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            d=LEFT;
            break;
        case 'd':
            d=RIGHT;
            break;
        case 'w':
            d=UP;
            break;
        case 's':
            d=DOWN;
            break;
        case 'x':
            game_over=true;
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

void Logic_hard()
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
    if(x>width||x<0||y>height||y<0)game_over=true;
    //if(x>=width)x=0;
    //else if(x<0)x=width-1;
    //if(y>=height)y=0;
    //else if(y<0)y=height-1;
    for(int i=0; i<nt; i++) if(tx[i]==x && ty[i]==y)game_over=true;

    if(x==fx&&y==fy)
    {
        score+=10;
        fx=rand()%width;
        fy=rand()%height;
        nt++;
    }
}

bool Try_Again()
{
    cout << endl << "Do you want to play again?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    int res2;
    do
    {
        cin >> res2;
        if (res2 == 1)
        {
            return true;
        }
        else if (res2 == 2)
        {
            return false;
        }
        else
        {
            cout << "Invalid input. Please choose 1 or 2." << endl;
        }
    }
    while (true);
}

int set_difficulty()
{
    cout<<"Choose difficulty"<<endl<<"1.Normal"<<endl<<"2.Hard"<<endl;
    int res3;
    do
    {
        cin>>res3;
        if(res3==1)return 1;
        else if(res3==2)return 2;
        else cout << "Invalid input. Please choose 1 or 2." << endl;
    }
    while(true);

}


void Play_norm()
{
    do
    {
        Setup();
        while(!game_over)
        {
            Draw_norm();
            Input();
            Logic_norm();
            Sleep(50);
        }
    }
    while(Try_Again());
    cout<<"Thanks for playing!!! :D"<<endl;
}

void Play_hard()
{
    do
    {
        Setup();
        while(!game_over)
        {
            Draw_hard();
            Input();
            Logic_hard();
            Sleep(0);
        }
    }
    while(Try_Again());
    SetColor(12);
    cout<<"Thanks for playing!!! :D You're really cool !"<<endl;
    SetColor(7);
}
int main()
{
    SetColor(12);
    cout<<"  ____              __              \n";
    cout<<" / ___|   _     _  | | _           \n";
    cout<<" \\___ --/   \\ /  \\ | |/ / ___      \n";
    cout<<"  ___) |  ^  | () \\|   < / _'\\--   \n";
    cout<<" |____/|_| |_|\\__/\\|_|\\ \\ \\___     \n";
    cout<<"  ________________________\_\__  \\  \n";
    cout<<" <____________________________ /  \n";
    cout<<endl;
    SetColor(7);
    cout<<"Do you want to play?"<<endl<<"1.Yes"<<endl<<"2.No"<<endl;
    int res;
    do
    {
        cin>>res;
        if(res==1)
        {
            switch(set_difficulty())
            {
            case 1:
                Play_norm();
                return 0;
            case 2:
                Play_hard();
                return 0;
            }

        }
        else if(res==2) cout<<endl<<"Byeee!"<<endl;
        else
        {
            cout << "Invalid input. Please choose 1 or 2." << endl;
        }
    }
    while(true);

    return 0;
}


