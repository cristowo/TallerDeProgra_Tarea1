#include "State_Operator.h"

class RotateR : public State_Operator {
public:
    //Constructor de la clase RotateR
    RotateR();
    //Destructor de la clase RotateR
    ~RotateR();
    //Metodo de rotar el cubo
    State* operate(int s, State* state);
};