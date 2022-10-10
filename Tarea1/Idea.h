#include "State.h"

class Idea {
public:
    State **stateArray;
    int size;
    int arraySize;
    //Constructor de la clase Idea
    Idea();
    //Destructor de la clase Idea
    ~Idea();
    //Metodo de insercion de un estado en el heap
    void insert(State *s);
    //Metodo de insertar State en el heap (para closed)
    void insertC(State *s);
    //Metodo de eliminacion de un estado en el heap
    void remove(State *s);
    //Metodo de encontrar un estado en el heap
    bool find(State *s);
    //Metodo de optener un state
    State *getNodo();
    //Metodo para ver si esta vacio
    bool isEmpty();
    //Metodo de ordenar el heap
    void heapify(int i);
    //Metodo de ordenar el heap
    void heapifyUp(int i);
    
};