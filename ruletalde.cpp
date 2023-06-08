#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Nodo {
    int numero;
    Nodo* siguiente;
    Nodo* anterior;
};

class Ruleta {
private:
    Nodo* cabeza;
    int tamano;

public:
    Ruleta() {
        cabeza = nullptr;
        tamano = 0;
    }

    void agregarNumero(int numero) {
        Nodo* nuevo = new Nodo();
        nuevo->numero = numero;

        if (cabeza == nullptr) {
            nuevo->siguiente = nuevo;
            nuevo->anterior = nuevo;
            cabeza = nuevo;
        } else {
            nuevo->siguiente = cabeza;
            nuevo->anterior = cabeza->anterior;
            cabeza->anterior->siguiente = nuevo;
            cabeza->anterior = nuevo;
        }

        tamano++;
    }

    int girarRuleta() {
        if (cabeza == nullptr) {
            cout << "La ruleta está vacía" << endl;
            return -1;
        }

        // Generar un número aleatorio entre 1 y el tamaño de la ruleta
        srand(time(nullptr));
        int pasos = rand() % tamano + 1;

        // Moverse hacia adelante o hacia atrás en la ruleta según los pasos generados
        Nodo* actual = cabeza;
        if (pasos > 0) {
            for (int i = 0; i < pasos; i++) {
                actual = actual->siguiente;
            }
        } else {
            for (int i = 0; i > pasos; i--) {
                actual = actual->anterior;
            }
        }

        return actual->numero;
    }

    void mostrar() {
        if (cabeza == nullptr) {
            cout << "La ruleta está vacía" << endl;
            return;
        }

        Nodo* actual = cabeza;

        do {
            cout << actual->numero << " ";
            actual = actual->siguiente;
        } while (actual != cabeza);

        cout << endl;
    }
};

int main() {
    Ruleta ruleta;

    // Agregar números a la ruleta
    ruleta.agregarNumero(0);
    for (int i = 1; i <= 36; i++) {
        ruleta.agregarNumero(i);
    }

    // Girar la ruleta y mostrar el resultado
    int numeroGanador = ruleta.girarRuleta();
    cout << "El número ganador es: " << numeroGanador << endl;

    // Mostrar la ruleta después de girar
    ruleta.mostrar();

    return 0;
}
