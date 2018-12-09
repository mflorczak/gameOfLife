#pragma once
#include "board.h"

class Effect
{
  protected:
    int x;
    int y;
    int dx;
    int dy;

  public:
    Effect();
    Effect(int, int, int, int);
    virtual void apply(int **) = 0;
};

class EffectZero : public Effect
{
  public:
    EffectZero();
    EffectZero(int, int, int, int);
    void apply(int **);
};

class EffectOne : public Effect
{
  public:
    EffectOne();
    EffectOne(int, int, int, int);
    void apply(int **);
};

class EffectTwo : public Effect
{
  public:
    EffectTwo();
    EffectTwo(int, int, int, int);
    void apply(int **);
};

class EffectThree : public Effect
{
  public:
    EffectThree();
    EffectThree(int, int, int, int);
    void apply(int **);
};

class EffectFour : public Effect
{
  public:
    EffectFour();
    EffectFour(int, int, int, int);
    void apply(int **);
};

class EffectFive : public Effect
{
  private:
    int **savedBoard;
    bool isSave;

  public:
    EffectFive();
    EffectFive(int, int, int, int);
    void apply(int **);
};

class EffectSix : public Effect
{
  private:
    int **savedBoard;
    bool isSave;

  public:
    EffectSix();
    EffectSix(int, int, int, int);
    void apply(int **);
};