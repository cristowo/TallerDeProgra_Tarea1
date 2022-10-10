#ifndef __STATE_H__
#define __STATE_H__

#include "Rubik.h"
#include "Path.h"

class State {
public:
    Rubik *cube;
    State *previous;
    std::string op;    
    int cost;
    int prev;
    //Constructor
    State(Rubik *r);
    //State(Rubik *r, int c);
    //Destructor
    ~State();
    //Metodo para retornar el costo
    int getCost();
    //Metodo para obtener el camino
    Path *getPath();
    //Metodo para imprimir el camino
    void printPath();
    //Metodo para imprimir el cubo
    void print();
};

#endif
