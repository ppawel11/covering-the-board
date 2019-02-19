#include "figury.h"
#include "plansza.h"

int main()
{

    cout<<"Program szukajacy sposobu pokrycia planszy,\nzadana iloscio domin, tromin i tetramin."<<endl;
    cout<<"Autor: Pawel Lech"<<endl<<endl;
    srand (time(NULL));
    Plansza *p;
    try{p = new Plansza("test.txt");}
    catch(int a)
    {
        return a;
    }
    p->figures();
    if(algo(*p))
        {
            cout<<"Rozwiazanie znalezione: "<<endl;
            p->drukuj();
        }
    else
        cout<<"Rozwiazania nie znaleziono."<<endl;

    delete p;
    return 0;
}
