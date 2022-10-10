#include "Idea.h"

int main() {
    Idea *s = new Idea();
    State *state = new State(new Rubik());
    s->insert(state);
    s->getNodo();
    return 0;
}