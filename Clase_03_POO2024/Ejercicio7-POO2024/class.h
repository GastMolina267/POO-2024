#ifndef CLASS_H
#define CLASS_H

#include <iostream>
using namespace std;

class Calculadora {
private:
    char Operador;
    float OperandoUno = 0;
    float OperandoDos = 0;

public:
    Calculadora();
    Calculadora(char OP, float OPUno, float OPDos);
    int setOperador(char OP);
    void setOperandoUno(float OPUno);
    void setOperandoDos(float OPDos);
    char getOperador();
    float getOperandoUno();
    float getOperandoDos();

    float Operar();
};

Calculadora::Calculadora() {
    Operador = NULL;
    OperandoUno = NULL;
    OperandoDos = NULL;
}

Calculadora::Calculadora(char OP, float OPUno, float OPDos) {
    Operador = OP;
    OperandoUno = OPUno;
    OperandoDos = OPDos;
}

int Calculadora::setOperador(char OP) {
    if (OP != '+' & OP != '-' & OP != '/' & OP != '*') {
        return -1;
    } else {
        Operador = OP;
        return 1;
    }
}

void Calculadora::setOperandoUno(float OPUno) {
    OperandoUno = OPUno;
}

void Calculadora::setOperandoDos(float OPDos) {
    OperandoDos = OPDos;
}

char Calculadora::getOperador() {
    if (Operador != NULL) {
        return Operador;
    } else {
        return NULL;
    }
}

float Calculadora::getOperandoUno() {
    return OperandoUno;
}

float Calculadora::getOperandoDos() {
    return OperandoDos;
}

float Calculadora::Operar() {
    float RETURN_THIS;
    if (Operador == NULL) {
        return -1;
    } else {
        switch(Operador) {
        case '+':
            RETURN_THIS = OperandoUno + OperandoDos;
            break;

        case '-':
            RETURN_THIS = OperandoUno - OperandoDos;
            break;

        case '/':
            RETURN_THIS = OperandoUno / OperandoDos;
            break;

        case '*':
            RETURN_THIS = OperandoUno * OperandoDos;
            break;

        default:
            RETURN_THIS = -1;
            cout << "Error Desconocido" << endl;
            break;
        }
    }
    return RETURN_THIS;
}
#endif // CLASS_H
