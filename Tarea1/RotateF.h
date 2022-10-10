#include "State_Operator.h"
#include "State.h"

class RotateF : public State_Operator {
public:
    //Constructor de la clase RotateF
    RotateF();
    //Destructor de la clase RotateF
    ~RotateF();
    //Metodo de rotar el cubo
    State* operate(int s, State* cube);
};