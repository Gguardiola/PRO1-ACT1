#include "implicacio.hpp"
#include <iostream>
#include <math.h>
using namespace std;

implicacio::implicacio(){
    /* Pre: cert */
    /* Post: Si no hay implicación no se puede construir un objeto generico */

}

implicacio::implicacio(const string &i){
    /// PRE: cert
    /// POST: Partiendo del parametro implicito i, divida las variables del lado izq y lado der teniendo ">" como referencia de cada lado
    // también guarda todas en un vector all para tratarlas en el getter getAllVariables()
    bool rightSide = false;
    for(int line = 0; line<int(i.size());line++){
        if(i[line] == '>') rightSide = true;
        if(!rightSide){
            if(i[line] >= 'a' and i[line] <= 'z') {
                izq.push_back(i[line]);
                all.push_back(i[line]);             
            }
        }else{
            if(i[line] >= 'a' and i[line] <= 'z') {
                der.push_back(i[line]);
                all.push_back(i[line]); 
            }
        }
             
    }	

}

implicacio:: ~implicacio(){
  /* Post: esborra automaticament els objectes locals en sortir d'un ambit 
	   de visibilitat */
   
}

//Consultors

vector<char> implicacio::getAllVariables() const{
   //PRE: Cert
   //POST: Devuelve un VECTOR de char con todas las variables EJ.: [a,b,c,d..]

   return all;
}

vector<char> implicacio::getIzq() const{
//PRE: Cert
//POST: Devuelve un VECTOR de char con todas las variables de la izquierda de "->"" EJ.: [a,b,c,d..]

    return izq;
}
vector<char> implicacio::getDer() const{
//PRE: Cert
//POST: Devuelve un VECTOR de char con todas las variables de la derecha "->"" EJ.: [a,b,c,d..]   

    return der;
}

//Modificadores

//Lectura i escriptura

ostream& operator<<(ostream &os, const implicacio &i){
/* Pre: cert  */
/* Post: devuelve por el canal estandar de salida una string con el lado izq y derecho con el formato: ejemplo:"ab -> c" */
    for(char j: i.izq) os<<j<<" ";
    os<<"-> ";
    for(char x: i.der) os<<x<<" ";
    return os;

}
