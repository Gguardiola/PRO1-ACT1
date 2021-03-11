#ifndef ASSIGNACIO_HPP
#define ASSIGNACIO_HPP
#include <iostream>
using namespace std;

class Assignacio{
//Tipo de modulo: datos.
//Descripcion del tipo: contiene un vector de 2^n variables bool.

private:


public:

//Constructores
Assignacio();
    //PRE: cierto.
    //POST: el resultado es una assignación sin variables.

Assignacio (int n);
    //PRE; cierto.
    //POST: el resultado es una asignacion con n variables.

//Destructor
~Assignacio();
/* Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat */

//Modificadores
Assignacio operator++(const Assignacio &a);
    /* Pre: cierto*/
    /* Post: el resultado es la siguiente asignacion (orden total)*/

//Consultores




}
#endif