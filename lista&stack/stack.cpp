#include <iostream>

using namespace std;
//Reutilizo el nodo de la lista enlazada
template <typename T>
struct nodo
{
    T valor;
    nodo<T>* next;
    nodo(T v, nodo<T>* n = nullptr){
        valor = v;
        next = n;
    }
};

template <typename T>
class Pila
{
    nodo<T>* top = nullptr;
public:
    void push(T valor);
    T pop();
    bool vacio();
    ~Pila();
    void print();
};

template <typename T>
void Pila<T>::push(T valor)
{
    top = new nodo<T>(valor,top);
}
//retorna 0 si la pila esta vacia lo que no me convence mucho
//se podria utilizar un try-catch o cambiar el tipo de funcion
//a bool o void y que el elemento a quitar pase por referencia
template <typename T>
T Pila<T>::pop()
{
    if(!vacio())
    {
        T val = top->valor;
    
        nodo<T> *t = top;
        top = t->next;
        delete t;

        return val;
    }
    cout << "\nla pila esta vacia\n";
    return 0;
}

template <typename T>
bool Pila<T>::vacio()
{
    return !top;
}

template <typename T>
Pila<T>::~Pila()
{
    while(top)
        pop();
}

template <typename T>
void Pila<T>::print()
{
    cout << "TOP -> ";

    for(nodo<T> *t = top; t; t = t->next)
        cout << t->valor << " -> ";

    cout << "NULL" << endl;
}
//============================== MENU ==============================
template <typename T>
void print_options(Pila<T> &miPila)
{
    system("clear");
    cout << "<============ STACK ============>\n\n";
    miPila.print();
    cout << "\n1. Push New Element\n";
    cout << "2. Pop Last Element\n";
    cout << "3. Salir\n";
}

template <typename T>
void menu_acciones(Pila<T> &miPila)
{
    print_options(miPila);

    short op;
    cin >> op;
    switch (op)
    {
    case 1:
        T elm;
        cout << "\nIngrese el elemento: ";
        cin >> elm;
        miPila.push(elm);
        break;
    case 2:
        elm = miPila.pop();
        print_options(miPila);
        cout << "\n\nUsted extrajo el elemento: " << elm;
        cin.ignore();
        cin.ignore();
        break;
    case 3:
        system("clear");
        return;
    }
    menu_acciones(miPila);
}

int main()
{
menu:
    system("clear");
    cout << "<============ STACK ============>\n\n";
    cout << "1. Entero 32-bits\n";
    cout << "2. Entero 16-bits\n";
    cout << "3. Simbolo ASCII 8-bits\n";
    cout << "4. Punto flotante 32-bits\n";
    cout << "5. Doble punto flotante 64-bits\n";
    cout << "6. Booleano 8-bits\n";
    cout << "7. Salir\n\n";
    cout << "Seleccione el tipo de dato que almacenara su Stack: ";
    short tipo;
    cin >> tipo;
    switch (tipo)
    {
    case 1:{
        Pila<int> miPila;
        menu_acciones(miPila);
        break;}
    case 2:{
        Pila<short> miPila;
        menu_acciones(miPila);
        break;}
    case 3:{
        Pila<char> miPila;
        menu_acciones(miPila);
        break;}
    case 4:{
        Pila<float> miPila;
        menu_acciones(miPila);
        break;}
    case 5:{
        Pila<double> miPila;
        menu_acciones(miPila);
        break;}
    case 6:{
        Pila<bool> miPila;
        menu_acciones(miPila);
        break;}
    case 7:
        break;
    default:
        goto menu;
    }
    return 0;
}
