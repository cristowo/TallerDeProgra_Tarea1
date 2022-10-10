#include <iostream>
#include "Path.h"
#include "Rubik.h"
#include "State.h"
#include "RotateU.h"
#include "RotateD.h"
#include "RotateF.h"
#include "RotateB.h"
#include "RotateL.h"
#include "RotateR.h"
#include "Idea.h"




class Rubik_Solver {
public:
    Rubik *cube;
    State *initialState;
    Idea *open;
    Idea *closed;
    //Constructor de la clase Rubik_Solver
    Rubik_Solver(Rubik * rubik);
    //Destructor de la clase Rubik_Solver
    ~Rubik_Solver();
    //Metodo de resolver el cubo
    Path *solve();
    //Obtener la heuristica
    int getHeuristic(State *state, int cond);
    //Obtener la heuristica
    int oneHeuristic(State *state);
    //Obtener la heuristica
    int twoHeuristic(State *state, int heuristic); 
    //Obtener la heuristica
    int threeHeuristic(State *state, int heuristic);
    //Obtener la heuristica
    int fourHeuristic(State *state, int heuristic);
    //Obtener la heuristica
    int fiveHeuristic(State *state, int heuristic);
    //Metodo para mover de open a closed
    void moveToClose();
    State *madeOrder(State *state);
private:
    //Metodo para ver si un estado se genero
    bool wasNotGenerated(State *next);
    State_Operator *operators[6];
};
