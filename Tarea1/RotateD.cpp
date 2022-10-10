#include "RotateD.h"

/*
Clase RotateD que permite rotar un cubo de Rubik
*/

/*
* Constructor de la clase RotateD
*/
RotateD::RotateD() {
    
}

/*
* Destructor de la clase RotateD
*/
RotateD::~RotateD() {
    
}

/*
* Metodo de rotar el cubo
* @param int oreintacion a girar, State* estado actual
* @return State* estado rotado
*/
State* RotateD::operate(int s, State *state){
    if (s==1){State* next = new State(state->cube->rotateD(1));next->op="D+";next->previous = state;return next;}
    else if(s==2){State* next = new State(state->cube->rotateD(1)->rotateD(1));next->op="D2";next->previous = state;return next;}
    else{State* next = new State(state->cube->rotateD(-1));next->op="D-";next->previous = state;return next;}
}