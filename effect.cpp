#include "effect.h"

Effect::Effect()
{
}

Effect::Effect(int x, int y, int dx, int dy, int d)
{
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
    this->d = d;
}

EffectZero::EffectZero()
{
}

EffectZero::EffectZero(int x, int y, int dx, int dy, int d) : Effect(x, y, dx, dy, d)
{
}

void EffectZero::apply(vector<Board> &boards)
{
    for (int i = x; i <= dx; i++)
        for (int j = y; j <= dy; j++)
            boards.at(d).getCondition(i, j) = DeathCell(0);
}

EffectOne::EffectOne()
{
}

EffectOne::EffectOne(int x, int y, int dx, int dy, int d) : Effect(x, y, dx, dy, d)
{
}

void EffectOne::apply(vector<Board> &boards)
{
    for (int i = x; i <= dx; i++)
        for (int j = y; j <= dy; j++)
            boards.at(d).getCondition(i, j) = LifeCell(1);
}

EffectTwo::EffectTwo()
{
}

EffectTwo::EffectTwo(int x, int y, int dx, int dy, int d) : Effect(x, y, dx, dy, d)
{
}

void EffectTwo::apply(vector<Board> &boards)
{
    for (int i = x; i <= dx; i++)
        for (int j = y; j <= dy; j++)
        {
            if (boards.at(d).getCondition(i, j).getValueCondition() == 0)
                boards.at(d).getCondition(i, j) = LifeCell(1);
            else
                boards.at(d).getCondition(i, j) = DeathCell(0);
        }
}

EffectThree::EffectThree()
{
}

EffectThree::EffectThree(int x, int y, int dx, int dy, int d) : Effect(x, y, dx, dy, d)
{
}

void EffectThree::apply(vector<Board> &boards)
{
    for (int i = x; i <= dx; i++)
    {
        for (int j = y; j <= dy; j++)
        {
            if (boards.at(d).getCondition(i, j).getValueCondition() == 1)
            {
                int neighbourCount = 0;
                for (int n = -1; n < 2; n++)
                {
                    for (int m = -1; m < 2; m++)
                    {
                        if (!(n == 0 && m == 0))
                        {
                            int a = i + n;
                            int b = j + m;
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
                            if ((boards.at(d).getCondition(i, j).getValueCondition() == 1))
                                ++neighbourCount;
                        }
                    }
                }
                if (!(neighbourCount == 2 || neighbourCount == 3))
                    boards.at(d).getCondition(i, j) = DeathCell(0);
                else
                    boards.at(d).getCondition(i, j) = LifeCell(1);
            }
            else
                boards.at(d).getCondition(i, j) = DeathCell(0);
        }
    }
}

EffectFour::EffectFour()
{
}

EffectFour::EffectFour(int x, int y, int dx, int dy, int d) : Effect(x, y, dx, dy, d)
{
}

void EffectFour::apply(vector<Board> &boards)
{
    for (int i = x; i <= dx; i++)
    {
        for (int j = y; j <= dy; j++)
        {
            if (boards.at(d).getCondition(i, j).getValueCondition() == 0)
            {
                int neighbourCount = 0;
                for (int n = -1; n < 2; n++)
                {
                    for (int m = -1; m < 2; m++)
                    {
                        if (!(n == 0 && m == 0))
                        {
                            int a = i + n;
                            int b = j + m;
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
                            if ((boards.at(d).getCondition(i, j).getValueCondition() == 1))
                                ++neighbourCount;
                        }
                    }
                }
                if (neighbourCount == 3)
                    boards.at(d).getCondition(i, j) = LifeCell(1);
                else
                    boards.at(d).getCondition(i, j) = DeathCell(0);
            }
            else
                boards.at(d).getCondition(i, j) = DeathCell(0);
        }
    }
}

EffectFive::EffectFive()
{
}

EffectFive::EffectFive(int x, int y, int dx, int dy, int d) : Effect(x, y, dx, dy, d)
{
}

void EffectFive::apply(vector<Board> &boards)
{
    if (!isSave)
    {
        board = boards.at(d);
        isSave = true;
    }
    else
    {
        for (int i = x; i <= dx; i++)
        {
            for (int j = y; j <= dy; j++)
            {
                if (board.getCondition(i, j).getValueCondition() == 0 && boards.at(1).getCondition(i, j).getValueCondition() == 1)
                    boards.at(1).getCondition(i, j) = LifeCell(1);
                if (board.getCondition(i, j).getValueCondition() == 1 && boards.at(1).getCondition(i, j).getValueCondition() == 0)
                    boards.at(1).getCondition(i, j) = LifeCell(1);
                if (board.getCondition(i, j).getValueCondition() == 1 && boards.at(1).getCondition(i, j).getValueCondition() == 1)
                    boards.at(1).getCondition(i, j) = DeathCell(0);
                if (board.getCondition(i, j).getValueCondition() == 0 && boards.at(1).getCondition(i, j).getValueCondition() == 0)
                    boards.at(1).getCondition(i, j) = DeathCell(0);
            }
        }
        isSave = false;
    }
}

EffectSix::EffectSix()
{
}

EffectSix::EffectSix(int x, int y, int dx, int dy, int d) : Effect(x, y, dx, dy, d)
{
}

void EffectSix::apply(vector<Board> &boards)
{
    if (!isSave)
    {
        board = boards.at(d);
        isSave = true;
    }
    else
    {
        for (int i = x; i <= dx; i++)
        {
            for (int j = y; j <= dy; j++)
            {
                if (board.getCondition(i, j).getValueCondition() == 1 )
                    boards.at(1).getCondition(i, j) = LifeCell(1);
                if (board.getCondition(i, j).getValueCondition() == 0 )
                    boards.at(1).getCondition(i, j) = DeathCell(0);
            }
        }
        isSave = false;
    }
}