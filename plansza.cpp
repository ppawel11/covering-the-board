#include "plansza.h"

using namespace std;

Plansza::Plansza(string input_file)
{
    dom =0;
    tro =0;
    tet =0;
    znak = 'A';
    ifstream file;
    file.open(input_file.c_str());
    if(file.is_open())
    {
        file>>n>>m;
        board = new char*[m];
        for(int i = 0; i < m; ++i)
        {
            board[i] = new char[n];
            for(int k = 0; k<n; k++)
                board[i][k] = '*';
        }
        int l;
        while(!file.eof())
        {
            file>>l;
            if(l==2)
                file>>dom;
            else if(l==3)
                file>>tro;
            else if(l==4)
                file>>tet;
            else
                {
                    cout<<"Dane w pliku nieprawidlowe. Odczyt zakonczony"<<endl;
                    throw 2;
                }
        }
        file.close();
        ksztalty[0] = dom;
        if(tro)
        {
            ksztalty[1] = rand() % (tro+1);
            ksztalty[2] = tro - ksztalty[1];
        }
        int random;
        for(int i=0;i<tet;i++)
        {
            random = rand() % 7;
            ksztalty[random+3] += 1;
        }
    }
    else
        {
            cout<<"Nie udalo sie otworzyc pliku. Dane nie zostaly wczytane"<<endl;
            throw 1;
        }
}

Plansza::~Plansza()
{
    for(int i=0;i<m;i++)
        delete board[i];
    delete board;
    cout<<"usunieto plansze"<<endl;
}

void Plansza::drukuj()
{
    cout<<n<<" "<<m<<endl;
    for(int i = 0; i < m; ++i)
        {for(int k = 0; k<n; k++)
            cout<<board[i][k]<<" ";
        cout<<endl;}
}

void Plansza::wpisz(int x, int y, char a)
{
    board[x][y] = a;
}

void Plansza::addZnak()
{
    znak = znak+1;
}

void Plansza::remove_last()
{
    znak = znak-1;
    for(int i = 0; i < m; ++i)
        {
            for(int k = 0; k<n; k++)
                if (board[i][k] == znak)
                    board[i][k] = '*';
        }
}

void Plansza::figures()
{
    for(int i=0;i<10;i++)
        if(ksztalty[i] != 0)
            switch(i)
            {//tromina: I, L, tetramina: I, K, X, L, L2, Z, S
            case 0:
                {
                    cout<<"Uzyto domin: "<<ksztalty[i]<<endl;
                    break;
                }
            case 1:
                {
                    cout<<"Uzyto tromin I: "<<ksztalty[i]<<endl;
                    break;
                }
            case 2:
                {
                    cout<<"Uzyto tromin L: "<<ksztalty[i]<<endl;
                    break;
                }
            case 3:
                {
                    cout<<"Uzyto tetramin I: "<<ksztalty[i]<<endl;
                    break;
                }
            case 4:
                {
                    cout<<"Uzyto tetramin kwadratowych: "<<ksztalty[i]<<endl;
                    break;
                }
            case 5:
                {
                    cout<<"Uzyto tetramin X: "<<ksztalty[i]<<endl;
                    break;
                }
            case 6:
                {
                    cout<<"Uzyto tetramin L2: "<<ksztalty[i]<<endl;
                    break;
                }
            case 7:
                {
                    cout<<"Uzyto tetramin L: "<<ksztalty[i]<<endl;
                    break;
                }
            case 8:
                {
                    cout<<"Uzyto tetramin Z: "<<ksztalty[i]<<endl;
                    break;
                }
            case 9:
                {
                    cout<<"Uzyto tetramin S: "<<ksztalty[i]<<endl;
                    break;
                }
            }
}

void Plansza::is_over(int &x, int &y)
{
    for(int i = 0; i < m; i++)
        {
            for(int k = 0; k<n; k++)
                if (board[i][k] == '*')
                    {
                        x = i;
                        y = k;
                        return;
                    }
        }
    return;
}

bool Plansza::all_placed()
{
    for(int i=0;i<10;i++)
        if (ksztalty[i] != 0)
            return false;
    return true;
}

int Plansza::getn() {return n;}
int Plansza::getm() {return m;}
