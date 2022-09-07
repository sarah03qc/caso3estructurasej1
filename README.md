# caso3estructurasej1


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

