#include <iostream>
#include <fstream>
#include <vector>
#include "head.h"

int programacionD (int capacidad, int cant, std::vector<Objeto> cosas);

int programacionD (int capacidad, int cant, std::vector<Objeto> cosas) {
    int res;

    if(cant == 0 || capacidad == 0) {
        res = 0;

    } else  if(cosas[cant-1].peso > capacidad) {
        res = programacionD(capacidad, cant-1, cosas);

    } else {
        int res1, res2;
        res1 = programacionD(capacidad, cant-1, cosas);
        res2 = cosas[cant-1].benef + programacionD(capacidad-cosas[cant-1].peso, cant-1, cosas);
        res = std::max(res1, res2);

    }
    return res;
}