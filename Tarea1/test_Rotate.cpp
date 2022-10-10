#include "RotateB.h"
#include "RotateD.h"
#include "RotateF.h"
#include "RotateL.h"
#include "RotateR.h"
#include "RotateU.h"
#include "State.h"
#include "State_Operator.h"
#include "Rubik.h"
#include "Path.h"

int main() {
    State *state = new State(new Rubik());
    RotateB *rotateB = new RotateB();
    RotateD *rotateD = new RotateD();
    RotateF *rotateF = new RotateF();
    RotateL *rotateL = new RotateL();
    RotateR *rotateR = new RotateR();
    RotateU *rotateU = new RotateU();
    state = rotateB->operate(1, state);
    state = rotateD->operate(0, state);
    state = rotateF->operate(2, state);
    state = rotateL->operate(1, state);
    state = rotateR->operate(0, state);
    state = rotateU->operate(2, state);
    state->cube->print();
    return 0;
}