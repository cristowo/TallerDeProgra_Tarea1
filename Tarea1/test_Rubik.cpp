#include <iostream>
#include "Rubik.h"

int main() {
    Rubik *rubik=new Rubik();
    rubik->print();
    delete rubik;

    for(int i=0;i<10000;i++) {
        Rubik *rubik=new Rubik();
        delete rubik;
    }

}