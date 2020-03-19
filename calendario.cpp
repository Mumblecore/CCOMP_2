#include <iostream>

using namespace std;

int meses[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};

bool bisiesto(int anio)
{
    return ((!(anio%4) && anio%100)||!(anio%400)) ? 1 : 0;
}

int cal_dia(int mes, int anio)
{
    int dia;
    dia = anio - 1582;

    int inc_bis = (dia + 1)/4;

    for(int i = 1; i < mes; i++)
    {
       dia += meses[i];
    }

    if(bisiesto(anio) && mes >2){dia++;}

    return (dia + inc_bis + 4)%7;
}

void dibujar_cal(int dia, int mes)
{
    cout << "L\tM\tX\tJ\tV\tS\tD\n\n";

    for(int i = dia; i; i--)
    {
        cout << "\t";
    }

    int d = 0;
    for(int i = meses[mes]; i; i--)
    {
        cout << d+1 << "\t";
        if((d%7)+1 == (7-dia)){cout << "\n";}
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

    cout << bisiesto(anio) << endl;
    if(mes == 2 && bisiesto(anio))
    {
        dibujar_cal(cal_dia(2, anio), 0);
    }else{
        dibujar_cal(cal_dia(mes, anio), mes);
    }
    return 0;
}
