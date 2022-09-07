/*
ALGORITMO EN EL QUE ME BASE PARA EL CONVERSOR:
1. Inicializar la pila
2. Definir la prioridad del conjunto de operaciones
3. Mientras no ocurra error y no sea fin de la expresión infija haz
• Si el carácter es:
     1. PARENTESIS IZQUIERDO. Colocarlo en la pila

     2. PARENTESIS DERECHO. Extraer y desplegar los valores hasta encontrar
        paréntesis izquierdo. Pero NO desplegarlo.

     3. UN OPERADOR. Si la pila esta vacía o el operador tiene más alta 
        prioridad que el operador del tope de la pila insertar el operador en la pila.
        
        En caso contrario extraer y desplegar el
        elemento del tope de la pila y repetir la
        comparación con el nuevo tope.

     4. OPERANDO. Desplegarlo.

4. Al final de la expresión extraer y desplegar los elementos de la pila hasta que se vacíe.
*/


#include<iostream>
#include<sstream>
#include<conio.h>
#include "Node.h"
#include "Stack.h"
#include<string>

using namespace std;
 
//Definir la prioridad del conjunto de operaciones
int priori(char caract) {
    if(caract == '-' || caract == '+') {
        return 1;
    }
    else if(caract == '*' || caract == '/' || caract == '%') {
        return 2;
    }
    else {
        return -1;
    }
}
 

string infiAposfi(string expInfija) {
 
    Stack<char> pila1; //creamos el stack
    string hileraFinal;
    char caract;
 
    for(int i = 0; i < expInfija.length(); i++) {
        //se itera por la expresión infija 
        caract = expInfija[i];

         //Si el carácter es:
         //1. PARENTESIS IZQUIERDO. Colocarlo en la pila
        if (caract == '(') {
            pila1.push('(');
        }
           
        //2. PARENTESIS DERECHO. Extraer y desplegar los valores hasta encontrar
        //parentesis izquierdo. Pero NO desplegarlo.
        else if(caract == ')') {
            while (pila1.peek() != '(' && pila1.peek() != ')') {
                if(pila1.peek() == '*') {
                    hileraFinal += '*';
                }
                else if(pila1.peek() == '+') {
                    hileraFinal += '+';
                }
                else if(pila1.peek() == '-') {
                    hileraFinal += '-';
                }
                else if(pila1.peek() == '/') {
                    hileraFinal += '/';
                }
                else if(pila1.peek() == '%') {
                    hileraFinal += '%';
                }
                pila1.pop();
            }
            pila1.pop();
        }

        //3. OPERANDO. Desplegarlo.
        else if((caract >= '0' && caract <= '9')) {
            hileraFinal += caract;
        }
  
        //4. UN OPERADOR.              
        else {  
            //mientras la lista no este vacia y el operador no tiene mas alta prioridad
            //que el operador de la cima de la pila 
            while (!pila1.isEmpty() && priori(expInfija[i]) <= priori(pila1.peek())) {
                //extraer y desplegar el
                //elemento top de la pila y repetir la
                //comparación con el nuevo top
                hileraFinal += pila1.peek();    //se arma en la string 
                pila1.pop();          //y se quita
            }
            //insertar el operador en la pila si esta vacia o el operador tiene más alta 
            //prioridad que el operador de la cima de la pila 
            pila1.push(caract);    
        }
    }
    //Al final de la expresión extraer y desplegar los elementos de la pila hasta que se vacíe
    while(!pila1.isEmpty()) {
        hileraFinal += pila1.peek();
        pila1.pop();
    }
    cout << "La hilera en notacion postfija es: " << hileraFinal << endl;
    return hileraFinal;
}

/*
ESTE ALGORITMO ES EN EL QUE SE BASA LA FUNCION DE EVALUAR:
1. Incrementar la pila
2. Repetir
    Tomar un carácter.

    Si el carácter es un operando colocarlo en la pila.

    Si el carácter es un operador entonces tomar los
    dos valores del tope de la pila, aplicar el operador
    y colocar el resultado en el nuevo tope de la pila.
    (Se produce un error en caso de no tener los 2
     valores)
3. Hasta encontrar el fin de la expresión RPN.
*/

void evaluador(string hilera) {
    //Esta es la funcion que evalua la expresion postfija y retorna el resultado
    Stack<int> pila1; //creamos el stack, double por si acaso
    int resultado;    //donde se guardara el resultado
    char caract;
    int num1;
    int num2;

    for(int i = 0; i < hilera.length(); i++) {
        //se itera por la expresión infija 
        caract = hilera[i];
        if(isdigit(caract)) {
            //si es un numero se pone en la pila
            int integer = caract;
            int valorReal = integer - 48;
            pila1.push(valorReal);
        } else {
            //si caract es un operador
            num1 = pila1.peek();  //ponemos el valor al tope de la pila
            pila1.pop();   //y lo quitamos de la pila
            num2 = pila1.peek();  //lo hacemos de nuevo con el siguiente
            pila1.pop();  
            //ahora comparamos a ver cual es el operador, de las opciones validas
            //y hacemos la operacion
            if(caract == '*') {
                resultado = num1 * num2;
            }
            else if(caract == '+') {
                resultado = num1 + num2;
            }
            else if(caract == '-') {
                resultado = num2 - num1;
            }
            else if(caract == '/') {
                resultado = num2 / num1;
            }
            else if(caract == '%') {
                resultado = num2 % num1;
            }
            pila1.push(resultado);    //agregamos ese resultado a la pila
        }
    }
    resultado = pila1.peek();
    cout << "El resultado final es: " << resultado << endl;
}