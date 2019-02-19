#ifndef FIGURY_H_INCLUDED
#define FIGURY_H_INCLUDED

#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

class Plansza;

class Figura
{
public:
    virtual bool flip() = 0;
    virtual void ruch(int, int) = 0;
    virtual bool correct(Plansza&) = 0;
    virtual bool place(Plansza&) = 0;
};

class Domino: public Figura
{
    int x, y, typ;
public:
    Domino();
    bool flip();
    bool correct(Plansza& plan);
    void ruch(int a, int b);
    bool place(Plansza& plan);
};

class Tromino: public Figura
{
protected:
    int x, y;
    int trominoRect[3][3];
    virtual bool flip() = 0;
public:
    Tromino();
    void ruch(int a, int b);
    bool correct(Plansza& plan);
    bool place(Plansza& plan);
};

class TrominoI: public Tromino
{
public:
    TrominoI();
    bool flip();
};

class TrominoL: public Tromino
{
public:
    TrominoL();
    bool flip();
};

class Tetramino: public Figura
{
protected:
    int x, y;
    int tetraRect[4][4];
    Tetramino();
    virtual bool flip() = 0;
    bool correct(Plansza& plan);
public:
    void ruch(int a, int b);
    bool place(Plansza& plan);
};

class TetraminoK: public Tetramino
{
public:
    TetraminoK();
    bool flip();
};
class TetraminoI:public Tetramino
{
public:
    TetraminoI();
    bool flip();
};

class TetraminoZ: public Tetramino
{
public:

    TetraminoZ();
    bool flip();
};

class TetraminoX: public Tetramino
{
public:
    TetraminoX();
    bool flip();
};

class TetraminoS:public Tetramino
{
public:
    TetraminoS();
    bool flip();
};

class TetraminoL: public Tetramino
{
    int typ;
public:
    TetraminoL();
    bool flip();
};

class TetraminoL2: public Tetramino
{
    int typ;
public:
    TetraminoL2();
    bool flip();
};

bool algo(Plansza &plansza);

#endif // FIGURY_H_INCLUDED
