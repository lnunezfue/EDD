#include <iostream>
#include <stack>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

int Prioridad(char operador) {
    if (operador == '^')
        return 3;
    else if (operador == '*' || operador == '/')
        return 2;
    else if (operador == '+' || operador == '-')
        return 1;
    else
        return 0;
}

double calcular(double num1, double num2, char operador) {
    switch (operador) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '^':
            return pow(num1, num2);
        default:
            return 0;
    }
}

string Postfija(const string& expresion) {
    stack<char> pila;
    string postfija;

    for (char caracter : expresion) {
        if (caracter == ' ' || caracter == '\t')
            continue;

        if (isalnum(caracter))
            postfija += caracter;
        else if (caracter == '(')
            pila.push(caracter);
        else if (caracter == ')') {
            while (!pila.empty() && pila.top() != '(') {
                postfija += pila.top();
                pila.pop();
            }
            pila.pop(); 
        } else {
            while (!pila.empty() && Prioridad(caracter) <= Prioridad(pila.top())) {
                postfija += pila.top();
                pila.pop();
            }
            pila.push(caracter);
        }
    }

    while (!pila.empty()) {
        postfija += pila.top();
        pila.pop();
    }

    return postfija;
}

string Prefija(const string& expresion) {
    stack<char> pila;
    string prefija;

    for (int i = expresion.size() - 1; i >= 0; i--) {
        char caracter = expresion[i];

        if (caracter == ' ' || caracter == '\t')
            continue;

        if (isalnum(caracter))
            prefija = caracter + prefija;
        else if (caracter == ')')
            pila.push(caracter);
        else if (caracter == '(') {
            while (!pila.empty() && pila.top() != ')') {
                prefija = pila.top() + prefija;
                pila.pop();
            }
            pila.pop(); 
        } else {
            while (!pila.empty() && Prioridad(caracter) < Prioridad(pila.top())) {
                prefija = pila.top() + prefija;
                pila.pop();
            }
            pila.push(caracter);
        }
    }

    while (!pila.empty()) {
        prefija = pila.top() + prefija;
        pila.pop();
    }

    return prefija;
}

int main() {
    string expresion;
    cout << "Ingrese una expresion infija: ";
    getline(cin, expresion);

    string postfija = Postfija(expresion);
    cout << "Expresion postfija: " << postfija << endl;
    
    string prefija = Prefija(expresion);
    cout << "Expresion prefija: " << prefija << endl;
    
    stack<double> operandos;

    for (char caracter : prefija) {
        if (isdigit(caracter)) {
            double numero;
            stringstream ss;
            ss << caracter;
            ss >> numero;
            operandos.push(numero);
        } else {
            double num2 = operandos.top();
            operandos.pop();
            double num1 = operandos.top();
            operandos.pop();
            double resultado = calcular(num1, num2, caracter);
            operandos.push(resultado);
        }
    }
    
    double resultadoFinalPre = operandos.top();
    cout << "Resultado: " << resultadoFinalPre << endl;
    
    stack<double> operandos2;

    for (char caracter : postfija) {
        if (isdigit(caracter)) {
            double numero;
            stringstream ss;
            ss << caracter;
            ss >> numero;
            operandos2.push(numero);
        } else {
            double num2 = operandos2.top();
            operandos2.pop();
            double num1 = operandos2.top();
            operandos2.pop();
            double resultado = calcular(num1, num2, caracter);
            operandos2.push(resultado);
        }
    }

    double resultadoFinalPos = operandos.top();
    cout << "Resultado: " << resultadoFinalPos << endl;

    return 0;
}
