#ifndef ASSIGNACIO_HPP
#define ASSIGNACIO_HPP
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

class Assignacio{
//Tipo de modulo: datos.
//Descripcion del tipo: contiene un vector de 2^n variables bool y un vector de 2^n variables char. ejemplo:[a,b,f...]

private:

    vector <bool> boolAssig; //vector de 2^n variables bool [false,false,false...]
    vector <char> charAssig; //vector de 2^n variables char [a,b,c,f,q...]
    int it; //controla la cantidad de iteraciones ++ que se han realizado sobre el objeto
    bool fin; //controla si se ha llegado al final de las iteraciones ++
public:

//Constructores
Assignacio();
    //PRE: cierto.
    //POST: no puede realizar asignaciones si no hay valor para las n variables.

Assignacio (int n);
    //PRE: cierto.
    //POST: el resultado es una asignacion con n variables bool.

//Destructor
~Assignacio();
    /* Post: borra automaticamente los objetos locales al salir de un ambito de visibilidad */

//Modificadores
void setVariables (vector <char> vars);
    //PRE: cierto.
    //POST: rellena el vector de variables char del objeto con todas las variables posibles de las implicaciones.
    //De este modo se podrá relacionar las variables con su valor booleano del otro vector a la hora de operar las implicaciones. Ejemplo: "a" (posición 0 del vector char) se relaciona con "false"(posición 0 del vector bool)

void resetAssig ();
    //PRE: cierto.
    //POST: reinicia el iterador it para reiniciar las asignaciones (todo a false y listo para volver a operar las combinaciones desde cero).
    //ej: false, false, false, true, true | it = 3 -------- false, false, false, false, false | it = 0;

void operator ++(); 
    /* Pre: cierto*/
    /* Post: calcula la siguiente asignacion. Ejemplo: it=2 boolAssig=[false,true,false] ----- it++ (it=3) boolAssig=[false,true,true]*/

//Consultores
bool getVariable (char var);
    //PRE: cierto.
    //POST: devuelve el valor bool correspondiente a la variable introducida
    //Busca la variable en el vector de chars y como mide igual que el vector de booleanos devuelve el valor bool que corresponde en el vector bool
            //Ejemplo: input (a) = output (false)
bool isFinal ();
    //PRE: cierto.
    //POST: devuelve true si el objeto se encuentra en la asignacion final (todas true)

};
#endif