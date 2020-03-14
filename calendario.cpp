#include <iostream>

using namespace std;

int meses[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};

void dibujar_cal(int dia, int mes, int anio)
{
    cout << "L\tM\tX\tJ\tV\tS\tD\n\n";

    for(int i = dia; i; i--)
    {
        cout << "\t";
    }

    int d = 1;
    for(int i = meses[mes]; i; i--)
    {
        cout << d << "\t";
        if((d%7) == (7-dia)){cout << "\n";}
        d++;
    }
    cout << "\n";
}

int main()
{
    int  mes, anio;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;
    cout << "\n";

    dibujar_cal(5, mes, anio);

    return 0;
}
