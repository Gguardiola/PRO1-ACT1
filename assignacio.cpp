#include "assignacio.hpp"
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

//Constructores
Assignacio:: Assignacio(){
    //PRE: cierto.
    //POST: el resultado es una asignacion sin variables.

//error 404 not FOUND

}


Assignacio:: Assignacio (int n){
    //PRE: cierto.
    //POST: el resultado es una asignacion con n variables en orden alfabetico.

    vector <bool> boolAssig(n,false);
    vector <char> charAssig(n);
    int it=0;

}
//Destructor
Assignacio::~Assignacio(){
    /* Post: borra automaticamente los objetos locales al salir de un ambito de visibilidad */

}
//Modificadores
void Assignacio:: setVariables (vector <char> vars){
    //PRE: cierto.
    //POST: modifica un vector <char> vacio, añadiendo las variables de la asignación.
            //vector={a,b,c,d,···,z}

    for (int i=0; i<int(vars.size());i++){
        charAssig[i]=vars[i];
    }

}
void Assignacio:: operator++(const Assignacio &a){
    /* Pre: cierto*/
    /* Post: calcula la siguiente asignacion (orden total:empezando por la ultima variable)*/

    
    bitset <boolAssig.size()> ordre(it);
        
    for (int i=0; i<int(boolAssig.size());i++){
        boolAssig[i]=false;
    }

    for (int i=0; i<int(boolAssig.size());i++){
        if (ordre[i]==1) boolAssig[i]=true;
    }

    it++;

}
//Consultores
bool Assignacio:: getVariable (char var){
    //PRE: cierto.
    //POST: devuelve el valor bool correspondiente a la variable.
            //input (a) = output (false)

    bool found=false;
    int i=0;
    while (not found and i<int(charAssig.size()){
        if(charAssig[i]==var){
            found=false;
        }
    }

    return boolAssig[i];

}
