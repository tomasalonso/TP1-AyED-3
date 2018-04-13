#include <iostream>
#include <fstream>
#include "head.h"

int fuerzaBruta(int capacidad, int cant, std::vector<Objeto> cosas);

int fuerzaBruta(int capacidad, int cant, std::vector<Objeto> cosas) {
    int num = pow(2, cant) - 1;
    int iter, res = 0, resparcial = 0, peso = 0;
    for(int i = 0; i <= num; i++) {
        iter = i;
        for(int j = 0; j < cant; j++) {
            if(1 & iter) {
                peso += cosas[j].peso;
                resparcial += cosas[j].benef;
            }
            iter = iter>>1;
        }
        //std::cout << "resolucion parcial "<< resparcial << " con peso " << peso << " iteracion = " << i << "\n";
        if((resparcial > res) && (capacidad >= peso)) res = resparcial;
        resparcial = 0;
        peso = 0;
    }
    return res;
}
