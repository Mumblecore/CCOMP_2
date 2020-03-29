#include <iostream>
#include <string>

using namespace std;

string uni[16]=
{
    "cero", "un", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez", "once", "doce", "trece", "catorce", "quince"
};

string dece[10]=
{
    "dieci", "veinti", "veinte ", "treinta ", "cuarenta ", "cincuenta ", "sesenta ", "setenta ", "ochenta ", "noventa "
};

string cen[10]=
{
  "cien ", "ciento ", "doscientos ", "trescientos ", "cuatrocientos ", "quinientos ", "seiscientos ", "setecientos ", "ochocientos ", "novecientos "
};

string mill[6]=
{
    " millones ", " mil ", " billones ", " un millon " ,"", " un billon "
};

int trio_cant(long n)
{
    int c = 1;
    while(n/1000)
    {
        n /= 1000;
        c++;
    }
    return c;
}


int trio_f(long n, int x)
{
    long m = 1000;
    long d = 1;

    while(x>1)
    {
        m *= 1000;
        d *= 1000;
        x--;
    }

    return int((n%m)/d);
}

string trio_anl(int x)
{
    string trio = "";

    if(x)
    {
        if(x == 100){return cen[0];}                //evaluar cien(caso especial)

        if(x / 100){trio += cen[x/100];}            //evaluar centenas

        if(x%100 == 20){return (trio += dece[2]);}  //20(caso especial)

        if(x%100 > 29)
        {
            trio += dece[(x % 100)/10];
                if(x%10)
                {
                    trio = trio + "y " + uni[x%10];
                }
        }
        else if(x%100 > 15)
        {
            trio += dece[(x%100)/10 - 1];
            trio += uni[x % 10];
        }
        else if(x%100 > 0){trio += uni[x%100];}
    }

    return trio;
}

int main()
{
    cout << "Ingrese: ";
    long n;
    cin >> n;

    for(int i = 4; i > -1; i=i-2)
    {
        if(trio_cant(n) >  i)
        {
            if(trio_f(n,i+2))
            {
                cout << ((trio_f(n,i+2) != 1) ? trio_anl(trio_f(n,i+2)) : "\0") << mill[1];
            }
            if(trio_f(n,i+1) && i>1)
            {
                if(trio_f(n,i+1) == 1)
                {
                    cout << mill[i+1];
                }else{
                    cout << trio_anl(trio_f(n,i+1)) << mill[i-2];
                }
            }
        }
    }

    cout << trio_anl(trio_f(n,1));
    if(trio_f(n,1)%10 == 1 && trio_f(n,1) != 11)
    {
        cout << "o";
    }
    cout << "\n";
    return 0;
}
