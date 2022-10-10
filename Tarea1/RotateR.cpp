#include "RotateR.h"

/*
Clase RotateR que permite rotar un cubo de Rubik
*/

/*
* Constructor de la clase RotateR
*/
RotateR::RotateR() {
    
}

/*
* Destructor de la clase RotateR
*/
RotateR::~RotateR() {
    
}

/*
* Metodo de rotar el cubo
* @param int oreintacion a girar, State* estado actual
* @return State* estado rotado
*/
State* RotateR::operate(int s, State* state){
    if (s==1){State* next = new State(state->cube->rotateR(1));next->op="R+";next->previous = state;return next;}
    else if(s==2){State* next = new State(state->cube->rotateR(1)->rotateR(1));next->op="R2";next->previous = state;return next;}
    else{State* next = new State(state->cube->rotateR(-1));next->op="R-";next->previous = state;return next;}
}