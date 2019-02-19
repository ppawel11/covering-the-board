#ifndef PLANSZA2_H_INCLUDED
#define PLANSZA2_H_INCLUDED


#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Figura;
class Plansza
{
    int n; //szer
    int m; //wys
    int dom, tro, tet; //wartosci startowe, wczytane z pliku
    char znak;
public:
    int ksztalty[10];  // domina, tromina: I, L, tetramina: I, K, X, L2, L, Z, S
    char **board;
    Plansza(string input_file);
    ~Plansza();
    void drukuj();
    void wpisz(int x, int y, char a);
    void addZnak();
    void remove_last();
    void figures();

    void is_over(int &x, int &y);
    bool all_placed();

    int getn();
    int getm();

    friend class Domino;
    friend class Tromino;
    friend class Tetramino;
};

#endif // PLANSZA2_H_INCLUDED
