#include <iostream>
#include <ctime>

#include "Rubik_Solver.h"
#include "Rubik.h"

/*
 Aqui vamos a medir el tiempo que demora en resolver
 el cubo Rubik.
*/

int main() {
    clock_t ti, tf;
    double dt=0, tavg=0;
    int N=0;

    Rubik_Solver *solver;

    std::cout << "Ingrese cantidad de movimientos para desordenar el cubo: ";
    std::cin >> N;
    std::cout << "Se ejecutaran " << N << " movimientos" << std::endl;
    ti = clock();
    Rubik *rubik=new Rubik();
    rubik = rubik->scramble(N);
    solver = new Rubik_Solver(rubik);
    Path *path=solver->solve();
    path->print();
    tf = clock();
    dt =(tf-ti)/(double)CLOCKS_PER_SEC;
    tavg += dt;
    std::cout << "Tiempo de ejecucion: " << dt << " segundos" << std::endl;
    return 0;
}