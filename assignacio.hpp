#ifndef ASSIGNACIO_HPP
#define ASSIGNACIO_HPP
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

class Assignacio{
//Tipo de modulo: datos.
//Descripcion del tipo: contiene un vector de 2^n variables bool.

private:

    vector <bool> boolAssig;
    vector <char> charAssig;
    int it; 
    bool fin;  
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

void resetAssig ();
    //PRE: cierto.
    //POST: reinicia el iterador it para reiniciar las asignaciones binarias (todo a false y listo para volver a operar las combinaciones desde 0).
    //ej: false, false, false, true, true | it = 3 -------- false, false, false, false, false | it = 0;

void operator ++(); 
    /* Pre: cierto*/
    /* Post: calcula la siguiente asignacion (orden total:empezando por la ultima variable)*/

//Consultores
bool getVariable (char var);
    //PRE: cierto.
    //POST: devuelve el valor bool correspondiente a la variable.
            //input (a) = output (false)
bool isFinal ();
    //PRE: cierto.
    //POST: devuelve true si el objeto se encuentra en la asignacion final (todas true)

};
#endif