#include "assignacio.hpp"
#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
using namespace std;

//Constructores
Assignacio:: Assignacio(){
    //PRE: cierto.
    //POST: no puede realizar asignaciones si no hay valor para las n variables.
}

Assignacio:: Assignacio (int n){
    //PRE: cierto.
    //POST: el resultado es una asignacion con n variables bool.
    for (int i=0; i<n;i++){
        boolAssig.push_back(false);
    }    
    it=0;

}
//Destructor
Assignacio::~Assignacio(){
    /* Post: borra automaticamente los objetos locales al salir de un ambito de visibilidad */

}
//Modificadores
void Assignacio::setVariables (vector<char> vars){
    //PRE: cierto.
    //POST: rellena el vector de variables char del objeto con todas las variables posibles de las implicaciones.
    //De este modo se podrá relacionar las variables con su valor booleano del otro vector a la hora de operar las implicaciones. Ejemplo: "a" (posición 0 del vector char) se relaciona con "false"(posición 0 del vector bool)
    
    for (int i=0; i<int(vars.size());i++){
        charAssig.push_back(vars[i]);
    }

}

void Assignacio::resetAssig (){
    //PRE: cierto.
    //POST: reinicia el iterador it para reiniciar las asignaciones (todo a false y listo para volver a operar las combinaciones desde cero).
    //ej: false, false, false, true, true | it = 3 -------- false, false, false, false, false | it = 0;
    it = 0;
    for (int i=0; i<int(boolAssig.size());i++){
        boolAssig[i]=false;
    }  
}
void Assignacio::operator++() {
    /* Pre: cierto*/
    /* Post: calcula la siguiente asignacion. Ejemplo: it=2 boolAssig=[false,true,false] ----- it++ (it=3) boolAssig=[false,true,true]*/
    it++;
    bitset <26> ordre(it);//lo lee alreves!!
    for (int i=0; i<int(boolAssig.size());i++){
        boolAssig[i]=false;
    }  
    int i = int(boolAssig.size())-1;
    int j = 0;
    while(i>=0){
        if(ordre[j] == 1)boolAssig[i] = true;          
        i--;
        j++;
    }       

}
//Consultores
bool Assignacio::getVariable (char var){
    //PRE: cierto.
    //POST: devuelve el valor bool correspondiente a la variable introducida
    //Busca la variable en el vector de chars y como mide igual que el vector de booleanos devuelve el valor bool que corresponde en el vector bool
            //Ejemplo: input (a) = output (false)

    bool found=false;
    int i=0;

    while (i<int(charAssig.size()) and not found){

        if(charAssig[i]==var){
            found=true;
        }
        i++;
    }

    return boolAssig[i-1];

}

bool Assignacio::isFinal (){
    //PRE: cierto.
    //POST: devuelve true si el objeto se encuentra en la asignacion final (todas true)

    fin=false;
    if(it == pow(2, int(boolAssig.size()))) fin = true;
    return fin;

}