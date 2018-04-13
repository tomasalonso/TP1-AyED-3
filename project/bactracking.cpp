#include <iostream>
#include <fstream>
#include "head.h"

int backtracking(int capacidad, int cant, int actual, int pesoact, std::vector<Objeto> cosas);

int backtracking(int capacidad, int cant, int actual, int pesoact, std::vector<Objeto> cosas) {
    int res1 = 0, res2 = 0;

    if (actual < cant) {
        if (pesoact + cosas[actual].peso <= capacidad) {
            int pesoaux = pesoact + cosas[actual].peso;
            res1 = cosas[actual].benef + backtracking(capacidad, cant, actual+1, pesoaux, cosas);
        }
        res2 = backtracking(capacidad, cant, actual+1, pesoact, cosas);
    }
    res1 = std::max(res1, res2);
    return res1;
}
