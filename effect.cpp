#include "effect.h"

Effect::Effect()
{
}

Effect::Effect(int x, int y, int dx, int dy)
{
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
}

EffectZero::EffectZero()
{
}

EffectZero::EffectZero(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectZero::apply(int **board)
{
    for (int i = x; i <= dx; i++)
        for (int j = y; j <= dy; j++)
            board[i][j] = 0;
}

EffectOne::EffectOne()
{
}

EffectOne::EffectOne(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectOne::apply(int **board)
{
    for (int i = x; i <= dx; i++)
        for (int j = y; j <= dy; j++)
            board[i][j] = 1;
}

EffectTwo::EffectTwo()
{
}

EffectTwo::EffectTwo(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectTwo::apply(int **board)
{
    for (int i = x; i <= dx; i++)
    {
        for (int j = y; j <= dy; j++)
        {
            if (board[i][j] == 0)
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
}

EffectThree::EffectThree()
{
}

EffectThree::EffectThree(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectThree::apply(int **board)
{
    int copyBoard[16][16];

    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            copyBoard[i][j] = board[i][j];

    for (int i = x; i <= dx; i++)
    {
        for (int j = y; j <= dy; j++)
        {
            if (copyBoard[i][j] == 1)
            {
                int neighbourCount = 0;
                for (int n = -1; n < 2; n++)
                {
                    for (int m = -1; m < 2; m++)
                    {
                        if (!(n == 0 && m == 0))
                        {
                            int a = i;
                            int b = j;
                            a += n;
                            b += m;
                            switch (a)
                            {
                            case -1:
                                a = 15;
                                break;
                            case 16:
                                a = 0;
                                break;
                            }

                            switch (b)
                            {
                            case -1:
                                b = 15;
                                break;
                            case 16:
                                b = 0;
                                break;
                            }
                            if (copyBoard[a][b] == 1)
                                ++neighbourCount;
                        }
                    }
                }
                if (!(neighbourCount == 2 || neighbourCount == 3))
                    board[i][j] = 0;
                else
                    board[i][j] = 1;
            }
            else
                board[i][j] = 0;
        }
    }
}

EffectFour::EffectFour()
{
}

EffectFour::EffectFour(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectFour::apply(int **board)
{
    int copyBoard[16][16];

    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            copyBoard[i][j] = board[i][j];

    for (int i = x; i <= dx; i++)
    {
        for (int j = y; j <= dy; j++)
        {
            if (copyBoard[i][j] == 0)
            {
                int neighbourCount = 0;

                for (int n = -1; n < 2; n++)
                {
                    for (int m = -1; m < 2; m++)
                    {
                        if (!(m == 0 && n == 0))
                        {
                            int a = i;
                            int b = j;
                            a += n;
                            b += m;
                            switch (a)
                            {
                            case -1:
                                a = 15;
                                break;
                            case 16:
                                a = 0;
                                break;
                            }

                            switch (b)
                            {
                            case -1:
                                b = 15;
                                break;
                            case 16:
                                b = 0;
                                break;
                            }
                            if (copyBoard[a][b] == 1)
                                ++neighbourCount;
                        }
                    }
                }
                if (neighbourCount == 3)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
            else
                board[i][j] = 0;
        }
    }
}

EffectFive::EffectFive()
{
    isSave = false;
}

EffectFive::EffectFive(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectFive::apply(int **board)
{
    if (!isSave)
    {
        int **initializerTable = new int *[16];
        for (int i = 0; i < 16; i++)
            initializerTable[i] = new int[16];
        savedBoard = initializerTable;
        for (int i = x; i <= dx; i++)
        {
            for (int j = y; j <= dy; j++)
            {
                savedBoard[i][j] = board[i][j];
            }
        }
        isSave = true;
    }
    else
    {
        for (int i = x; i <= dx; i++)
        {
            for (int j = y; j <= dy; j++)
            {

                board[i][j] = (savedBoard[i][j] & 1) ^ (board[i][j] & 1);
            }
        }
        isSave = false;
    }
}

EffectSix::EffectSix()
{
    isSave = false;
}

EffectSix::EffectSix(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectSix::apply(int **board)
{
    if (!isSave)
    {
        int **initializerTable = new int *[16];
        for (int i = 0; i < 16; i++)
            initializerTable[i] = new int[16];
        this->savedBoard = initializerTable;
        for (int i = x; i <= dx; i++)
        {
            for (int j = y; j <= dy; j++)
            {
                this->savedBoard[i][j] = board[i][j];
            }
        }
        isSave = true;
    }
    else
    {
        for (int i = x; i <= dx; i++)
        {
            for (int j = y; j <= dy; j++)
            {
               this->savedBoard[i][j] = board[i][j];
            }
        }
        isSave = false;
    }
}