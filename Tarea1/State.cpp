#include "State.h"
#include "Path.h"

/*
* Clase para el estado del cubo
*/

/*
* Constructor
* @param Rubik *cube
*/
State::State(Rubik *r) {
    cube = r;
    previous = NULL;
    op = "";
    cost = 0;
    prev = -1;
}
/*
State::State(Rubik *r, int c) {
    cube = r;
    previous = NULL;
    op = "";
    cost = c;
}*/

/*
* Destructor
*/
State::~State() {
    delete cube;
}

/*
* Metodo para obtener el camino
* @return Path *path
*/
Path *State::getPath(){
    Path *path = new Path();
    State *state = this;
    while (state->previous != NULL) {
        path->insert(state->op);
        state = state->previous;
    }
    //std::cout << "Path: " << path->path << std::endl;
    return path;
}

/*
* Metodo para imprimir el camino
*/
void State::printPath() {
    Path *path = getPath();
    path->print();
    delete path;
}

/*
* Metodo para imprimir el cubo
*/
void State::print() {
    cube->print();
}

/*
* Metodo para retornar el costo
* @return int cost
*/
int State::getCost() {
    return this->cost;
}
