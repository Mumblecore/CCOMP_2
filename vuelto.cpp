#include <iostream>

using namespace std;

int main()
{
    //MONEDAS
    int ent[] = {200, 100, 50, 20, 10, 5, 2, 1};
    float dec[] = {0.5, 0.2, 0.1};

    float n;

    cout << "Ingrese el monto: ";
    cin >> n;
    cout << "\nmonto\tcant.\n";

    int n_int = int(n);
    float n_dec = n - n_int;

    for(int i = 0; n_int > 0; i++)
    {
        int v = n_int/ent[i];
        if(v){cout << ent[i] << "\t" << v << "\n";}
        n_int -= v*ent[i];
    }

    for(int i = 0; i < 3; i++)
    {
        int v = 0;
        while(n_dec >= dec[i])
        {
            v++;
            n_dec -= dec[i];
        }
        if(v){cout << dec[i] << "\t" << v << "\n";}
    }


    return 0;
}
