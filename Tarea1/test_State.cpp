#include "State.h"
#include "Path.h"

int main() {
    State *state = new State(new Rubik());
    state->cube->print();
    return 0;
}