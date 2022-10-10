#ifndef RUBIK_H
#define RUBIK_H 
 
#include <iostream>
#include <cstdlib>
#include <ctime>

#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define ORANGE 5
#define WHITE 6
class Rubik{
    public:
    int U[3][3];
    int D[3][3];
    int L[3][3];
    int R[3][3];
    int F[3][3];
    int B[3][3];
    //Constructor
    Rubik();
    //Constructor
    Rubik(Rubik *r);
    //Destructor
    ~Rubik();
    //Metodo para imprimir
    void print();
    //Metodo para rotar la cara superior
    Rubik* rotateU(int s);
    //Metodo para rotar la cara inferior
    Rubik* rotateD(int s);
    //Metodo para rotar la cara izquierda
    Rubik* rotateL(int s);
    //Metodo para rotar la cara derecha
    Rubik* rotateR(int s);
    //Metodo para rotar la cara frontal
    Rubik* rotateF(int s);
    //Metodo para rotar la cara trasera
    Rubik* rotateB(int s);
    //Metodo para verificar si es igual
    int equal(Rubik *r);
    //Metodo para verificar si esta resuelto
    int isSolved();
    //Metodo para revolver el cubo
    Rubik* scramble(int steps);
    private:
    //Metodo para imprimir una cara
    void printFace(int face[3][3]);
    //Metodo para imprimir una linea
    void printLine(int face[3][3], int i);
};

#endif