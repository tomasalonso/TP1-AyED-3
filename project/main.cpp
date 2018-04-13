#include <iostream>
#include <fstream>
#include <vector>
#include "head.h"
#include "fuerzaBruta.cpp"
#include "bactracking.cpp"
#include "programacionDinamica.cpp"

std::vector<Objeto> procesar(std::string archivo, int *mochila, int *cantidad);

int main() {
    int* mochila = new int;
    int* cant = new int;



    std::vector<Objeto> todos = procesar("text", mochila, cant);

    int result = backtracking(*mochila, *cant, 0, 0, todos);
    int res2 = fuerzaBruta(*mochila, *cant, todos);
    int resultado = programacionD(*mochila, *cant, todos);

    std::cout << result << "\n";
    std::cout << res2 << "\n";
    std::cout << resultado << "\n";

   // std::vector<Objeto> todos2 = procesar("text2", mochila, cant);

    //int res3 = fuerzaBruta(*mochila, *cant, todos2);

    //std::cout << res3 << "\n";

    return 0;
}

//
//
//      aca empiezan las funciones
//
//

std::vector<Objeto> procesar(std::string texto, int *mochila, int *cantidad) {

    std::ifstream ifs(texto);
    if(ifs.fail()){
        std::cout << "failed " << "\n";
    }

    int i, j;
    ifs >> i >> j;
    std:: cout << "cantidad = " << i << ", mochila puede tener = " << j << "\n";
    std::vector<Objeto> todos; //creo mi grupo de objetos
    *mochila = j;
    *cantidad = i;
    int g = 0;

    while(ifs >> i >> j && i != 0 && j != 0) {//los pongo en sus lugares
        Objeto cosa;
        cosa.peso = i;
        cosa.benef = j;
        todos.push_back(cosa);
        std::cout << "el objeto = " << g << " pesa " << i << " con beneficio " << j << "\n";
        g++;
    }
    ifs.close();
    return todos;
}