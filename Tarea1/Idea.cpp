#include "Idea.h"

/*
Clase Idea, implementa un heap
*/

/*
* Constructor de la clase Idea
*/
Idea::Idea() {
    stateArray = new State*[1];
    size = 0;
    arraySize = 1;
}

/*
* Destructor de la clase Idea
*/
Idea::~Idea() {
    delete[] stateArray;
}

/*
* Metodo de insercion de un estado en el heap
* @param State* estado que se encuentra en la raiz del heap
* @return Void
*/
void Idea::insert(State *s) {
    if (size >= arraySize) {                    //si el array esta lleno
        State** tmp = new State*[2*arraySize];  //crea un array temporal
        for(int k = 0; k < arraySize; k++) {    //copia los elementos del array original al temporal
            tmp[k] = stateArray[k];
        }
        arraySize *= 2;                         //duplica el tamaño del array
        delete[] stateArray;                    //elimina el array original
        stateArray = tmp;                       //copia el array temporal al original
    }
    stateArray[size] = s;                       //inserta el nuevo elemento
    size++;                                     //aumenta el tamaño del size
    heapifyUp(size-1);                          //ordena el array
}

/*
* Metodo de insertar State en el heap (para closed)
* @param State* estado que se encuentra en la raiz del heap
* @return Void
*/
void Idea::insertC(State *s){
    if (size >= arraySize) {                    //si el array esta lleno
        State** tmp = new State*[2*arraySize];  //crea un array temporal
        for(int k = 0; k < arraySize; k++) {    //copia los elementos del array original al temporal
            tmp[k] = stateArray[k];
        }
        arraySize *= 2;                         //duplica el tamaño del array
        delete[] stateArray;                    //elimina el array original
        stateArray = tmp;                       //copia el array temporal al original
    }
    stateArray[size] = s;                       //inserta el nuevo elemento
    size++;                                     //aumenta el tamaño del size
}

/*
* Metodo de optencion del nodo
* @param
* @return State* estado que se encuentra en la raiz del heap
*/
State* Idea::getNodo() {
    if (size == 0) {                            //si el array esta vacio
        return nullptr;                         //retorna null
    }
    State* result = stateArray[0];              //guarda el primer elemento del array
    stateArray[0] = stateArray[size-1];         //copia el ultimo elemento del array al primero
    size--;                                     //disminuye el tamaño del array
    heapify(0);                                 //ordena el array
    return result;                              //retorna el primer elemento del array
}

/*
* Metodo de ordenamieonto de un heap
* @param int
* @return Void
*/
void Idea::heapify(int i) {
    int left = 2*i+1;                           //calcula el indice del hijo izquierdo
    int right = 2*i+2;                          //calcula el indice del hijo derecho
    int smallest = i;                           //guarda el indice del menor elemento
    if (left < size && stateArray[left]->cost < stateArray[i]->cost) { //si el hijo izquierdo es menor que el padre
        smallest = left;                        //guarda el indice del hijo izquierdo
    }
    if (right < size && stateArray[right]->getCost() < stateArray[smallest]->getCost()) { //si el hijo derecho es menor que el padre
        smallest = right;                       //guarda el indice del hijo derecho
    }
    if (smallest != i) {                        //si el menor elemento no es el padre
        State* tmp = stateArray[i];             //guarda el padre en una variable temporal
        stateArray[i] = stateArray[smallest];   //copia el menor elemento al padre
        stateArray[smallest] = tmp;             //copia el padre al menor elemento
        heapify(smallest);                      //ordena el array
    }
}

/*
* Metodo de ordenamieonto de un heap
* @param int
* @return Void
*/
void Idea::heapifyUp(int i) {
    int parent = (i-1)/2;                       //calcula el indice del padre
    if (i > 0 && stateArray[i]->cost < stateArray[parent]->cost) { //si el hijo es menor que el padre
        State* tmp = stateArray[i];             //guarda el hijo en una variable temporal
        stateArray[i] = stateArray[parent];     //copia el padre al hijo
        stateArray[parent] = tmp;               //copia el hijo al padre
        heapifyUp(parent);                      //ordena el array
    }
}

/*
* Metodo de eliminacion de un state
* @param State* estado 
* @return Void
*/
void Idea::remove(State *s) {
    int k = 0;                                      //inicializa un contador
    for(int i = 0; i < size; i++){                  //recorre el array
        if(!stateArray[i]->cube->equal(s->cube)){   //si el elemento es distinto al que se quiere eliminar              
            stateArray[k] = stateArray[i];          //copia los elementos del array original al temporal
            k++;
        }
    }
    size--;                                          //disminuye el tamaño del size
}

/*
* Metodo de encontrar un cubo en común
* @param State* estado
* @return Bool
*/
bool Idea::find(State *s){
    for(int k = 0; k < size; k++) {             //recorre el array
        if (stateArray[k]->cube->equal(s->cube)){   //si encuentra el elemento
            return true;                        //retorna true
        }
    }
    return false;                               //si no encuentra el elemento retorna false
}
/*
State *Idea::getNodo(){
    int min = stateArray[0]->cost;               //inicializa el minimo con el primer elemento
    int posmin = 0;                             //inicializa la posicion del minimo con 0
    for(int k = 0; k < size; k++) {             //recorre el array
        if (stateArray[k]->cost < min) {        //si encuentra el elemento
            min = stateArray[k]->cost;          //actualiza el minimo
            posmin = k;                         //guarda la posicion del minimo
        }
    }
    return stateArray[posmin];                  //retorna el nodo con el menor costo
}*/

/*
* Metodo de ver si el heap esta vacio
* @param 
* @return Bool
*/
bool Idea::isEmpty(){
    return size == 0;
}
