#include "Rubik_Solver.h"

/*
Clase Rubik_Solver que permite resolver un cubo de Rubik
*/

/*
* Constructor de la clase Rubik_Solver
* @param Rubik* cubo a resolver
*/
Rubik_Solver::Rubik_Solver(Rubik *rubik) {
    this->cube = rubik;
    this->initialState = new State(rubik);
    this->open = new Idea();
    this->closed = new Idea();
    this->operators[0] = new RotateU();
    this->operators[1] = new RotateD();
    this->operators[2] = new RotateF();
    this->operators[3] = new RotateB();
    this->operators[4] = new RotateL();
    this->operators[5] = new RotateR();
}

/*
* Destructor de la clase Rubik_Solver
*/
Rubik_Solver::~Rubik_Solver() {
    delete this->initialState;
    delete this->open;
    delete this->closed;
}

/*
* Metodo de resolver el cubo
* @return Path* camino solucion
*/
Path *Rubik_Solver::solve(){
    //--------INICIALIZAR------------------
    int cost = 0;
    int cond = 0;
    std::string opera = "";
    //------------------------------------
    //------------- A* -------------------
    State *current, *next;
    open->insert(initialState); //establecemos estado inicial
                                // tener en cuenta que closed esta vacia en esta instancia
    //-------INICIO WHILE-----------------------------------------------------------------------                            
    while(!open->isEmpty()){

        current = open->getNodo();   //obtenemos el mejor nodo de la lista (heuristica)

        if(current->cube->isSolved()){      //si el nodo es solucion        
            current->cube->print();
            //current->getPath()->print();
            return current->getPath();      //retornamos el camino
        } 

        /*
        //mas que nada dejo esto aqui, para ver los nodos que se van generando
        std::cout << "condicion: " << cond << " open: " << open->size << " closed: " << closed->size << std::endl;
        std::cout << "costo: " << cost << std::endl;
        std::cout << "operacion: " << current->op << std::endl;
        current->getPath()->print();
        current->cube->print();
        */

        //--------- CRUZ -------------------------------------------------------------------   
        if(cond == 0 && oneHeuristic(current) == 0){  
            cond = 1;
            //std::cout << "condicion: " << cond << " open: " << open->size << " closed: " << closed->size << std::endl;
            //current->cube->print();
            //moveToClose();

        }
        //------PRIMERA CARA---------------------------------------------------------------------------   
        if(cond == 1 && oneHeuristic(current) == 0 && twoHeuristic(current, 0) == 0){
            //std::cout << "condicion: " << cond << " open: " << open->size << " closed: " << closed->size << std::endl;
            //current->cube->print();
            //return nullptr;
            cond = 2;
        }
        //--------SEGUNDA CARA-------------------------------------------------------------------------
        if(cond == 2 && oneHeuristic(current) == 0 && twoHeuristic(current, 0) == 0 && threeHeuristic(current, 0) == 0){
            //std::cout << "condicion: " << cond << " open: " << open->size << " closed: " << closed->size << std::endl;
            //current->cube->print();
            cond = 3;
        }
        //--------CRUZ AMARILLA-------------------------------------------------------------------------
        if(cond == 3 && oneHeuristic(current) == 0 && twoHeuristic(current, 0) == 0 && threeHeuristic(current, 0) == 0 && fourHeuristic(current, 0) == 0){
            //std::cout << "condicion: " << cond << " open: " << open->size << " closed: " << closed->size << std::endl;
            //current->cube->print();
            cond = 4;
        }
        //--------TERCERA CARA-------------------------------------------------------------------------
        if(cond == 4 && oneHeuristic(current) == 0 && twoHeuristic(current, 0) == 0 && threeHeuristic(current, 0) == 0 && fourHeuristic(current, 0) == 0 && fiveHeuristic(current, 0) == 0){
            //std::cout << "condicion: " << cond << " open: " << open->size << " closed: " << closed->size << std::endl;
            //current->cube->print();
            cond = 5;
        }
        //----------------------------------------------------------------------------------------  

        //open->remove(current);           //eliminamos el nodo de la lista abierta
        closed->insertC(current);         //insertamos el nodo en la lista cerrada
        for(int i = 0; i < 6; i++){                         //recorremos los operadores (12)
            for(int s = 0; s < 3; s++){
                next = operators[i]->operate(s, current);   //generamos el siguiente nodo
                if(wasNotGenerated(next)){  //si el nodo no esta en la lista cerrada y abierta
                                                                //limita el movimiento a 1 vez por cara
                    if(next->prev != i){                         //next->getPath()->size() < 27 (lo dejo comentado aqui nada mas xd)              
                        cost = getHeuristic(next, cond);        //calculamos la heuristica
                        next->cost = cost;                      //establecemos el costo    
                        next->prev = i;
                        open->insert(next);                     //insertamos el nodo en la lista abierta 
                                                                //(lista de todos los nodos abiertos)
                    }
                    //else{ closed->insertC(next); }
                } 
            }
        }
    }
    return nullptr;      
}

/*
* Metodo que verifica si un nodo ya fue generado
* @param State* nodo a verificar
* @return bool true si no fue generado, false si fue generado
*/
bool Rubik_Solver::wasNotGenerated(State *next) {
    return !closed->find(next) && !open->find(next);
}

/*
* Metodo que calcula la heuristica de un nodo
* @param State* nodo a calcular, int condicion
* @return int costo de la heuristica
*/
int Rubik_Solver::getHeuristic(State *state, int cond){
    int heuristic = 0;

    heuristic = oneHeuristic(state);

    if(cond > 0){heuristic = twoHeuristic(state, heuristic);}

    if(cond > 1){heuristic = threeHeuristic(state, heuristic);}

    if(cond > 2){heuristic = fourHeuristic(state, heuristic);}

    if(cond > 3){heuristic = fiveHeuristic(state, heuristic);}

    return heuristic;}

/*
* Metodo que calcula la heuristica de un nodo
* @param State* nodo a calcular
* @return int costo de la heuristica
*/
int Rubik_Solver::oneHeuristic(State *state){
    int heuristic = 0;

    if(state->cube->U[0][1] != WHITE || state->cube->B[0][1] != ORANGE){heuristic+=2;}
    if(state->cube->U[1][0] != WHITE || state->cube->L[0][1] != GREEN){heuristic+=2;}
    if(state->cube->U[1][2] != WHITE || state->cube->R[0][1] != BLUE){heuristic+=2;}
    if(state->cube->U[2][1] != WHITE || state->cube->F[0][1] != RED){heuristic+=2;}

    return heuristic;
}

/*
* Metodo que calcula la heuristica de un nodo
* @param State* nodo a calcular, int costo de la heuristica
* @return int costo de la heuristica
*/
int Rubik_Solver::twoHeuristic(State *state, int heuristic){
    
    if(state->cube->U[0][0] != WHITE || state->cube->L[0][0]!= GREEN || state->cube->B[0][2] != ORANGE){heuristic+=2;} 
    if(state->cube->U[0][2] != WHITE || state->cube->R[0][2]!= BLUE || state->cube->B[0][0] != ORANGE){heuristic+=2;}
    if(state->cube->U[2][0] != WHITE || state->cube->L[0][2]!= GREEN || state->cube->F[0][0] != RED){heuristic+=2;}
    if(state->cube->U[2][2] != WHITE || state->cube->R[0][0]!= BLUE || state->cube->F[0][2] != RED){heuristic+=2;}
    return heuristic;
}

/*
* Metodo que calcula la heuristica de un nodo
* @param State* nodo a calcular, int costo de la heuristica
* @return int costo de la heuristica
*/
int Rubik_Solver::threeHeuristic(State *state, int heuristic){
    if(state->cube->F[1][0] != RED || state->cube->L[1][2] != GREEN){heuristic+=2;}
    if(state->cube->F[1][2] != RED || state->cube->R[1][0] != BLUE){heuristic+=2;}
    if(state->cube->B[1][2] != ORANGE || state->cube->L[1][0] != GREEN){heuristic+=2;}
    if(state->cube->B[1][0] != ORANGE || state->cube->R[1][2] != BLUE){heuristic+=2;}
    return heuristic;
}

/*
* Metodo que calcula la heuristica de un nodo
* @param State* nodo a calcular, int costo de la heuristica
* @return int costo de la heuristica
*/
int Rubik_Solver::fourHeuristic(State *state, int heuristic){
    if(state->cube->F[2][1] != RED || state->cube->D[0][1] != YELLOW){heuristic+=2;}
    if(state->cube->L[2][1] != GREEN || state->cube->D[1][0] != YELLOW){heuristic+=2;}
    if(state->cube->R[2][1] != BLUE || state->cube->D[1][2] != YELLOW){heuristic+=2;}
    if(state->cube->B[2][1] != ORANGE || state->cube->D[2][1] != YELLOW){heuristic+=2;}
    return heuristic;
}

/*
* Metodo que calcula la heuristica de un nodo
* @param State* nodo a calcular, int costo de la heuristica
* @return int costo de la heuristica
*/
int Rubik_Solver::fiveHeuristic(State *state, int heuristic){
    if(state->cube->D[0][0] != YELLOW || state->cube->F[2][0] || state->cube->L[2][2]){heuristic+=2;}
    if(state->cube->D[0][2] != YELLOW || state->cube->F[2][2] || state->cube->R[2][0]){heuristic+=2;}
    if(state->cube->D[2][0] != YELLOW || state->cube->B[2][2] || state->cube->L[2][0]){heuristic+=2;}
    if(state->cube->D[2][2] != YELLOW || state->cube->B[2][0] || state->cube->R[2][2]){heuristic+=2;}
    return heuristic;
}


//este no se uso
//basicamente era para acortar el camino pero siento que no es legal.
State *Rubik_Solver::madeOrder(State *state){
    if(state->cube->F[0][1] != RED){
        if(state->cube->R[0][1] == RED){
            state = operators[5]->operate(-1, state);   //-R
            state = operators[5]->operate(-1, state);   //-R
            state = operators[1]->operate(1, state);    //+D
            state = operators[2]->operate(1, state);    //+F
            state = operators[2]->operate(1, state);    //+F
            state = operators[1]->operate(-1, state);   //-D
            state = operators[5]->operate(-1, state);   //-R
            state = operators[5]->operate(-1, state);   //-R
        }
        else if(state->cube->B[0][1] == RED){
            state = operators[3]->operate(-1, state);   //-B
            state = operators[3]->operate(-1, state);   //-B
            state = operators[1]->operate(1, state);    //+D
            state = operators[1]->operate(1, state);    //+D
            state = operators[2]->operate(1, state);    //+F
            state = operators[2]->operate(1, state);    //+F
            state = operators[1]->operate(-1, state);   //-D
            state = operators[1]->operate(-1, state);   //-D
            state = operators[3]->operate(-1, state);   //-B
            state = operators[3]->operate(-1, state);   //-B
        }
        else if(state->cube->L[0][1] == RED){
            state = operators[4]->operate(-1, state);   //-L
            state = operators[4]->operate(-1, state);   //-L
            state = operators[1]->operate(-1, state);   //-D
            state = operators[2]->operate(1, state);    //+F
            state = operators[2]->operate(1, state);    //+F
            state = operators[1]->operate(1, state);    //-D
            state = operators[4]->operate(-1, state);   //-L
            state = operators[4]->operate(-1, state);   //-L
        }
    }
    if(state->cube->R[0][1] != BLUE){
        if(state->cube->B[0][1] == BLUE){
            state = operators[3]->operate(-1, state);   //-B
            state = operators[3]->operate(-1, state);   //-B
            state = operators[1]->operate(1, state);    //+D
            state = operators[5]->operate(1, state);    //+R
            state = operators[5]->operate(1, state);    //+R
            state = operators[1]->operate(-1, state);   //-D
            state = operators[3]->operate(-1, state);   //-B
            state = operators[3]->operate(-1, state);   //-B
        }
        else if(state->cube->L[0][1] == BLUE){
            state = operators[4]->operate(-1, state);   //-L
            state = operators[4]->operate(-1, state);   //-L
            state = operators[1]->operate(-1, state);   //-D
            state = operators[1]->operate(-1, state);   //-D
            state = operators[5]->operate(1, state);    //+R
            state = operators[5]->operate(1, state);    //+R
            state = operators[1]->operate(1, state);    //-D
            state = operators[1]->operate(1, state);    //-D
            state = operators[4]->operate(-1, state);   //-L
            state = operators[4]->operate(-1, state);   //-L
        }
    }
    if(state->cube->B[0][1] != ORANGE){
        if(state->cube->L[0][1] == ORANGE){
            state = operators[4]->operate(-1, state);   //-L
            state = operators[4]->operate(-1, state);   //-L
            state = operators[1]->operate(1, state);    //+D
            state = operators[3]->operate(1, state);    //+B
            state = operators[3]->operate(1, state);    //+B
            state = operators[1]->operate(-1, state);   //-D
            state = operators[4]->operate(-1, state);   //-L
            state = operators[4]->operate(-1, state);   //-L
        }
    }
    return state;
}

/*
* metodo para mover de open a closed
*/
void Rubik_Solver::moveToClose(){
    int i =0;
    while(!open->isEmpty()){
        closed->insert(open->stateArray[i]);
        open->remove(open->stateArray[i]);
        i++;
    }
    delete open;
    this->open = new Idea();
}

