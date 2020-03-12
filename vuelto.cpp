#include <iostream>

using namespace std;

int main()
{
    //MONEDAS
    float mon[] = {2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    float n;

    cout << "Ingrese el monto: ";
    cin >> n;
    cout << "\nmonto\tcant.\n";

    int n_int = int(n*10);

    for(int i = 0; n_int > 0; i++)
    {
        int v = n_int/mon[i];
        if(v){cout << mon[i]/10 << "\t" << v << "\n";}
        n_int -= v*mon[i];
    }

    return 0;
}
