#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

// Alumno
struct Alumno
{
    string Nom_Apell;
    string codigo;
    float Nota1 = 0;
    float Nota2 = 0;
    float Promedio;
};

// Nodo
struct Nodo
{
    Alumno A;
    Nodo* siguiente;
};

// Opciones
int op, op1;

// Insertar
void insert_i(Nodo*&, Alumno);
void insert_f(Nodo*&, Alumno);
void insertar_ad(Nodo*&, string, Alumno);
void insertar_dd(Nodo*&, string, Alumno);

// Eliminar
void eliminar_i(Nodo*&);
void eliminar_u(Nodo*&);
void eliminar_x(Nodo*&, string);
void eliminar_ad(Nodo*&, string);
void eliminar_dd(Nodo*&, string);

// Busquedas
void modificarNodo(Nodo*);
Nodo* buscarNodo(Nodo*, string);

// Ver
void mostrar(Nodo*);

int main()
{
    Nodo* P = NULL;

    do
    {
        cout << "----------------------------------------- MENU -----------------------------------------------" << endl;
        cout << "1. Insertar Inicio" << endl;
        cout << "2. Insertar Final " << endl;
        cout << "3. Insertar Antes de" << endl;
        cout << "4. Insertar Despues de" << endl;
        cout << "5. Eliminar Inicio" << endl;
        cout << "6. Eliminar Final" << endl;
        cout << "7. Eliminar Antes de" << endl;
        cout << "8. Eliminar Despues de" << endl;
        cout << "9. Eliminar Especifico" << endl;
        cout << "10. Buscar " << endl;
        cout << "11. Mostrar" << endl;
        cout << "12. Modificar" << endl;
        cout << "13. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> op;
        system("cls");

        if (op == 1)
        {
            fflush(stdin);
            Alumno Alumno1;
            cout << "Complete los campos del Alumno: " << endl;
            cout << "Ingrese el Nombre y Apellido: ";
            getline(cin, Alumno1.Nom_Apell);
            cout << "Ingrese el Codigo: ";
            getline(cin, Alumno1.codigo);
            cout << "Ingrese La primera Nota: ";
            cin >> Alumno1.Nota1;
            cout << "Ingrese la segunda Nota: ";
            cin >> Alumno1.Nota2;
            Alumno1.Promedio = (Alumno1.Nota1 + Alumno1.Nota2) / 2;
            insert_i(P, Alumno1);
            system("pause");
            system("cls");
        }
        else if (op == 2)
        {
            fflush(stdin);
            Alumno Alumno1;
            cout << "Complete los campos del Alumno: " << endl;
            cout << "Ingrese el Nombre y Apellido: ";
            getline(cin, Alumno1.Nom_Apell);
            cout << "Ingrese el Codigo: ";
            getline(cin, Alumno1.codigo);
            cout << "Ingrese La primera Nota: ";
            cin >> Alumno1.Nota1;
            cout << "Ingrese la segunda Nota: ";
            cin >> Alumno1.Nota2;
            Alumno1.Promedio = (Alumno1.Nota1 + Alumno1.Nota2) / 2;
            insert_f(P, Alumno1);
            system("pause");
            system("cls");
        }
        else if (op == 3)
        {
            fflush(stdin);
            string clave;
            Alumno Alumno1;
            cout << "Ingrese la clave del Alumno que desea agregar antes: ";
            getline(cin, clave);
            cout << "Complete los campos del Alumno: " << endl;
            cout << "Ingrese el Nombre y Apellido: ";
            getline(cin, Alumno1.Nom_Apell);
            cout << "Ingrese el Codigo: ";
            getline(cin, Alumno1.codigo);
            cout << "Ingrese La primera Nota: ";
            cin >> Alumno1.Nota1;
            cout << "Ingrese la segunda Nota: ";
            cin >> Alumno1.Nota2;
            Alumno1.Promedio = (Alumno1.Nota1 + Alumno1.Nota2) / 2;
            insertar_ad(P, clave, Alumno1);
            system("pause");
            system("cls");
        }
        else if (op == 4)
        {
            fflush(stdin);
            string clave;
            Alumno Alumno1;
            cout << "Ingrese la clave del Alumno que desea agregar despues: ";
            getline(cin, clave);
            cout << "Complete los campos del Alumno: " << endl;
            cout << "Ingrese el Nombre y Apellido: ";
            getline(cin, Alumno1.Nom_Apell);
            cout << "Ingrese el Codigo: ";
            getline(cin, Alumno1.codigo);
            cout << "Ingrese La primera Nota: ";
            cin >> Alumno1.Nota1;
            cout << "Ingrese la segunda Nota: ";
            cin >> Alumno1.Nota2;
            Alumno1.Promedio = (Alumno1.Nota1 + Alumno1.Nota2) / 2;
            insertar_dd(P, clave, Alumno1);
            system("pause");
            system("cls");
        }
        else if (op == 5)
        {
            eliminar_i(P);
            system("pause");
            system("cls");
        }
        else if (op == 6)
        {
            eliminar_u(P);
            system("pause");
            system("cls");
        }
        else if (op == 7)
        {
            fflush(stdin);
            string clave;
            cout << "Ingrese la clave del Alumno que desea eliminar antes: ";
            getline(cin, clave);
            eliminar_ad(P, clave);
            system("pause");
            system("cls");
        }
        else if (op == 8)
        {
            fflush(stdin);
            string clave;
            cout << "Ingrese la clave del Alumno que desea eliminar despues: ";
            getline(cin, clave);
            eliminar_dd(P, clave);
            system("pause");
            system("cls");
        }
        else if (op == 9)
        {
            fflush(stdin);
            string clave;
            cout << "Ingrese la clave del Alumno que desea eliminar: ";
            getline(cin, clave);
            eliminar_x(P, clave);
            system("pause");
            system("cls");
        }
        else if (op == 10)
        {
            fflush(stdin);
            string clave;
            cout << "Ingrese la clave del Alumno que desea buscar: ";
            getline(cin, clave);
            Nodo* encontrado = buscarNodo(P, clave);
            if (encontrado != NULL)
            {
                cout << "Alumno encontrado:" << endl;
                cout << "Nombre y Apellido: " << encontrado->A.Nom_Apell << endl;
                cout << "Codigo: " << encontrado->A.codigo << endl;
                cout << "Nota 1: " << encontrado->A.Nota1 << endl;
                cout << "Nota 2: " << encontrado->A.Nota2 << endl;
                cout << "Promedio: " << encontrado->A.Promedio << endl;
            }
            else
            {
                cout << "Alumno no encontrado." << endl;
            }
            system("pause");
            system("cls");
        }
        else if (op == 11)
        {
            mostrar(P);
            system("pause");
            system("cls");
        }
        else if (op == 12)
        {
            fflush(stdin);
            string clave;
            cout << "Ingrese la clave del Alumno que desea modificar: ";
            getline(cin, clave);
            Nodo* encontrado = buscarNodo(P, clave);
            if (encontrado != NULL)
            {
                modificarNodo(encontrado);
            }
            else
            {
                cout << "Alumno no encontrado." << endl;
            }
            system("pause");
            system("cls");
        }
    } while (op != 13);

    return 0;
}

// Insertar al inicio
void insert_i(Nodo*& P, Alumno A)
{
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->A = A;

    if (P == NULL)
    {
        nuevo_nodo->siguiente = nuevo_nodo;
        P = nuevo_nodo;
    }
    else
    {
        Nodo* aux = P;
        while (aux->siguiente != P)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = P;
        P = nuevo_nodo;
    }
}

// Insertar al final
void insert_f(Nodo*& P, Alumno A)
{
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->A = A;

    if (P == NULL)
    {
        nuevo_nodo->siguiente = nuevo_nodo;
        P = nuevo_nodo;
    }
    else
    {
        Nodo* aux = P;
        while (aux->siguiente != P)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = P;
    }
}

// Insertar antes de una clave
void insertar_ad(Nodo*& P, string clave, Alumno A)
{
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->A = A;

    if (P == NULL)
    {
        cout << "Lista vacia." << endl;
        return;
    }
    else if (P->A.codigo == clave)
    {
        Nodo* aux = P;
        while (aux->siguiente != P)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = P;
        P = nuevo_nodo;
    }
    else
    {
        Nodo* aux = P;
        while (aux->siguiente != P && aux->siguiente->A.codigo != clave)
        {
            aux = aux->siguiente;
        }
        if (aux->siguiente == P)
        {
            cout << "Clave no encontrada." << endl;
            return;
        }
        nuevo_nodo->siguiente = aux->siguiente;
        aux->siguiente = nuevo_nodo;
    }
}

// Insertar despues de una clave
void insertar_dd(Nodo*& P, string clave, Alumno A)
{
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->A = A;

    if (P == NULL)
    {
        cout << "Lista vacia." << endl;
        return;
    }
    Nodo* aux = P;
    while (aux != NULL && aux->A.codigo != clave)
    {
        aux = aux->siguiente;
    }
    if (aux == NULL)
    {
        cout << "Clave no encontrada." << endl;
        return;
    }
    nuevo_nodo->siguiente = aux->siguiente;
    aux->siguiente = nuevo_nodo;
}

// Eliminar al inicio
void eliminar_i(Nodo*& P)
{
    if (P == NULL)
    {
        cout << "Lista vacia." << endl;
        return;
    }
    else if (P->siguiente == P)
    {
        delete P;
        P = NULL;
    }
    else
    {
        Nodo* aux = P;
        while (aux->siguiente != P)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = P->siguiente;
        Nodo* temp = P;
        P = P->siguiente;
        delete temp;
    }
}

// Eliminar al final
void eliminar_u(Nodo*& P)
{
    if (P == NULL)
    {
        cout << "Lista vacia." << endl;
        return;
    }
    else if (P->siguiente == P)
    {
        delete P;
        P = NULL;
    }
    else
    {
        Nodo* aux = P;
        while (aux->siguiente->siguiente != P)
        {
            aux = aux->siguiente;
        }
        Nodo* temp = aux->siguiente;
        aux->siguiente = P;
        delete temp;
    }
}

// Eliminar antes de una clave
void eliminar_ad(Nodo*& P, string clave)
{
    if (P == NULL)
    {
        cout << "Lista vacia." << endl;
        return;
    }
    else if (P->A.codigo == clave)
    {
        Nodo* aux = P;
        while (aux->siguiente != P)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = P->siguiente;
        Nodo* temp = P;
        P = P->siguiente;
        delete temp;
    }
    else
    {
        Nodo* aux = P;
        while (aux->siguiente != P && aux->siguiente->A.codigo != clave)
        {
            aux = aux->siguiente;
        }
        if (aux->siguiente == P)
        {
            cout << "Clave no encontrada." << endl;
            return;
        }
        Nodo* temp = aux->siguiente;
        aux->siguiente = temp->siguiente;
        delete temp;
    }
}

// Eliminar despues de una clave
void eliminar_dd(Nodo*& P, string clave)
{
    if (P == NULL)
    {
        cout << "Lista vacia." << endl;
        return;
    }
    Nodo* aux = P;
    while (aux != NULL && aux->A.codigo != clave)
    {
        aux = aux->siguiente;
    }
    if (aux == NULL)
    {
        cout << "Clave no encontrada." << endl;
        return;
    }
    Nodo* temp = aux->siguiente;
    if (temp == P)
    {
        aux->siguiente = temp->siguiente;
        P = aux->siguiente;
    }
    else
    {
        aux->siguiente = temp->siguiente;
    }
    delete temp;
}

// Eliminar especifico
void eliminar_x(Nodo*& P, string clave)
{
    if (P == NULL)
    {
        cout << "Lista vacia." << endl;
        return;
    }
    else if (P->A.codigo == clave)
    {
        Nodo* aux = P;
        while (aux->siguiente != P)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = P->siguiente;
        delete P;
        P = aux->siguiente;
    }
    else
    {
        Nodo* aux = P;
        while (aux->siguiente != P && aux->siguiente->A.codigo != clave)
        {
            aux = aux->siguiente;
        }
        if (aux->siguiente == P)
        {
            cout << "Clave no encontrada." << endl;
            return;
        }
        Nodo* temp = aux->siguiente;
        aux->siguiente = temp->siguiente;
        delete temp;
    }
}

// Buscar nodo
Nodo* buscarNodo(Nodo* P, string clave)
{
    if (P == NULL)
    {
        return NULL;
    }
    Nodo* aux = P;
    do
    {
        if (aux->A.codigo == clave)
        {
            return aux;
        }
        aux = aux->siguiente;
    } while (aux != P);
    return NULL;
}

// Modificar nodo
void modificarNodo(Nodo* nodo)
{
    fflush(stdin);
    cout << "Ingrese el Nombre y Apellido: ";
    getline(cin, nodo->A.Nom_Apell);
    cout << "Ingrese La primera Nota: ";
    cin >> nodo->A.Nota1;
    cout << "Ingrese la segunda Nota: ";
    cin >> nodo->A.Nota2;
    nodo->A.Promedio = (nodo->A.Nota1 + nodo->A.Nota2) / 2;
}

// Mostrar lista
void mostrar(Nodo* P)
{
    if (P == NULL)
    {
        cout << "Lista vacia." << endl;
        return;
    }
    Nodo* aux = P;
    do
    {
        cout << "Nombre y Apellido: " << aux->A.Nom_Apell << endl;
        cout << "Codigo: " << aux->A.codigo << endl;
        cout << "Nota 1: " << aux->A.Nota1 << endl;
        cout << "Nota 2: " << aux->A.Nota2 << endl;
        cout << "Promedio: " << aux->A.Promedio << endl;
        aux = aux->siguiente;
    } while (aux != P);
}
