#include "Path.h"

int main() {
    Path *path = new Path();
    path -> insert("B+");
    path -> insert("B-");
    path -> insert("B+");
    path -> print();
    return 0;
}