#include <iostream>
#include <algorithm> // Para la función de búsqueda en arrays ordenados
#include <string>

using namespace std;

struct Alumno{
	string codigo;
	string nombre;
	string apellido;
	float nota1;
	float nota2;
	float promedio;
};
// Función para mostrar un array
void mostrarArray(Alumno arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout <<"ALUMNO Nro." <<i+1<<endl;
        cout <<"CODIGO -->" <<arr[i].codigo<<endl;
        cout <<"NOMBRE -->" <<arr[i].nombre<<endl;
        cout <<"APELLIDO -->" <<arr[i].apellido<<endl;
        cout <<"NOTA 1 -->" <<arr[i].nota1<<endl;
        cout <<"NOTA 2 -->" <<arr[i].nota2<<endl;
        cout <<"PROMEDIO -->" <<arr[i].promedio<<endl;
    }
    cout << endl;
}

// Función para buscar un elemento en un array desordenado
int buscarDesordenado(Alumno arr[], int size, string c) {
    for (int i = 0; i < size; i++) {
        if (arr[i].codigo == c) {
            return i;
        }
    }
    return -1; // Retorna -1 si el elemento no se encuentra
}

// Función para buscar un elemento en un array ordenado
int buscarOrdenado(Alumno arr[], int size,string c) {
    int inicio = 0;
    int fin = size - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        
        if (arr[medio].codigo == c) {
            return medio;
        }
        else if (arr[medio].codigo < c) {
            inicio = medio + 1;
        }
        else {
            fin = medio - 1;
        }
    }
    
    return -1; // Retorna -1 si el elemento no se encuentra
}

// Función para insertar un elemento en un array desordenado
void insertarDesordenado(Alumno arr[], int& size, Alumno elemento) {
    arr[size++] = elemento;
}

// Función para insertar un elemento en un array ordenado
void insertarOrdenado(Alumno arr[], int& size, Alumno elemento) {
    int i = size - 1;
    
    while (i >= 0 && arr[i].codigo > elemento.codigo) {
        arr[i + 1] = arr[i];
        i--;
    }
    
    arr[i + 1] = elemento;
    size++;
}

// Función para eliminar un elemento de un array desordenado
void eliminarDesordenado(Alumno arr[], int& size,string c) {
    int indice = buscarDesordenado(arr, size, c);
    
    if (indice != -1) {
        for (int i = indice; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

// Función para eliminar un elemento de un array ordenado
void eliminarOrdenado(Alumno arr[], int& size, string c) {
    int indice = buscarOrdenado(arr, size, c);
    
    if (indice != -1) {
        for (int i = indice; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

// Función para modificar un elemento en un array desordenado
void modificarDesordenado(Alumno arr[], int size, string c) {
    int indice = buscarDesordenado(arr, size,  c);
    Alumno A;
    cout<<"Ingrese el codigo del alumno"<<endl;
	cin>>A.codigo;
	cout<<"Ingrese el nombre del alumno"<<endl;
	cin>>A.nombre;
	cout<<"Ingrese el apellido del alumno"<<endl;
	cin>>A.apellido;
	cout<<"Ingrese la nota 1 del alumno"<<endl;
	cin>>A.nota1;
	cout<<"Ingrese la nota 2 del alumno"<<endl;
	cin>>A.nota2;
	A.promedio=(A.nota1+A.nota2)/2;
    if (indice != -1) {
        arr[indice] = A;
    }
}

// Función para modificar un elemento en un array ordenado
void modificarOrdenado(Alumno arr[], int size,string c) {
    int indice = buscarOrdenado(arr, size,c);
    Alumno A;
    cout<<"Ingrese el codigo del alumno"<<endl;
	cin>>A.codigo;
	cout<<"Ingrese el nombre del alumno"<<endl;
	cin>>A.nombre;
	cout<<"Ingrese el apellido del alumno"<<endl;
	cin>>A.apellido;
	cout<<"Ingrese la nota 1 del alumno"<<endl;
	cin>>A.nota1;
	cout<<"Ingrese la nota 2 del alumno"<<endl;
	cin>>A.nota2;
	A.promedio=(A.nota1+A.nota2)/2;
    if (indice != -1) {
        eliminarOrdenado(arr,size,c);
        insertarOrdenado(arr,size,A);
    }
}

int main() {
    const int MAX_SIZE = 100;
	Alumno arr[MAX_SIZE];
    Alumno arr1[MAX_SIZE];
    Alumno A;
	int size = 0;
	int size1 = 0;
    int opcion;

    do {
        // Mostrar el menú
        cout << "---- MENU PRINCIPAL ----" << endl;
        cout << "1. ARREGLO ORDENADO" << endl;
        cout << "2. ARREGLO DESORDENADO" << endl;
        cout << "3. SALIR" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        system("cls");
		system("pause");
        // Ejecutar la opción seleccionada
        if (opcion == 1) {
            int opcion1;

		    do {
		        // Mostrar el menú
		        cout << "---- MENU ORDENADO ----" << endl;
		        cout << "1. INSERTAR" << endl;
		        cout << "2. ELIMINAR" << endl;
		        cout << "3. MODIFICAR" << endl;
		        cout << "4. MOSTRAR" << endl;
		        cout << "5. BUSCAR" << endl;
		        cout << "6. SALIR" << endl;
		        cout << "Ingrese su opcion: ";
		        cin >> opcion1;
		        system("cls");
		        system("pause");
		
		        // Ejecutar la opción seleccionada
		        if (opcion1 == 1) {
		        	system("cls");
		        	cout<<"---Insertar---"<<endl;
		        	cout<<"Ingrese el codigo del alumno"<<endl;
		        	cin>>A.codigo;
		        	cout<<"Ingrese el nombre del alumno"<<endl;
		        	cin>>A.nombre;
		        	cout<<"Ingrese el apellido del alumno"<<endl;
		        	cin>>A.apellido;
		        	cout<<"Ingrese la nota 1 del alumno"<<endl;
		        	cin>>A.nota1;
		        	cout<<"Ingrese la nota 2 del alumno"<<endl;
		        	cin>>A.nota2;
		        	A.promedio=(A.nota1+A.nota2)/2;
	            	insertarOrdenado(arr,size,A);
	            	system("cls");
		        	system("pause");
		        } else if (opcion1 == 2) {
		        	system("cls");
		        	string auxe;
				    cout<<"Inserte el Codigo del Alumno"<<endl;
				    cin>>auxe;
		        	eliminarOrdenado(arr,size,auxe);
		        	system("pause");
		        	system("cls");
		        } else if (opcion1 == 3) {
		        	system("cls");
		        	string auxm;
				    cout<<"Inserte el Codigo del Alumno"<<endl;
				    cin>>auxm;
		            modificarOrdenado(arr,size,auxm);
		        	system("pause");
					system("cls");
		        } else if (opcion1 == 4) {
		        	system("cls");
		            mostrarArray(arr,size);
		        	system("pause");
		        	system("cls");
		        } else if (opcion1 == 5) {
		        	system("cls");
		        	int indice;
		        	string auxb;
				    cout<<"Inserte el Codigo del Alumno"<<endl;
				    cin>>auxb;
		            indice=buscarOrdenado(arr,size,auxb);
		            if(indice!=-1){
		            	cout <<"ALUMNO Nro." <<indice+1<<endl;
        				cout <<"CODIGO -->" <<arr[indice].codigo<<endl;
        				cout <<"NOMBRE -->" <<arr[indice].nombre<<endl;
				        cout <<"APELLIDO -->" <<arr[indice].apellido<<endl;
				        cout <<"NOTA 1 -->" <<arr[indice].nota1<<endl;
				        cout <<"NOTA 2 -->" <<arr[indice].nota2<<endl;
				        cout <<"PROMEDIO -->" <<arr[indice].promedio<<endl;
					}
		        	system("pause");
		        	system("cls");
		        } else if (opcion1 == 6) {
		        	system("cls");
		            cout << "Saliendo..." << endl;
		        	system("pause");
		        	system("cls");
		        } else {
		        	system("cls");
		            cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
		        	system("pause");
		        	system("cls");
		        }
		        cout << endl;
		    } while (opcion1 != 6);
        } else if (opcion == 2) {
        	int opcion2;
        	do {
		        // Mostrar el menú
		        cout << "---- MENU DESORDENADO ----" << endl;
		        cout << "1. INSERTAR" << endl;
		        cout << "2. ELIMINAR" << endl;
		        cout << "3. MODIFICAR" << endl;
		        cout << "4. MOSTRAR" << endl;
		        cout << "5. BUSCAR" << endl;
		        cout << "6. SALIR" << endl;
		        cout << "Ingrese su opcion: ";
		        cin >> opcion2;
		        system("cls");
		        system("pause");
		
		        // Ejecutar la opción seleccionada
		        if (opcion2 == 1) {
		        	system("cls");
		        	cout<<"---Insertar---"<<endl;
		        	cout<<"Ingrese el codigo del alumno"<<endl;
		        	cin>>A.codigo;
		        	cout<<"Ingrese el nombre del alumno"<<endl;
		        	cin>>A.nombre;
		        	cout<<"Ingrese el apellido del alumno"<<endl;
		        	cin>>A.apellido;
		        	cout<<"Ingrese la nota 1 del alumno"<<endl;
		        	cin>>A.nota1;
		        	cout<<"Ingrese la nota 2 del alumno"<<endl;
		        	cin>>A.nota2;
		        	A.promedio=(A.nota1+A.nota2)/2;
	            	insertarDesordenado(arr1,size1,A);
	            	system("cls");
		        	system("pause");
		        } else if (opcion2 == 2) {
		        	system("cls");
		        	string auxe2;
				    cout<<"Inserte el Codigo del Alumno"<<endl;
				    cin>>auxe2;
		        	eliminarDesordenado(arr1,size1,auxe2);
		        	system("pause");
		        	system("cls");
		        } else if (opcion2 == 3) {
		        	system("cls");
		        	string auxm2;
				    cout<<"Inserte el Codigo del Alumno"<<endl;
				    cin>>auxm2;
		            modificarDesordenado(arr1,size1,auxm2);
		        	system("pause");
					system("cls");
		        } else if (opcion2 == 4) {
		        	system("cls");
		            mostrarArray(arr1,size1);
		        	system("pause");
		        	system("cls");
		        } else if (opcion2 == 5) {
		        	system("cls");
		        	int indice2;
		        	string auxb2;
				    cout<<"Inserte el Codigo del Alumno"<<endl;
				    cin>>auxb2;
		            indice2=buscarDesordenado(arr1,size1,auxb2);
		            if(indice2!=-1){
		            	cout <<"ALUMNO Nro." <<indice2+1<<endl;
        				cout <<"CODIGO -->" <<arr1[indice2].codigo<<endl;
        				cout <<"NOMBRE -->" <<arr1[indice2].nombre<<endl;
				        cout <<"APELLIDO -->" <<arr1[indice2].apellido<<endl;
				        cout <<"NOTA 1 -->" <<arr1[indice2].nota1<<endl;
				        cout <<"NOTA 2 -->" <<arr1[indice2].nota2<<endl;
				        cout <<"PROMEDIO -->" <<arr1[indice2].promedio<<endl;
					}
		        	system("pause");
		        	system("cls");
		        } else if (opcion2 == 6) {
		        	system("cls");
		            cout << "Saliendo..." << endl;
		        	system("pause");
		        	system("cls");
		        } else {
		        	system("cls");
		            cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
		        	system("pause");
		        	system("cls");
		        }
		        cout << endl;
		    } while (opcion2!= 6);
            
        } else {
            cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
        }

        cout << endl;
    } while (opcion != 3);
	cout << "Saliendo..." << endl;
    return 0;
}
