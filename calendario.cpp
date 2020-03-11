#include <iostream>

using namespace std;

int main()
{
    cout << "\n=====================CALENDARIO====================\n";
    int  mes, anio;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;
    cout << "\n";

    cout << "L\tM\tX\tJ\tV\tS\tD\n";
    for(int i = 1; i < 31; i++)
    {
        if((i-1)%7 == 0)
        {
            cout << "\n";
        }
        cout << i << "\t";
    }

    return 0;
}
