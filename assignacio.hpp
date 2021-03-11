#ifndef ASSIGNACIO_HPP
#define ASSIGNACIO_HPP
#include <iostream>

using namespace std;

class Assignacio{
//Tipo de modulo: datos.
//Descripcion del tipo: contiene un vector de 2^n variables bool.

private:

    vector <bool> boolAssig;
    vector <char> charAssig;

public:

//Constructores
Assignacio();
    //PRE: cierto.
    //POST: el resultado es una asignacion sin variables.

Assignacio (int n);
    //PRE: cierto.
    //POST: el resultado es una asignacion con n variables en orden alfabetico.

//Destructor
~Assignacio();
    /* Post: borra automaticamente los objetos locales al salir de un ambito de visibilidad */

//Modificadores
void setVariables (vector <char> vars);
    //PRE: cierto.
    //POST: modifica un vector <char> vacio, añadiendo las variables de la asignación.
            //vector={a,b,c,d,···,z}
void operator++(const Assignacio &a);
    /* Pre: cierto*/
    /* Post: calcula la siguiente asignacion (orden total)*/

//Consultores
bool getVariable (char var);
    //PRE: cierto.
    //POST: devuelve el valor bool correspondiente a la variable.
            //input (a) = output (false)




}
#endif