#ifndef __STATE_OPERATOR_H__
#define __STATE_OPERATOR_H__
#include <iostream>
#include "State.h"

class State_Operator {
public:
    State_Operator();
    ~State_Operator();
    virtual State* operate(int s, State *state);
};
#endif