

#ifndef STACK 

#define STACK 1

template <class T>
class Stack {

    private:
        Node<T> *top;
        Node<T> *aux;
        int quantity;
        bool empty;

    public:
        Stack() {
            top = NULL;
            quantity = 0;
            empty = true;
        }

        void push(T pData) {
            Node<T> *newNode = new Node(pData);  //creamos espacio en memoria para almacenar nodo
            newNode->setNext(top);  //hacemos que apunte a null, pq pila era null
            top = newNode; 
            empty = false;
            quantity++;
        }    

        int getSize() {
            return quantity;
        }

        bool isEmpty() {
            return !top;
        }

        T peek() {
            return top->getData();
        }

        void pop() {
            Node<T> *aux = top;
            
            top = aux->getNext(); 

            delete aux;
            quantity--;
        }

};

#endif
