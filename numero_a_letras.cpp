#include <iostream>
#include <string>

using namespace std;

string uni[16]=
{
    "cero ", "uno ", "dos ", "tres ", "cuatro ", "cinco ", "seis ", "siete ", "ocho ", "nueve ", "diez ", "once ", "doce ", "trece ", "catorce ", "quince "
};

string dece[10]=
{
    "dieci", "veinti", "veinte ", "treinta ", "cuarenta ", "cincuenta ", "sesenta ", "setenta ", "ochenta ", "noventa "
};

string cen[10]=
{
  "cien ", "ciento ", "doscientos ", "trescientos ", "cuatrocientos ", "quinientos ", "seiscientos ", "setecientos ", "ochocientos ", "novecientos "
};

int trio_num(u_long n)
{
    int c = 1;
    while(n/1000)
    {
        n /= 1000;
        c++;
    }
    return c;
}

int trio_f(u_long n, int x)
{
    u_long m = 1000;
    u_long d = 1;
    
    while(x>1)
    {
        m *= 1000;
        d *= 1000;
        x--;
    }
    
    return int((n%m)/d);
}

string trio_anal(int x)
{
    string trio = "";
    
    if(x)
    {
        if(x == 100){return cen[0];}    //evaluar cien
        if(x / 100)                     //evaluar centenas
        {
            trio += cen[x/100];
        }
        
        if(x%100 >= 15)                 //evaluar decenas
        {
            if(x%100 < 20)
            {
                trio += dece[0];
                trio += uni[x % 10];
            }
            else if(x%100 < 30)
            {
                trio += dece[1];
                trio += uni[x % 10];
            }
            else
            {
                trio += dece[(x % 100)/10];
                if(x%10)
                {
                    trio = trio + "y " + uni[x%10];
                }
            }
        }
        else
        {
            trio += uni[x];
            
        }
    }
    
    return trio;
}

int main()
{
    cout << "Ingrese: ";
    u_long n;
    cin >> n;
  
    if(trio_num(n) > 4)
    {
        if(trio_f(n,6))
        {
            cout << trio_anal(trio_f(n,4)) << " mil ";
        }
        if(trio_f(n,5))
        {
            if(trio_f(n,5) == 1)
            {
                cout << "un billon ";
            }else{
                cout << trio_anal(trio_f(n,5)) << " billones ";
            }
        }
    }
    
    if(trio_num(n) > 2)
    {
        if(trio_f(n,4))
        {
            cout << trio_anal(trio_f(n,4)) << " mil ";
        }
        if(trio_f(n,3))
        {
            if(trio_f(n,3) == 1)
            {
                cout << "un millon ";
            }else{
                cout << trio_anal(trio_f(n,3)) << " millones ";
            }
        }
    }
    
    if(trio_f(n,2))
    {
        cout << trio_anal(trio_f(n,2)) << " mil ";
    }
    cout << trio_anal(trio_f(n,1)) << endl;
    
    return 0;
}
