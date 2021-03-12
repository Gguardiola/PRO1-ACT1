#include "assignacio.hpp"
#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
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
    //POST: modifica un vector <char> vacio, añadiendo las variables de la asignación.
            //vector={a,b,c,d,···,z}
    
    for (int i=0; i<int(vars.size());i++){
        charAssig.push_back(vars[i]);
    }

}

void Assignacio::resetAssig (){
    //PRE: cierto.
    //POST: reinicia el iterador it para reiniciar las asignaciones binarias (todo a false y listo para volver a operar las combinaciones desde 0).
    //ej: false, false, false, true, true | it = 3 -------- false, false, false, false, false | it = 0;
    it = 0;
    for (int i=0; i<int(boolAssig.size());i++){
        boolAssig[i]=false;
    }  
}
void Assignacio::operator++() {
    /* Pre: cierto*/
    /* Post: calcula la siguiente asignacion (orden total:empezando por la ultima variable)*/
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
    //POST: devuelve el valor bool correspondiente a la variable.
            //input (a) = output (false)

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