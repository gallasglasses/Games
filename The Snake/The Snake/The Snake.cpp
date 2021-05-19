// The Snake.cpp 
//**
//

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <sysinfoapi.h>

const int WIDTH = 60,
          HEIGHT = 40;

int x,
    y,
    boardX,
    boardY,
    foodX,
    foodY,
    tailX[100],
    tailY[100],
    nTail,
    score;

double after_ms = 600.0;

bool isGameOver;

enum class eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection route;

void NewFood();
void Setup();
void Draw();
void ClearScreen();
void hideCursor();
void DrawWidthBorder();
void DrawHeightBorder();
void Input();
void Logic();


int main()
{
    Setup();
    while (!isGameOver)
    {
        Draw();
        Input();
        Logic();
    }
    return 0;
}

void NewFood()
{
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
}

void Setup()
{
    isGameOver = false;
    route = eDirection::STOP;

    boardX = 0;
    boardY = 0;

    x = WIDTH / 2 - 1;
    y = HEIGHT / 2 - 1;

    NewFood();

    score = 0;
}

void Draw()
{

    ClearScreen();
    hideCursor();

    DrawWidthBorder();
    printf("\n");

    DrawHeightBorder();
    
    DrawWidthBorder();
    printf("\n");

    std::cout << "\nScore: " << score;
}

void ClearScreen()
{
    HANDLE                     hStdOut;
    COORD                      Position;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = boardX;
    Position.Y = boardY;

    SetConsoleCursorPosition(hStdOut, Position); 

}

void hideCursor() 
{ 
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void DrawWidthBorder()
{
    for (int i = 0; i < WIDTH + 1; i++)
    {
        printf("o");
    }
}

void DrawHeightBorder()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0 || j == WIDTH - 1)
            {
                printf("o");
            }
            if (i == y && j == x)
            {
                printf("@");
            }
            else if (i == foodY && j == foodX)
            {
                printf("F");
            }
            else
            {
                bool isPrintTail = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        isPrintTail = true;
                        printf("#");
                    }
                }
                if (!isPrintTail)
                    printf(" ");
            }
        }
        printf("\n");
    }
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch ())
        {
        case 'a':
            route = eDirection::LEFT;
            break;
        case 'd':
            route = eDirection::RIGHT;
            break;
        case 'w':
            route = eDirection::UP;
            break;
        case 's':
            route = eDirection::DOWN;
            break;
        case 'q':
            isGameOver = true;
            break;
        }
    }
}


//unsigned long long currentMoveTime,preMoveTime;

void Logic()
{
    int prevX = tailX[0],
        prevY = tailY[0],
        prev2X,
        prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    
    //currentMoveTime = GetTickCount64();
    //preMoveTime = 0;
    switch (route)
    {
    case eDirection::LEFT:
        x--;
        //if (after_ms <= currentMoveTime - preMoveTime)
        //{
           // preMoveTime = currentMoveTime;
            //currentMoveTime = GetTickCount64();
            
        //}
        break;
    case eDirection::RIGHT:
        x++;
        //if (after_ms <= currentMoveTime - preMoveTime)
       // {
           // preMoveTime = currentMoveTime;
            //currentMoveTime = GetTickCount64();
            
        //}
        break;
    case eDirection::UP:
        y--;
        //if (after_ms <= currentMoveTime - preMoveTime)
        //{
            //preMoveTime = currentMoveTime;
            //currentMoveTime = GetTickCount64();
            
        //}
        break;
    case eDirection::DOWN:
        y++;
        //if (after_ms <= currentMoveTime - preMoveTime)
        //{
            //preMoveTime = currentMoveTime;
            //currentMoveTime = GetTickCount64();
            
        //}
        break;
    }

    if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
    {
        isGameOver = true;
    }

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            isGameOver = true;
    }

    if (x == foodX && y == foodY)
    {
        score++;
        NewFood();
        nTail++;
        /*
        if (score % 2 == 0 && score != 0)
        {
            if (after_ms > 20)
                after_ms -= 20;
            else after_ms /= 20;
        }*/
    }
}