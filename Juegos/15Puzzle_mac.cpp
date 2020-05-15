#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*======================FUNCION PARA MOSTRAR EK ARRAY EN CONSOLA========================*/
void print(int arr[][4])
{
    system("clear");

    for(int (*p)[4] = arr; p < arr + 4; p++)
    {
        cout << "|";
        for(int *q = *p; q < *p + 4; q++)
        {
            if(*q<10)
            {
                cout << " ";
            }
            if(*q)
            {
                cout << *q << "|";
            }else
            {
                cout << " |";
            }
        }
        cout << endl;
    }
}
/*=================================CONDICION PARA GANAR=================================*/
bool ordenado(int arr[][4])
{
    for(int *p = *arr; p != *arr + 14; p++)
    {
        if(*p>*(p+1))
        {
            return false;
        }
    }
    return true;
}
/*==============================FUNCIONES DE MOVIMIENTO=================================*/
void mov_hor(int arr[4][4], bool dir, int *pos)
{
    if(dir)
    {
        if(*pos<3)
        {
            swap(*(*(arr + *(pos+1)) + *pos),*(*(arr + *(pos+1)) + *pos + 1));
            *pos = *pos + 1;
        }
    }
    else
    {
        if(*pos>0)
        {
            swap(*(*(arr + *(pos+1)) + *pos),*(*(arr + *(pos+1)) + *pos - 1));
            *pos = *pos - 1;
        }
    }
}

void mov_ver(int arr[4][4], bool dir, int *pos)
{
    if(dir)
    {
        if(*(pos+1)>0)
        {
            swap(*(*(arr + *(pos+1)) + *pos),*(*(arr + *(pos+1) - 1) + *pos));
            *(pos+1) = *(pos+1) - 1;
        }
    }
    else
    {
        if(*(pos+1)<3)
        {
            swap(*(*(arr + *(pos+1)) + *pos),*(*(arr + *(pos+1) + 1) + *pos));
            *(pos+1) = *(pos+1) + 1;
        } 
    }
}
/*========================FUNCION PARA DESORDENAR EL ARRAY===========================*/
void desordenar(int arr[][4], int* pos)
{
    srand (time(NULL));
    int c = rand() % 60 + 50;
    while(c--)
    {
        srand (time(NULL));
        mov_hor(arr,rand()%2, pos);
        mov_ver(arr,rand()%2, pos);
    }
}
/*======================================MAIN=========================================*/
int main()
{
    int puzzle[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
    int pos[2] = {3,3};     //array que almacena la posicion del pivote (x,y)

    bool juego = 1;

    desordenar(puzzle,pos);
/*=================================BUCLE PRINCIPAL===================================*/
    while(juego)
    {
        print(puzzle,4);

        if(ordenado(puzzle)) //comprobar si ya se gano
        {
            cout << "\n";
            cout << "+===============================================+\n";
            cout << "|              FELICIDADES, GANO!!!             |\n";
            cout << "+===============================================+\n";
            juego = 0;
        }
        else //sino, se juega
        {
            char control;
            cout << "\n";
            cin >> control;

            switch (control)
            {
            case 'w':
                mov_ver(puzzle,1,pos);
                break;
            
            case 'a':
                mov_hor(puzzle,0,pos);
                break;
            
            case 's':
                mov_ver(puzzle,0,pos);
                break;
            
            case 'd':
                mov_hor(puzzle,1,pos);
                break;
            
            default:
                break;
            }
        }
        
    }

    return 0;
}
