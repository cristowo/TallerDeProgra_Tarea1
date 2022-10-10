#include "Rubik_Solver.h"

int main() {
    Rubik *rubik=new Rubik();
    rubik = rubik->scramble(2);
    Rubik_Solver *solver = new Rubik_Solver(rubik);
    solver->solve();
    delete solver;
    return 0;
}