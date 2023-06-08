#include <iostream>

using namespace std;

void poner (int *,int *,int,int);
int sacar (int *,int *);

int main ()
{
    int pila[100];
    int tope=-1;
    int max=99;
}

void poner (int * pila,int & tope, int max, int dato)
{
    if(tope<max)
    {
        tope=tope+1;
        pila[tope]=dato;
    }
    else
    {
        cout << "Desbordamiento de pila"<<endl;
    }
}

void sacar (int * pila, int & tope,int dato)
{
    if (tope>0)
    {
        int dato;
        dato=pila[tope];
        tope=tope-1;
    }
    else
    {
        cout << "Subdesbordamiento de pila"<<endl;
    }
}

void imprimir(int * pila, int & tope)
{
    cout << "Pila: ";
    for (int i=tope;i>0;i--)
    {
        cout << pila[tope];
        cout << endl;
    }
}