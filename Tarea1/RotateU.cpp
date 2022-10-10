#include "RotateU.h"

/*
Clase RotateU que permite rotar un cubo de Rubik
*/

/*
* Constructor de la clase RotateU
*/
RotateU::RotateU() {
    
}

/*
* Destructor de la clase RotateU
*/
RotateU::~RotateU() {
    
}

/*
* Metodo de rotar el cubo
* @param int oreintacion a girar, State* estado actual
* @return State* estado rotado
*/
State* RotateU::operate(int s, State *state){
    if (s==1){
        State* next = new State(state->cube->rotateU(1));
        next->op="U+";
        next->previous = state;
        return next;
    }
    else if(s==2){
        State* next = new State(state->cube->rotateU(1)->rotateU(1));
        next->op="U2";
        next->previous = state;
        return next;
        }
    else{
        State* next = new State(state->cube->rotateU(-1));
        next->op="U-";
        next->previous = state;
        return next;
    }
}