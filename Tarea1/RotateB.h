#include "State_Operator.h"

class RotateB : public State_Operator {
public:
    //Constructor de la clase RotateB
    RotateB();
    //Destructor de la clase RotateB
    ~RotateB();
    //Metodo de rotar el cubo
    State* operate(int s, State* cube);
};