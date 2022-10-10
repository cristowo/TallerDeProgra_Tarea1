#include "State_Operator.h"

class RotateU : public State_Operator {
public:
    //Constructor de la clase RotateU
    RotateU();
    //Destructor de la clase RotateU
    ~RotateU();
    //Metodo de rotar el cubo
    State* operate(int s, State* state);
};