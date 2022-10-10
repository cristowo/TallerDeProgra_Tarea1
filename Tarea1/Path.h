#ifndef _PATH_H_
#define _PATH_H_
#include <iostream>

class Path {
public:
    std::string path;
    //Constructor de la clase Path
    Path();
    //Destructor de la clase Path
    ~Path();
    //Metodo de insertar un movimiento en el array
    void insert(std::string op);
    //Metodo de obtener el tamaño del array
    int size();
    //Metodo de imprimir el array
    void print();
};

#endif // _PATH_H_