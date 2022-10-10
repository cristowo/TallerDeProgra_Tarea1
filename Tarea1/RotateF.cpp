#include "RotateF.h"

/*
Clase RotateF que permite rotar un cubo de Rubik
*/

/*
* Constructor de la clase RotateF
*/
RotateF::RotateF() {
    
}

/*
* Destructor de la clase RotateF
*/
RotateF::~RotateF() {
    
}

/*
* Metodo de rotar el cubo
* @param int oreintacion a girar, State* estado actual
* @return State* estado rotado
*/
State* RotateF::operate(int s, State *state){
    if (s==1){State* next = new State(state->cube->rotateF(1));next->op="F+";next->previous = state;return next;}
    else if(s==2){State* next = new State(state->cube->rotateF(1)->rotateF(1));next->op="F2";next->previous = state;return next;}
    else{State* next = new State(state->cube->rotateF(-1));next->op="F-";next->previous = state;return next;}
}