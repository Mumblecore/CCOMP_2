#include <iostream>

using namespace std;

bool gano(int tab[][7], int fil, short col)
{
    int *p = *(tab+6-fil) + col;

    if(fil > 3)
    {
        if(*p == *(p+7) && *(p+7) == *(p+14) && *(p+14) == *(p+21))
        {
            return true;
        }
        if(col > 2)
        {
            if(*p == *(p-1) && *(p-1) == *(p-2) && *(p-2) == *(p-3))
            {
                return true;
            }
            if(*p == *(p+6) && *(p+6) == *(p+12) && *(p+12) == *(p+18))
            {
                return true;
            }
        }
        if(col < 4)
        {
            if(*p == *(p+1) && *(p+1) == *(p+2) && *(p+2) == *(p+3))
            {
                return true;
            }
            if(*p == *(p+8) && *(p+8) == *(p+16) && *(p+16) == *(p+24))
            {
                return true;
            }
        }
    }
    else
    {
        if(*p == *(p-7) && *(p-7) == *(p-14) && *(p-14) == *(p-21))
        {
            return true;
        }
        if(col > 2)
        {
            if(*p == *(p-1) && *(p-1) == *(p-2) && *(p-2) == *(p-3))
            {
                return true;
            }
            if(*p == *(p-8) && *(p-8) == *(p-16) && *(p-16) == *(p-24))
            {
                return true;
            }
        }
        if(col < 4)
        {
            if(*p == *(p+1) && *(p+1) == *(p+2) && *(p+2) == *(p+3))
            {
                return true;
            }
            if(*p == *(p-6) && *(p-6) == *(p-12) && *(p-12) == *(p-18))
            {
                return true;
            }
        }
    }
    return false;
}

bool InsertarFicha(int tab[][7], int pos, bool jug)
{
    if(pos > 7)
    {
        cout << "Ingresar una columna vacia o menor que 8\n";
        return false;
    }
    if(*(*tab + pos) == 0)
    {
        int* p;
        for(int i = 0; i < 6; i++)
        {
            if(*(*tab + pos) == 0)
                p = *tab++ + pos;
        }
        *p = (jug ? 1 : 2);

        return true;
    }
    return false;
}

void DibujarTablero(int tab[][7])
{
    system("clear");
    for(int (*p)[7] = tab; p < tab + 6 ; p++)
    {
        cout << '|';
        for(int *q = *p; q != *p + 7; q++)
        {
            if(*q == 1)
            {
                cout << "x|";
            }
            else if(*q == 2)
            {
                cout << "o|";
            }
            else
            {
                cout << " |";
            }
        }
        cout << endl;
    }
    cout << "|1|2|3|4|5|6|7|\n";
}

bool tab_lleno(int tab[][7])
{
    for(int (*p)[7] = tab; p < tab + 6 ; p++)
    {
        for(int *q = *p; q != *p + 7; q++)
        {
            if(*q == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int tablero[6][7] = 
    {
        0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,
        0,0,0,0,0,0,0
    };
    int arr_f[7] = {0,0,0,0,0,0,0};

    short jugador = 0;
    
    bool juego = true;

    DibujarTablero(tablero);

    while(juego)
    {
        if(tab_lleno(tablero))
        {
            return 0;
        }

        short a;
        cout << "Ingrese la columna: ";
        cin >> a;
        
        if(InsertarFicha(tablero, a - 1, jugador & 1)) 
        {
            jugador++;
            (*(arr_f + a - 1))++;
        }

        DibujarTablero(tablero);
        
        if(gano(tablero, *(arr_f + a - 1), a - 1))
        {
            cout << "Gano el jugador " << (jugador & 1 ? 'o' : 'x') << endl;
            juego = false;
        }
    }

    return 0;
}
