#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

//Alumno
struct Alumno
{
    string Nom_Apell;
    string codigo;
    float Nota1=0;
    float Nota2=0;
    float Promedio;
}Alumno1;


//Nodo
struct Nodo
{
    Alumno A;
    Nodo* siguiente;
	Nodo* anterior;
}nodo;

//Opciones
int op,op1;

//Crear
void crear_i(Nodo*&, Nodo*&);
void crear_f(Nodo*&, Nodo*&);
//Insertar
void insert_i(Nodo *&, Nodo*&);
void insert_f(Nodo *&, Nodo *&);
void insertar_ad(Nodo *&,Nodo *&,string);
void insertar_dd(Nodo*&,Nodo *&,string); 
//Eliminar
void eliminar_i(Nodo *&,Nodo*&);
void eliminar_u(Nodo*&, Nodo*&);
void eliminar_x(Nodo*&, Nodo*&,string);
//Busqueda
void buscar_ld(Nodo*&,string);
//Modificar
void modificar(Nodo *&,string);

//Ver
void mostrar(Nodo *&);

	//Cabeza
    Nodo *P = NULL;
    //Final
    Nodo *F = NULL;
    //Busqueda
    Nodo *B =NULL;
int main ()
{
    
    do
    {
        cout << "----------------------------------------- MENU -----------------------------------------------" << endl;
        cout << "1. Crear por el Inicio" << endl;
        cout << "2. Crear por el Final " << endl;
		cout << "3. Insertar Inicio"<<endl;
		cout << "4. Insertar Final"<<endl;
        cout << "5. Insertar Antes de" << endl;
		cout << "6. Insertar Despues de"<<endl;
		cout << "7. Eliminar Inicio"<<endl;
		cout << "8. Eliminar Final"<<endl;
		cout << "9. Eliminar Especifico"<<endl;
        cout << "10. Buscar "<<endl;
        cout << "11. Mostrar" << endl;
		cout << "12. Modificar"<<endl;
        cout << "13. Salir" << endl;	
        cout << "Ingrese opcion: "; cin >> op;
        system("cls");
        if(op==1)
        {
        	fflush(stdin);
            crear_i(P,F);
            system("pause");
            system("cls");
        }
        else if(op==2)
        {   
            fflush(stdin);
			crear_f(P, F);
            system("pause");
            system("cls");
        }
		else if (op==3)
		{
			fflush(stdin);
			insert_i(P, F);
            system("pause");
            system("cls");
		}
		else if (op==4)
		{
			fflush(stdin);
			insert_f(P, F);
            system("pause");
            system("cls");
		}
        else if(op==5)
        {
			string refer;
			fflush(stdin);
			cout << "Ingrese el codigo del alumno de referencia: "; cin >> refer;
			insertar_ad(P, F,refer);
			system("pause");
			system("cls");
        }
        else if(op==6)
        {
			string refer;
			fflush(stdin);
			cout << "Ingrese el codigo del alumno de referencia: "; cin >> refer;
			insertar_dd(P, F, refer);
			system("pause");
			system("cls");
        }
		else if (op==7)
		{
			fflush(stdin);
			eliminar_i(P, F);
			system("pause");
			system("cls");
		}
		else if (op==8)
		{
			fflush(stdin);
			eliminar_u(P, F);
			system("pause");
			system("cls");
		}
		else if (op==9)
		{
			string ref;
			fflush(stdin);
			cout << "Ingrese el codigo a eliminar: "; cin >> ref;
			eliminar_x(P,F,ref);
			system("pause");
			system("cls");
		}
        else if (op==10)
        {
			string ref;
			fflush(stdin);
			cout << "Ingrese el codigo a buscar: "; cin>>ref;
			buscar_ld(P,ref);
			system("pause");
            system("cls");
        }
        else if (op==11)
        {
			mostrar(P);
			system("pause");
            system("cls");
        }
		else if (op==12)
		{
			string ref;
			fflush(stdin);
			cout << "Ingrese el codigo a modificar: "; cin>>ref;
			modificar(P,ref);
			system("pause");
            system("cls");
		}
    } while (op!=13);   
    
    return 0;
}

void crear_i(Nodo*& P, Nodo*& F)
{
	int op = 1;
	do
	{
		fflush(stdin);
		Nodo* q = new Nodo();
		//lee info de q
		cout << "Complete los campos del Alumno a ingresar: " << endl;
		cout << "Ingrese el Nombre y Apellido: "; getline(cin, q->A.Nom_Apell);
		cout << "Ingrese el Codigo: "; getline(cin, q->A.codigo);
		cout << "Ingrese La primera Nota: "; cin >> q->A.Nota1;
		cout << "Ingrese la segunda Nota: "; cin >> q->A.Nota2;
		q->A.Promedio = (q->A.Nota1 + q->A.Nota2) / 2;
		//termina de leer
		q->anterior = NULL;
		q->siguiente = P;
		if (P == NULL)
        {
            F = q;
            q->siguiente = q;
        }
        else
        {
            P->anterior = q;
            q->siguiente = P;
        }
		P = q;
		cout << "\nQuiere agregar mas nodos?" << endl;
		cout << "1. Si" << endl;
		cout << "2. No" << endl;
		cout << "Ingrese su opcion: "; cin >> op;
	} while (op == 1);
}

void crear_f(Nodo*& P, Nodo*& F)
{
	int op = 1;
	do
	{
		fflush(stdin);
		Nodo* q = new Nodo();
		//lee info de q
		cout << "Complete los campos del Alumno a ingresar: " << endl;
		cout << "Ingrese el Nombre y Apellido: "; getline(cin, q->A.Nom_Apell);
		cout << "Ingrese el Codigo: "; getline(cin, q->A.codigo);
		cout << "Ingrese La primera Nota: "; cin >> q->A.Nota1;
		cout << "Ingrese la segunda Nota: "; cin >> q->A.Nota2;
		q->A.Promedio = (q->A.Nota1 + q->A.Nota2) / 2;
		//termina de leer
		q->siguiente = NULL;
		q->anterior = F;
		if (P == NULL)
        {
            P = q;
            q->siguiente = q; // Hacer que el siguiente apunte al mismo nodo
        }
        else
        {
            F->siguiente = q;
            q->anterior = F;
            q->siguiente = P; // Hacer que el siguiente apunte al primer nodo
        }
		F = q;
		cout << "\nQuiere agregar mas nodos?" << endl;
		cout << "1. Si" << endl;
		cout << "2. No" << endl;
		cout << "Ingrese su opcion: "; cin >> op;
	} while (op == 1);
}

void insert_i(Nodo *&P, Nodo*&F)
{
	fflush(stdin);
    Nodo *q = new Nodo();
	//lee info de q
	cout << "Complete los campos del Alumno a ingresar: " << endl;
	cout << "Ingrese el Nombre y Apellido: "; getline(cin, q->A.Nom_Apell);
	cout << "Ingrese el Codigo: "; getline(cin, q->A.codigo);
	cout << "Ingrese La primera Nota: "; cin >> q->A.Nota1;
	cout << "Ingrese la segunda Nota: "; cin >> q->A.Nota2;
	q->A.Promedio = (q->A.Nota1 + q->A.Nota2) / 2;
	cout << "\n";
	//termina de leer
	q->anterior = NULL;
	q->siguiente = P;
	if (P == NULL)
    {
        F = q;
        q->siguiente = q; // Hacer que el siguiente apunte al mismo nodo
    }
    else
    {
        P->anterior = q;
        q->siguiente = P; // Hacer que el siguiente apunte al primer nodo
    }
    P = q;

}

void insert_f(Nodo *&P, Nodo *&F)
{
	fflush(stdin);
	Nodo* q = new Nodo();
	//lee info de q
	cout << "Complete los campos del Alumno a ingresar: " << endl;
	cout << "Ingrese el Nombre y Apellido: "; getline(cin, q->A.Nom_Apell);
	cout << "Ingrese el Codigo: "; getline(cin, q->A.codigo);
	cout << "Ingrese La primera Nota: "; cin >> q->A.Nota1;
	cout << "Ingrese la segunda Nota: "; cin >> q->A.Nota2;
	q->A.Promedio = (q->A.Nota1 + q->A.Nota2) / 2;
	cout << "\n";
	//termina de leer
	q->siguiente = NULL;
	q->anterior = F;
	if (P == NULL)
    {
        P = q;
        q->siguiente = q; // Hacer que el siguiente apunte al mismo nodo
    }
    else
    {
        F->siguiente = q;
        q->anterior = F;
        q->siguiente = P; // Hacer que el siguiente apunte al primer nodo
    }
    F = q;
}

void insertar_ad(Nodo*&P, Nodo *&F,string ref)
{
	Nodo* q = new Nodo();
	if (P != NULL)
	{
		q = P;
		int cen = 0;
		while ((q->A.codigo != ref) && (cen == 0))
		{
			if (q->siguiente != NULL)
			{
				q = q->siguiente;
			}
			else
			{
				cen = 1;
			}
		}
		if (cen == 0)
		{
			fflush(stdin);
			Nodo* x = new Nodo();
			//Info
			cout << "Complete los campos del Alumno a ingresar: " << endl;
			cout << "Ingrese el Nombre y Apellido: "; getline(cin, x->A.Nom_Apell);
			cout << "Ingrese el Codigo: "; getline(cin, x->A.codigo);
			cout << "Ingrese La primera Nota: "; cin >> x->A.Nota1;
			cout << "Ingrese la segunda Nota: "; cin >> x->A.Nota2;
			x->A.Promedio = (x->A.Nota1 + x->A.Nota2) / 2;
			cout << "\n";
			//
			Nodo* r = new Nodo();
			x->siguiente = q;
			r = q->anterior;
			x->anterior = r;
			q->anterior = x;
			if (P != q)
			{
				r->siguiente = x;
			}
			else
			{
				P = x;
			}
		}
		else
		{
			cout << "No existe el referencial" << endl;
		}
	}
	else
	{
		cout << "Lista vacia" << endl;
	}
}


void insertar_dd(Nodo*& P, Nodo*&F,string ref)
{
	Nodo* q = new Nodo();
	if (P != NULL)
	{
		q = P;
		int cen = 0;
		while ((q->A.codigo != ref) && (cen == 0))
		{
			if (q->siguiente != NULL)
			{
				q = q->siguiente;
			}
			else
			{
				cen = 1;
			}
		}
		if (cen == 0)
		{
			fflush(stdin);
			Nodo* x = new Nodo();
			//Info
			cout << "Complete los campos del Alumno a ingresar: " << endl;
			cout << "Ingrese el Nombre y Apellido: "; getline(cin, x->A.Nom_Apell);
			cout << "Ingrese el Codigo: "; getline(cin, x->A.codigo);
			cout << "Ingrese La primera Nota: "; cin >>	x->A.Nota1;
			cout << "Ingrese la segunda Nota: "; cin >> x->A.Nota2;
			x->A.Promedio = (x->A.Nota1 + x->A.Nota2) / 2;
			cout << "\n";
			//
			Nodo* r = new Nodo();
			r = q->siguiente;
			x->anterior = q;
			q->siguiente = x;
			x->siguiente = r;
			if (q==F)
			{
				F = x;
			}
			else
			{
				r->anterior = x;
			}
		}
		else
		{
			cout << "No existe el referencial" << endl;
		}
	}
	else
	{
		cout << "Lista vacia" << endl;
	}
}


void mostrar(Nodo *&P)
{
    Nodo* temp = P;
  
    if (temp == NULL)
    {
        cout << "La lista está vacía." << endl;
        return;
    }
  
    do
    {
        cout << "Nombre: " << temp->A.Nom_Apell << endl;
        cout << "Edad: " << temp->A.codigo << endl;
        cout << "Promedio: " << temp->A.Promedio << endl;
        cout << endl;
  
        temp = temp->siguiente;
  
    } while (temp != P);
}

void eliminar_i(Nodo*& P, Nodo*& F)
{
	Nodo *q = new Nodo();
	if (P != NULL)
	{
		q = P;
		P = P->siguiente;
		if (q == F)
		{
			F = P;
		}
		else
		{
			P->anterior = NULL;
		}
		delete q;
	}
	else
	{
		cout << "Lista vacia" << endl;
	}
}

void eliminar_u(Nodo*& P, Nodo*& F)
{
	Nodo* q = new Nodo();
	if (P != NULL)
	{
		q = F;
		F = F->anterior;
		if (P==q)
		{
			P = F;
		}
		else
		{
			F->siguiente = NULL;
		}
		delete q;
	}
	else
	{
		cout << "Lista vacia" << endl;
	}
}

void eliminar_x(Nodo*& P, Nodo*& F,string ref)
{
	Nodo* q = new Nodo();
	int cen = 0;
	Nodo* r = new Nodo();
	Nodo* t = new Nodo();
	if (P != NULL)
	{
		q = P;
		cen = 0;
		while ((q->A.codigo != ref) && (cen == 0))
		{
			if (q->siguiente != NULL)
			{
				q = q->siguiente;
			}
			else
			{
				cen = 1;
			}
		}
		if (cen == 0)
		{
			if (P == F)
			{
				P = NULL;
				F = NULL;
			}
			else
			{
				if (P == q)
				{
					P = P->siguiente;
					P->anterior = NULL;
				}
				else
				{
					if (q == F)
					{
						F = F->anterior;
						F->siguiente = NULL;
					}
					else
					{
						r = q->anterior;
						t = q->siguiente;
						r->siguiente = t;
						t->anterior = r;
					}
				}
			}
			delete q;
		}
		else
		{
			cout << "No existe el referencial" << endl;
		}
	}
	else
	{
		cout << "Lista vacia" << endl;
	}
}

void buscar(Nodo *&B,Nodo *&P)
{
    int cen=0;
    int opb;
    string nombre_b;
    string codigo_b;
    Nodo *a = new Nodo();
    a=P;
    cout << "Buscar por: "<<endl;
    cout << "1. Nombre"<<endl;
    cout << "2. Codigo"<<endl;
    cout << "3. Cancelar"<<endl;
    cout << "Opcion: "; cin >> opb;
    do
    {
        if(opb==1)
        {
            fflush(stdin);
            cout << "Ingrese el nombre a buscar: "; getline(cin,nombre_b);
            if (P==NULL)
            {
                cout << "Lista sin datos"<<endl;
            }
            else if (a->A.Nom_Apell!=nombre_b)
            {
                a=a->siguiente;
            }
            else if (a->A.Nom_Apell==nombre_b) 
            {
                cen=1;
                B=a;
                cout << "Variable que indica al valor buscado actualizada"<<endl;
                cout << "Datos del alumno encontrado:"<<endl;
                cout << "Nombre: "<<B->A.Nom_Apell<<endl;
                cout << "Codigo: "<<B->A.codigo<<endl;
                cout << "Promedio: "<<B->A.Promedio<<endl;
            }
            system("pause");
            opb=3;
            system("cls");
        }
        else if (opb==2)
        {
            fflush(stdin);
            cout << "Ingrese el codigo a buscar: "; getline(cin,codigo_b);
            if (P==NULL)
            {
                cout << "Lista sin datos"<<endl;
            }
            else if (a->A.codigo!=codigo_b)
            {
                a=a->siguiente;
            }
            else if (a->A.codigo==codigo_b) 
            {
                cen=1;
                B=a;
                cout << "Variable que indica al valor buscado actualizada"<<endl;
                cout << "Datos del alumno encontrado:"<<endl;
                cout << "Nombre: "<<B->A.Nom_Apell<<endl;
                cout << "Codigo: "<<B->A.codigo<<endl;
                cout << "Promedio: "<<B->A.Promedio<<endl;
            }
            system("pause");
            opb=3;
            system("cls");
        }
    } while (opb!=3);
    if(cen==0)
    {
        cout << "Valor no encontrado."<<endl;
    }
}

void modificar(Nodo *&P,string ref)
{
    int opm;
    Nodo *q = new Nodo();
	int cen=0;
	if (P != NULL)
	{
		q = P;
		cen = 0;
		while ((q->A.codigo != ref) && (cen == 0))
		{
			if (q->siguiente != NULL)
			{
				q = q->siguiente;
			}
			else
			{
				cen = 1;
			}
		}
		if (cen == 0)
		{
			cout << "Ingrese que valor quiere modificar: "<<endl;
			cout << "1. Nombre"<<endl;
			cout << "2. Codigo"<<endl;
			cout << "3. Nota1"<<endl;
			cout << "4. Nota 2"<<endl;
			cout << "5. Cancelar"<<endl;
			cout << "Opcion: "; cin >>opm;
			do
			{
				if(opm==1)
				{
					fflush(stdin);
					cout << "Ingrese el nuevo nombre: "; getline(cin,q->A.Nom_Apell);
					system("pause");
					opm=5;
					system("cls");
				}
				if(opm==2)
				{
					fflush(stdin);
					cout << "Ingrese el nuevo codigo: "; getline(cin,q->A.codigo);
					system("pause");
					opm=5;
					system("cls");
				}
				if(opm==3)
				{
					cout << "Ingrese la nueva Nota 1: "; cin >> q->A.Nota1;
					system("pause");
					opm=5;
					system("cls");
				}
				if(opm==4)
				{
					cout << "Ingrese la nueva Nota 2: ";cin >>q->A.Nota2;
					system("pause");
					opm=5;
					system("cls");
				}
			} while (opm!=5);
		}
		else
		{
			cout << "No existe el referencial" << endl;
		}
	}
	else
	{
		cout << "Lista vacia" << endl;
	} 
}

void buscar_ld(Nodo *&P,string ref)
{
	Nodo *q = new Nodo();
	int cen = 0;
	if(P!=NULL)
	{
		q=P;
		cen=0;
		while ((q->A.codigo!=ref)&&(cen==0))
		{
			if(q->siguiente!=NULL)
			{
				q=q->siguiente;
			}
			else
			{
				cen=1;
			}
		}
		if(cen==0)
		{
				cout << "Datos del alumno encontrado:"<<endl;
                cout << "Nombre: "<<q->A.Nom_Apell<<endl;
                cout << "Codigo: "<<q->A.codigo<<endl;
                cout << "Promedio: "<<q->A.Promedio<<endl;
		}
		else
		{
			cout << "No existe el referencial"<<endl;
		}
	}
	else
	{
		cout << "Lista vacia"<<endl;
	}
}

void buscar_lo(Nodo *&P,string ref)
{
	Nodo *q = new Nodo();
	int cen = 0;
	if(P!=NULL)
	{
		q=P;
		cen=0;
		while ((q->A.codigo==ref)&&(cen==0))
		{
			if(q->siguiente!=NULL)
			{
				q=q->siguiente;
			}
			else
			{
				cen=1;
			}
		}
		if(q->A.codigo==ref)
		{
				cout << "Datos del alumno encontrado:"<<endl;
                cout << "Nombre: "<<q->A.Nom_Apell<<endl;
                cout << "Codigo: "<<q->A.codigo<<endl;
                cout << "Promedio: "<<q->A.Promedio<<endl;
		}
		else
		{
			cout << "No existe el referencial"<<endl;
		}
	}
	else
	{
		cout << "Lista vacia"<<endl;
	}
}