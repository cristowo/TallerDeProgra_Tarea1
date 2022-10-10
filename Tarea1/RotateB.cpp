#include "RotateB.h"

/*
Clase RotateB que permite rotar un cubo de Rubik
*/

/*
* Constructor de la clase RotateB
*/
RotateB::RotateB() {
    
}

/*
* Destructor de la clase RotateB
*/
RotateB::~RotateB() {
    
}

/*
* Metodo de rotar el cubo
* @param int oreintacion a girar, State* estado actual
* @return State* estado rotado
*/
State* RotateB::operate(int s, State *state){
    if (s==1){State* next = new State(state->cube->rotateB(1));next->op="B+";next->previous = state;return next;}
    else if(s==2){State* next = new State(state->cube->rotateB(1)->rotateB(1));next->op="B2";next->previous = state;return next;}
    else{State* next = new State(state->cube->rotateB(-1));next->op="B-";next->previous = state;return next;}
}

