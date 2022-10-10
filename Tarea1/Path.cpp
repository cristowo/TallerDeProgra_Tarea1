#include "Path.h"

/*
Clase Path, array para guardar los movimientos
*/

/*
* Constructor de la clase Path
*/
Path::Path() {
    path = "";
}

/*
* Destructor de la clase Path
*/
Path::~Path() {
}

/*
* Metodo de insertar un movimiento en el array
* @param char movimiento que se va a insertar
* @return Void
*/
void Path::insert(std::string op) {
    path = op + " " + path;
}

/*
* Metodo de obtener el tamaño del array
* @return int tamaño del array
*/
int Path::size() {
    return path.size();
}

/*
* Metodo de imprimir el array
* @return Void
*/
void Path::print() {
    std::cout << path << std::endl;
}

