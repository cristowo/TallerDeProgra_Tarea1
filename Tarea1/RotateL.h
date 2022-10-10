#include "State_Operator.h"

class RotateL : public State_Operator {
public:
    //Constructor de la clase RotateL
    RotateL();
    //Destructor de la clase RotateL
    ~RotateL();
    //Metodo de rotar el cubo
    State* operate(int s, State* cube);
};

