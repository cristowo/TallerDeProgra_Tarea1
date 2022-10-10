#include "RotateL.h"

/*
Clase RotateL que permite rotar un cubo de Rubik
*/

/*
* Constructor de la clase RotateL
*/
RotateL::RotateL() {
    
}

/*
* Destructor de la clase RotateL
*/
RotateL::~RotateL() {
    
}

/*
* Metodo de rotar el cubo
* @param int oreintacion a girar, State* estado actual
* @return State* estado rotado
*/
State* RotateL::operate(int s, State* state){
    if (s==1){State* next = new State(state->cube->rotateL(1));next->op="L+";next->previous = state;return next;}
    else if(s==2){State* next = new State(state->cube->rotateL(1)->rotateL(1));next->op="L2";next->previous = state;return next;}
    else{State* next = new State(state->cube->rotateL(-1));next->op="L-";next->previous = state;return next;}
}