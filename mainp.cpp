
#include<iostream>
#include<conio.h>
#include "Node.h"
#include "Stack.h"
#include "Converter.h"
#include <string>
using namespace std;

int main() {

    string postfija;

    //Estos son ejemplos variados para demostrar el funcionamiento de la funcion que convierte y
    //la funcion que evalua la expresion, se pueden agregar mas para probar (los parentesis importan)
    postfija = infiAposfi("((8+6)/2)");      //llamamos la que convierte a postfija y recogemos el string
    evaluador(postfija);                     //llamamos la que evalua
    cout << "\n   " << endl;
    postfija = infiAposfi("(2+(3*4))"); 
    evaluador(postfija);
    cout << "\n   " << endl;
    postfija = infiAposfi("(((8/2)%8)-1)"); 
    evaluador(postfija);

    return 0;
}