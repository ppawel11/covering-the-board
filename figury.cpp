#include "figury.h"
#include "plansza.h"



//-------------------------------------DOMINO

Domino::Domino()
{
    x = -1;
    y = -1;
    typ = 0;
}

bool Domino::flip()
{
    typ =(typ+1)%2;
    return typ;
}

bool Domino::correct(Plansza& plan)
{
    if(x<0 or y<0)
        return false;
    if (x<=plan.m && y<=plan.n)
        switch(typ)
        {
        case 0:
            if (x+1<=plan.n)
                {if(plan.board[x][y] == '*' && plan.board[x+1][y] == '*')
                    return true;}
            break;
        case 1:
            if (y+1<=plan.m)
                {if (plan.board[x][y] == '*' && plan.board[x][y+1] == '*')
                    return true;}
            break;
        }
    return false;
}

void Domino::ruch(int a, int b)
{
    x = a;
    y = b;
}

bool Domino::place(Plansza& plan)
{
    if (correct(plan))
    {
        switch(typ)
        {
        case 0:
            plan.board[x][y] = plan.znak;
            plan.board[x+1][y] = plan.znak;
            break;
        case 1:
            plan.board[x][y] = plan.znak;
            plan.board[x][y+1] = plan.znak;
            break;
        }
        return true;
    }
    return false;
}

//-------------------------------------TROMINA

Tromino::Tromino()
{
    x=-1;
    y=-1;
    for(int i=x;i<x+3;i++)
        for(int j=y;j<y+3;j++)
        {
            trominoRect[i][j]=0;
        }
}

void Tromino::ruch(int a, int b)
{
    x=a;
    y=b;
}

bool Tromino::correct(Plansza& plan)
{
    if(x<0 or y<0)
        return false;
    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            if((i>plan.n || j>plan.m) && trominoRect[i-x][j-y] == 1)
                return false;
            if(trominoRect[i-x][j-y] == 1 && plan.board[i][j] != '*')
                return false;
        }
    }
    return true;
}

bool Tromino::place(Plansza& plan)
{
    if(correct(plan))
    {
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
            if(trominoRect[i-x][j-y]==1)
                plan.board[i][j]=plan.znak;
            }
        }
        return true;
    }
    return false;
}

TrominoI::TrominoI(): Tromino()
{
    trominoRect[0][0] =1;
    trominoRect[1][0] =1;
    trominoRect[2][0] =1;
}

bool TrominoI::flip()
{
    if (trominoRect[1][0] ==1)
    {
        trominoRect[1][0] =0;
        trominoRect[2][0] =0;
        trominoRect[0][1] =1;
        trominoRect[0][2] =1;
    }
    else if(trominoRect[0][1]==1)
    {
        trominoRect[1][0] =1;
        trominoRect[2][0] =1;
        trominoRect[0][1] =0;
        trominoRect[0][2] =0;
        return false;
    }
    return true;
}

TrominoL::TrominoL(): Tromino()
{
    trominoRect[0][0] =1;
    trominoRect[1][0] =1;
    trominoRect[0][1] =1;
}

bool TrominoL::flip()
{
    if(trominoRect[1][1]==0)
    {
        trominoRect[1][1]=1;
        trominoRect[1][0]=0;
    }
    else if(trominoRect[1][0]==0)
    {
        trominoRect[1][0]=1;
        trominoRect[0][0]=0;
    }
    else if(trominoRect[0][0]==0)
    {
        trominoRect[0][0]=1;
        trominoRect[0][1]=0;
    }
    else if(trominoRect[0][1]==0)
    {
        trominoRect[0][1]=1;
        trominoRect[1][1]=0;
        return false;
    }
    return true;
}

//-----------------------------------------TETRAMINA

Tetramino::Tetramino()
{
    x=-1;
    y=-1;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            tetraRect[i][j] = 0;
}

bool Tetramino::correct(Plansza& plan)
{
    if(x<0 or y<0)
        return false;
    for(int i=x;i<x+4;i++)
        for(int j=y;j<y+4;j++)
        {
            if((i>plan.n || j>plan.m) &&tetraRect[i-x][j-y] == 1)
                return false;
            if(tetraRect[i-x][j-y] == 1 && plan.board[i][j] != '*')
                return false;
        }
    return true;
}

void Tetramino::ruch(int a, int b)
{
    x=a;
    y=b;
}

bool Tetramino::place(Plansza& plan)
{
    if(correct(plan))
    {
        for(int i=x;i<x+4;i++)
        {
            for(int j=y;j<y+4;j++)
                if(tetraRect[i-x][j-y]==1)
                    plan.board[i][j]=plan.znak;
        }
        return true;
    }
    return false;
}

TetraminoK::TetraminoK(): Tetramino()
{
    tetraRect[0][0] = 1;
    tetraRect[1][0] = 1;
    tetraRect[1][1] = 1;
    tetraRect[0][1] = 1;
}

bool TetraminoK::flip()
{
    return false;
}

TetraminoI::TetraminoI(): Tetramino()
{
    tetraRect[0][0] = 1;
    tetraRect[1][0] = 1;
    tetraRect[2][0] = 1;
    tetraRect[3][0] = 1;
}

bool TetraminoI::flip()
{
    if(tetraRect[1][0] == 1)
    {
        tetraRect[1][0]=0;
        tetraRect[2][0]=0;
        tetraRect[3][0]=0;
        tetraRect[0][1]=1;
        tetraRect[0][2]=1;
        tetraRect[0][3]=1;
    }
    else if(tetraRect[0][1] ==1)
    {
        tetraRect[1][0]=1;
        tetraRect[2][0]=1;
        tetraRect[3][0]=1;
        tetraRect[0][1]=0;
        tetraRect[0][2]=0;
        tetraRect[0][3]=0;
        return false;
    }
    return true;
}

TetraminoZ::TetraminoZ(): Tetramino()
{
    tetraRect[0][0] =1;
    tetraRect[0][1] =1;
    tetraRect[1][1] = 1;
    tetraRect[1][2] =1;
}

bool TetraminoZ::flip()
{
    if(tetraRect[0][0] == 1)
    {
        tetraRect[0][0] = 0;
        tetraRect[1][0] = 1;
        tetraRect[1][2] =0;
        tetraRect[2][0] = 1;
    }
    else if(tetraRect[0][0] == 0)
    {
        tetraRect[0][0] = 1;
        tetraRect[1][0] = 0;
        tetraRect[1][2] = 1;
        tetraRect[2][0] = 0;
        return false;
    }
    return true;
}

TetraminoX::TetraminoX(): Tetramino()
{
    tetraRect[0][0] = 1;
    tetraRect[1][0] = 1;
    tetraRect[2][0] =1;
    tetraRect[1][1] = 1;
}

bool TetraminoX::flip()
{
    if(tetraRect[2][0] == 1)
    {
        tetraRect[2][0] = 0;
        tetraRect[1][0] = 0;
        tetraRect[0][1] = 1;
        tetraRect[0][2] = 1;
    }
    else if(tetraRect[0][2] == 1)
    {
        tetraRect[0][2] = 0;
        tetraRect[0][0] = 0;
        tetraRect[1][0] = 1;
        tetraRect[1][2] = 1;
    }
    else if(tetraRect[1][2] == 1)
    {
        tetraRect[1][2] =0;
        tetraRect[2][1] = 1;
    }
    else if(tetraRect[2][1] == 1)
    {
        tetraRect[2][1] = 0;
        tetraRect[0][1] = 0;
        tetraRect[2][0] = 1;
        tetraRect[0][0] = 1;
        return false;
    }
    return true;
}

TetraminoS::TetraminoS(): Tetramino()
{
    tetraRect[0][1] = 1;
    tetraRect[0][2] = 1;
    tetraRect[1][0] = 1;
    tetraRect[1][1] = 1;
}

bool TetraminoS::flip()
{
    if(tetraRect[0][0] == 0)
    {
        tetraRect[0][0] =1;
        tetraRect[0][1] =0;
        tetraRect[0][2] =0;
        tetraRect[2][1] =1;
    }
    else if(tetraRect[0][0] ==1)
    {
        tetraRect[0][0] =0;
        tetraRect[0][1] =1;
        tetraRect[0][2] =1;
        tetraRect[2][1] =0;
        return false;
    }
    return true;
}

TetraminoL::TetraminoL(): Tetramino()
{
    typ = 0;
    tetraRect[0][0] = 1;
    tetraRect[0][1] = 1;
    tetraRect[1][0] =1;
    tetraRect[2][0] = 1;
}

bool TetraminoL::flip()
{
    switch(typ)
    {
    case 0:
        {
            tetraRect[1][0] =0;
            tetraRect[2][0] =0;
            tetraRect[0][2] =1;
            tetraRect[1][2] =1;
            break;
        }
    case 1:
        {
            tetraRect[0][1] =0;
            tetraRect[0][2] = 0;
            tetraRect[1][1] =1;
            tetraRect[1][0] =1;
            break;
        }
    case 2:
        {
            tetraRect[0][0] =0;
            tetraRect[1][0] =0;
            tetraRect[1][2] =0;
            tetraRect[0][1] = 1;
            tetraRect[2][0] =1;
            tetraRect[2][1] =1;
            tetraRect[1][1] =1;
            break;
        }
    case 3:
        {
            tetraRect[2][1] =0;
            tetraRect[1][1] =0;
            tetraRect[0][0] =1;
            tetraRect[1][0] =1;
            break;
        }
    }
    typ= (typ+1)%4;
    return typ;
}

TetraminoL2::TetraminoL2(): Tetramino()
{
    typ = 0;
    tetraRect[0][0] =1;
    tetraRect[0][1] =1;
    tetraRect[0][2] =1;
    tetraRect[1][0] =1;
}

bool TetraminoL2::flip()
{
    switch(typ)
    {
    case 0:
        {
            tetraRect[0][2] =0;
            tetraRect[1][0] =0;
            tetraRect[1][1] =1;
            tetraRect[2][1] =1;
            break;
        }
    case 1:
        {
            tetraRect[0][0] =0;
            tetraRect[0][1] =0;
            tetraRect[2][1] =0;
            tetraRect[1][0] =1;
            tetraRect[1][2] =1;
            tetraRect[0][2] =1;
            break;
        }
    case 2:
        {
            tetraRect[0][2] =0;
            tetraRect[1][1] =0;
            tetraRect[1][2] =0;
            tetraRect[0][0] =1;
            tetraRect[2][0] =1;
            tetraRect[2][1]=1;
            break;
        }
    case 3:
        {
            tetraRect[2][1] =0;
            tetraRect[2][0] =0;
            tetraRect[0][1] =1;
            tetraRect[0][2] =1;
            break;
        }
    }
    typ = (typ+1)%4;
    return typ;
}

//--------------------------------------ALGORYTM

bool algo(Plansza &plansza)
{
    int puste[2] = {-1, -1};
    Figura *element;
    plansza.is_over(puste[0], puste[1]);
    if (puste[0]<0)
    {
        if(plansza.all_placed())
            return true;
        else
            return false;
    }

    if(plansza.all_placed() && puste[0] >= 0)
        return false;

    int ktory;
    for(int i=0;i<10;i++)
    {
        ktory=i;
        if(plansza.ksztalty[i] != 0)
        {
            switch(i)
            {
            case 0:
                {
                    element = new Domino();
                    break;
                }
            case 1:
                {
                    element = new TrominoI();
                    break;
                }
            case 2:
                {
                    element = new TrominoL();
                    break;
                }
            case 3:
                {
                    element = new TetraminoI();
                    break;
                }
            case 4:
                {
                    element = new TetraminoK();
                    break;
                }
            case 5:
                {
                    element = new TetraminoX();
                    break;
                }
            case 6:
                {
                    element = new TetraminoL();
                    break;
                }
            case 7:
                {
                    element = new TetraminoL2();
                    break;
                }
            case 8:
                {
                    element = new TetraminoZ();
                    break;
                }
            case 9:
                {
                    element = new TetraminoS();
                    break;
                }

            }
            break;
        }
    }
    do
    {
    element->ruch(puste[0],puste[1]);
    do
    {
        if(element->place(plansza)) //funkcja place zwraca true jesli uda sie ustawic element na zadanym polu
        {
            plansza.ksztalty[ktory] -= 1;
            plansza.addZnak();
            if(algo(plansza))
            {
                delete element;
                return true;
            }
            plansza.remove_last();
            plansza.ksztalty[ktory] +=1;
        }
    }
    while(element->flip()); //funkcja flip zwraca 0 przy powrocie do poczatkowej orientacji figury
    puste[0] += 1;
    puste[0] = puste[0]%plansza.getm();
    if(puste[0] == 0)
        puste[1] += 1;
    }
    while(puste[1]<=plansza.getn());

    delete element;
    return false;
}
