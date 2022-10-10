#include "Rubik.h"
#define KEND  "\033[0m"
#define KRED  "\033[41m"
#define KGRN  "\033[42m"
#define KYEL  "\033[103m"
#define KBLU  "\033[44m"
#define KORA  "\033[45m"
#define KCYN  "\033[36m"
#define KWHT  "\033[107m"

/*
* Constructor
* Parametros: 
* Retorno: 
*/
Rubik::Rubik() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            U[i][j] = WHITE;
            D[i][j] = YELLOW;
            L[i][j] = GREEN;
            R[i][j] = BLUE;
            F[i][j] = RED;
            B[i][j] = ORANGE;
        }
    }
}
/*
* Destructor
* Parametros:
* Retorno:
*/
Rubik::~Rubik() {
    // destructor
}

/*
* Compara 2 Cubos.
* Parametros: 1 Cubo
* Retorno: Entero
*/
int Rubik::equal(Rubik *r) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (U[i][j] != r->U[i][j] || 
                D[i][j] != r->D[i][j] || 
                L[i][j] != r->L[i][j] || 
                R[i][j] != r->R[i][j] || 
                F[i][j] != r->F[i][j] || 
                B[i][j] != r->B[i][j]) {
                return 0; //falso
            }
        }
    }
    return 1; //verdadero
}

/*
* Imprime 1 cara
* Parametros: 1 cara
* Retorno:
*/
void Rubik::printFace(int face[3][3]) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            std::cout << face[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/*
* Imprime 1 fila de una cara con su respectivo color
* Parametros: 1 cara, número de la fila.
* Retorno:
*/
void Rubik::printLine(int face[3][3], int i) {
   for (int j=0; j<3; j++) {
       if(face[i][j] == 1){
       std::cout << KRED << "  " << KEND;
       }
       else if(face[i][j] == 2){
       std::cout << KGRN << "  " << KEND;
       }
       else if(face[i][j] == 3){
       std::cout << KBLU << "  " << KEND;
       }
       else if(face[i][j] == 4){
       std::cout << KYEL << "  " << KEND;
       }
       else if(face[i][j] == 5){
       std::cout << KORA << "  " << KEND;
       }
       else{
           std::cout << KWHT << "  " << KEND;
       }
   }
}

/*
void Rubik::print() {
    printFace(U);
    printFace(D);
    printFace(L);
    printFace(R);
    printFace(F);
    printFace(B);
    std::cout << std::endl;
}
*/

/*
* Imprime todo el cubo.
* Parametros:
* Retorno:
*/
void Rubik::print() {
    std::cout << "- - - - - - - - - - - -" << std::endl;
   for (int i=0; i<3; i++) {
   std::cout << "- - - ";
   printLine(U, i);
   std::cout << "- - - - - -" << std::endl;
   }
   for (int i=0; i<3; i++) {
   printLine(L, i);
   printLine(F, i);
   printLine(R, i);
   printLine(B, i);
   std::cout << " " << std::endl;
   }
   for (int i=0; i<3; i++) {
   std::cout << "- - - ";
   printLine(D, i);
   std::cout << "- - - - - -" << std::endl;
   }
   std::cout << "- - - - - - - - - - - -" << std::endl;
}
/*
* Gira la cara superior
* Parametros: Orientacion (-1 o 1)
* Retorno: Un cubo.
*/
Rubik* Rubik::rotateU(int s) {
    Rubik *r = new Rubik();
    // respaldo de las caras
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            r->U[i][j] = U[i][j];
            r->D[i][j] = D[i][j];
            r->L[i][j] = L[i][j];
            r->R[i][j] = R[i][j];
            r->F[i][j] = F[i][j];
            r->B[i][j] = B[i][j];
        }
    }
    // rotacion de la matriz

    // GIRO -1
    if(s == -1){
        for (int i=0; i<3; i++) {
            // primera fila de U a ultima columna 
            for(int j=0; j<3; j++){
                r->U[i][j] = U[2-j][i];
            }
            // primerafila F->L
            r->L[0][i] = F[0][i];
            // primerafila L->B
            r->B[0][i] = L[0][i];
            // primerafila B->R
            r->R[0][i] = B[0][i];
            // primerafila R->F
            r->F[0][i] = R[0][i];
        }
    }
    // GIRO 1
    else if(s == 1){
        for (int i=0; i<3; i++) {
            // primera fila de U a ultima columna 
            for(int j=0; j<3; j++){
                r->U[i][j] = U[j][2-i];
            }
            // primerafila F->R
            r->R[0][i] = F[0][i];
            // primerafila L->F
            r->F[0][i] = L[0][i];
            // primerafila B->L
            r->L[0][i] = B[0][i];
            // primerafila R->B
            r->B[0][i] = R[0][i];
        }
    }return r;}


/*
* Giro de la cara Inferior (D)
* Parametros: Orientacion (-1 o 1)
* Retorno: Un Cubo.
*/
Rubik* Rubik::rotateD(int s){
    Rubik *r = new Rubik();
    // respaldo de las caras
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            r->U[i][j] = U[i][j];
            r->D[i][j] = D[i][j];
            r->L[i][j] = L[i][j];
            r->R[i][j] = R[i][j];
            r->F[i][j] = F[i][j];
            r->B[i][j] = B[i][j];
        }
    }
    // rotacion de la matriz

    // GIRO -1
    if(s == -1){
        for (int i=0; i<3; i++) {
            // primera fila de D a ultima columna 
            for(int j=0; j<3; j++){
                r->D[i][j] = D[2-j][i];
            }
            // primerafila F->R
            r->R[2][i] = F[2][i];
            // primerafila L->F
            r->F[2][i] = L[2][i];
            // primerafila B->L
            r->L[2][i] = B[2][i];
            // primerafila R->B
            r->B[2][i] = R[2][i];
        }
    }
    // GIRO 1
    else if(s == 1){
        for (int i=0; i<3; i++) {
            // primera fila de D a ultima columna 
            for(int j=0; j<3; j++){
                r->D[i][j] = D[j][2-i];
            }
            // primerafila F->L
            r->L[2][i] = F[2][i];
            // primerafila L->B
            r->B[2][i] = L[2][i];
            // primerafila B->R
            r->R[2][i] = B[2][i];
            // primerafila R->F
            r->F[2][i] = R[2][i];
        }
    }
    return r;
}

/*
* Giro de la cara Izquierda (L)
* Parametros: Orientacion (-1 o 1)
* Retorno: Un Cubo.
*/
Rubik* Rubik::rotateL(int s){
    Rubik *r = new Rubik();
    // respaldo de las caras
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            r->U[i][j] = U[i][j];
            r->D[i][j] = D[i][j];
            r->L[i][j] = L[i][j];
            r->R[i][j] = R[i][j];
            r->F[i][j] = F[i][j];
            r->B[i][j] = B[i][j];
        }
    }
    // rotacion de la matriz

    // GIRO -1
    if(s == -1){
        for (int i=0; i<3; i++) {
            // primera fila de L a ultima columna 
            for(int j=0; j<3; j++){
                r->L[i][j] = L[2-j][i];
            }
            // primerafila U->F
            r->F[i][0] = U[i][0];
            // primerafila F->D
            r->D[i][0] = F[i][0];
            // primerafila D->B
            r->B[i][2] = D[2-i][0];
            // primerafila B->U
            r->U[i][0] = B[2-i][2];
        }
    }
    // GIRO 1
    else if(s == 1){
        for (int i=0; i<3; i++) {
            // primera fila de L a ultima columna 
            for(int j=0; j<3; j++){
                r->L[i][j] = L[j][2-i];
            }
            // primerafila U->B
            r->B[2-i][2] = U[i][0];
            // primerafila F->U
            r->U[i][0] = F[i][0];
            // primerafila D->F
            r->F[i][0] = D[i][0];
            // primerafila B->D
            r->D[2-i][0] = B[i][2];
        }
    }
    return r;
}

/*
* Giro de la cara Derecha (R)
* Parametros: Orientacion (-1 o 1)
* Retorno: Un Cubo.
*/
Rubik* Rubik::rotateR(int s){
    Rubik *r = new Rubik();
    // respaldo de las caras
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            r->U[i][j] = U[i][j];
            r->D[i][j] = D[i][j];
            r->L[i][j] = L[i][j];
            r->R[i][j] = R[i][j];
            r->F[i][j] = F[i][j];
            r->B[i][j] = B[i][j];
        }
    }
    // rotacion de la matriz

    // GIRO -1
    if(s == -1){
        for (int i=0; i<3; i++) {
            // primera fila de R a ultima columna 
            for(int j=0; j<3; j++){
                r->R[i][j] = R[2-j][i];
            }
            // primerafila U->B
            r->B[2-i][0] = U[i][2];
            // primerafila F->U
            r->U[i][2] = F[i][2];
            // primerafila D->F
            r->F[i][2] = D[i][2];
            // primerafila B->D
            r->D[2-i][2] = B[i][0];
        }
    }
    // GIRO 1
    else if(s == 1){
        for (int i=0; i<3; i++) {
            // primera fila de R a ultima columna 
            for(int j=0; j<3; j++){
                r->R[i][j] = R[j][2-i];
            }
            // primerafila U->F
            r->F[i][2] = U[i][2];
            // primerafila F->D
            r->D[i][2] = F[i][2];
            // primerafila D->B
            r->B[i][0] = D[2-i][2];
            // primerafila B->U
            r->U[i][2] = B[2-i][0];
        }
    }
    return r;
}

/*
* Giro de la cara Frontal (F)
* Parametros: Orientacion (-1 o 1)
* Retorno: Un Cubo.
*/
Rubik* Rubik::rotateF(int s){
    Rubik *r = new Rubik();
    // respaldo de las caras
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            r->U[i][j] = U[i][j];
            r->D[i][j] = D[i][j];
            r->L[i][j] = L[i][j];
            r->R[i][j] = R[i][j];
            r->F[i][j] = F[i][j];
            r->B[i][j] = B[i][j];
        }
    }
    // rotacion de la matriz

    // GIRO -1
    if(s == -1){
        for (int i=0; i<3; i++) {
            // primera fila de F a ultima columna 
            for(int j=0; j<3; j++){
                r->F[i][j] = F[2-j][i];
            }
            // primerafila U->R
            r->R[i][0] = U[2][i];
            // primerafila R->D
            r->D[0][2-i] = R[i][0];
            // primerafila D->L
            r->L[i][2] = D[0][i];
            // primerafila L->U
            r->U[2][2-i] = L[i][2];
        }
    }
    // GIRO 1
    else if(s == 1){
        for (int i=0; i<3; i++) {
            // primera fila de F a ultima columna 
            for(int j=0; j<3; j++){
                r->F[i][j] = F[j][2-i];
            }
            // primerafila U->L
            r->L[i][2] = U[2][2-i];
            // primerafila R->U
            r->U[2][i] = R[i][0];
            // primerafila D->R
            r->R[i][0] = D[0][2-i];
            // primerafila L->D
            r->D[0][i] = L[i][2];
        }
    }
    return r;
}

/*
* Giro de la cara Trasera (B)
* Parametros: Orientacion (-1 o 1)
* Retorno: Un Cubo.
*/
Rubik* Rubik::rotateB(int s){
    Rubik *r = new Rubik();
    // respaldo de las caras
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            r->U[i][j] = U[i][j];
            r->D[i][j] = D[i][j];
            r->L[i][j] = L[i][j];
            r->R[i][j] = R[i][j];
            r->F[i][j] = F[i][j];
            r->B[i][j] = B[i][j];
        }
    }
    // rotacion de la matriz

    // GIRO -1
    if(s == -1){
        for (int i=0; i<3; i++) {
            // primera fila de B a ultima columna 
            for(int j=0; j<3; j++){
                r->B[i][j] = B[2-j][i];
            }
            // primerafila R->U
            r->U[0][i] = R[i][2];
            // primerafila U->L
            r->L[2-i][0] = U[0][i];
            // primerafila L->D
            r->D[2][i] = L[i][0];
            // primerafila D->R
            r->R[i][2] = D[2][2-i];
        }
    }
    // GIRO 1
    else if(s == 1){
        for (int i=0; i<3; i++) {
            // primera fila de B a ultima columna 
            for(int j=0; j<3; j++){
                r->B[i][j] = B[j][2-i];
            }
            // primerafila R->D
            r->D[2][2-i] = R[i][2];
            // primerafila D->L
            r->L[i][0] = D[2][i];
            // primerafila L->U
            r->U[0][i] = L[2-i][0];
            // primerafila U->R
            r->R[i][2] = U[0][i];
        }
    }
    return r;
}

/*
* Verifica si el cubo esta resuelto
* Parametros: Ninguno
* Retorno: Un Entero
*/
int Rubik::isSolved() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (U[i][j] != WHITE || 
                D[i][j] != YELLOW || 
                L[i][j] != GREEN || 
                R[i][j] != BLUE || 
                F[i][j] != RED || 
                B[i][j] != ORANGE) {
                return 0;
            }
        }
    }
    return 1;
}

/*
* Funcion que revuelve el cubo
* Parametros: Numero de movimientos
* Retorno: Un Cubo.
*/
Rubik* Rubik::scramble(int steps){
    Rubik *r = new Rubik(), *temp;
    for(int i=0; i<steps;i++){
        int c = rand()%6;
        int s = 2*(rand()%2)-1;
        switch(c){
            case 0:
                temp = r->rotateU(s);
                break;
            case 1:
                temp = r->rotateD(s);
                break;
            case 2:
                temp = r->rotateL(s);
                break;
            case 3:
                temp = r->rotateR(s);
                break;
            case 4:
                temp = r->rotateF(s);
                break;
            case 5:
                temp = r->rotateB(s);
                break;
        }
        delete r;
        r = temp;
    }
    return r;
}