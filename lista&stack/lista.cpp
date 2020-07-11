#include <iostream>

using namespace std;

template <typename T>
struct nodo
{
    T valor;
    nodo<T>* next;
    nodo<T>* prev;
    nodo(T v, nodo<T>* n = nullptr, nodo<T>* p = nullptr){
        valor = v;
        next = n;
        prev = p;
    }
};

template <class T>
bool asc(T a, T b){return a < b;}
template <class T>
bool des(T a, T b){return a > b;}

template <class T>
class le
{
    nodo<T>* head = nullptr;
    bool(*orden)(T a, T b);
public://por default la lista es ascendente
    le(bool(*o)(T a, T b) = &asc){
        orden = o;
    }
    void add(T valor);
    void remove(T valor);
    bool find(T bus, nodo<T>*& pos);
    void print();
    ~le();
};

template <class T>
bool le<T>::find(T bus, nodo<T>*& pos)
{
    nodo<T>* t;
    for(t = head, pos = 0; t && orden(t->valor, bus); pos = t, t = t->next);
    if(t && t->valor==bus)
        return true;
    return false;
}

template <class T>
void le<T>::add(T valor)
{
    nodo<T> *p;
    if(!head)
        head = new nodo<T>(valor);
    else
    {
        if(!find(valor,p))
        {
            if(!p){
                head = new nodo<T>(valor,head);
                head->next->prev = head;
            }
            else{
                p->next = new nodo<T>(valor,p->next,p);
                if(p->next->next)
                    p->next->next->prev = p->next;
            }
        }
    }
}

template <class T>
void le<T>::print()
{
    nodo<T> *t;
    cout << "HEAD";
    for(t = head;t && t->next; t = t->next)
        cout << " -> " << t->valor;
    if(t)
        cout << " -> " << t->valor;
    cout << " -> NULL -> ";
    for(; t; t = t->prev)
        cout << t->valor << " -> ";
    cout << "HEAD" <<endl;
}

template <class T>
void le<T>::remove(T valor)
{
    nodo<T> *p,*t;

    if(find(valor,p))
    {
        if(p)
        {
            t = p->next;
            p->next = t->next;
            if(t->next)
                t->next->prev = p;
        }
        else
        {
            t = head;
            head = t->next;
            if(t->next)
                t->next->prev = 0;
        }
        delete t;
    }
}

template<class T>
le<T>::~le()
{
    while(head)
        remove(head->valor);
}
//============================== MENU ==============================

template <typename T>
void menu_acciones(le<T> &lista)
{
    system("clear");
    cout << "<============== LISTA ENLAZADA ==============>\n\n";
    lista.print();
    cout << "\n1. Insertar Elemento\n";
    cout << "2. Eliminar Elemento\n";
    cout << "3. Salir\n";

    short op;
    cin >> op;
    switch (op)
    {
    case 1:
        T elm;
        cout << "\nIngrese el elemento: ";
        cin >> elm;
        lista.add(elm);
        break;
    case 2:
        cout << "\nIngrese el elemento: ";
        cin >> elm;
        lista.remove(elm);
        break;
        break;
    case 3:
        system("clear");
        return;
    }
    menu_acciones(lista);
}

int main()
{
menu:
    system("clear");
    cout << "<============== LISTA ENLAZADA ==============>\n\n";
    cout << "1. Entero 32-bits\n";
    cout << "2. Entero 16-bits\n";
    cout << "3. Simbolo ASCII 8-bits\n";
    cout << "4. Punto flotante 32-bits\n";
    cout << "5. Doble punto flotante 64-bits\n";
    cout << "6. Booleano 8-bits\n";
    cout << "7. Salir\n\n";
    cout << "Seleccione el tipo de dato que almacenara su Lista Enlazada: ";
    short tipo;
    cin >> tipo;
    cout << "0. Ascendente\n";
    cout << "1. Descendente\n";
    cout << "Seleccione orden de su Lista Enlazada: ";
    short orden;
    cin >> orden;
    switch (tipo)
    {
    case 1:{
        if(orden){
            le<int> lista(&des);
            menu_acciones(lista);
        }else
        {
            le<int> lista;
            menu_acciones(lista);
        }
        break;}
    case 2:{
//a partir de aqui uso operador ternario para acortar el codigo,
//lo malo es que hay q especificar el tipo de dato
        le<short> lista(orden ? &des<short> : &asc<short>);
        menu_acciones(lista);
        break;}
    case 3:{
        le<char> lista(orden ? &des<char> : &asc<char>);
        menu_acciones(lista);
        break;}
    case 4:{
        le<float> lista(orden ? &des<float> : &asc<float>);
        menu_acciones(lista);
        break;}
    case 5:{
        le<double> lista(orden ? &des<double> : &asc<double>);
        menu_acciones(lista);
        break;}
    case 6:{
        le<bool> lista(orden ? &des<bool> : &asc<bool>);
        menu_acciones(lista);
        break;}
    case 7:
        break;
    default:
        goto menu;
    }
    return 0;
}
