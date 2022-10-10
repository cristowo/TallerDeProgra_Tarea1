#include "State_Operator.h"

class RotateD : public State_Operator {
public:
    //Constructor de la clase RotateD
    RotateD();
    //Destructor de la clase RotateD
    ~RotateD();
    //Metodo de rotar el cubo
    State* operate(int s, State* state);
};