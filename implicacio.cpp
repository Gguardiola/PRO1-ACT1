#include "implicacio.hpp"
#include <iostream>
using namespace std;

Implicacio::implicacio(){
    /* Pre: cert */
    /* Post: Si no hay implicación no se puede construir un objeto generico */

}

Implicacio::implicacio(const string& i){
    /* Pre: cert */
    /* Post: Si no hay implicación no se puede construir un objeto generico */

}

Implicacio:: ~Implicacio(){
  /* Post: esborra automaticament els objectes locals en sortir d'un ambit 
	   de visibilitat */
   
}
//Lectura i escriptura
ostream& operator<<(ostream &os, const Implicacio &i){
/* Pre: cert (completem els detalls de format quan coneguem la 
    implementacio) */
/* Post: s'han escrit els atributs del punt p al canal estandard de 
    sortida */

//os<<parte izquierda<<"->"<<parte derecha<<endl;
//return os;

}
istream& operator>>(istream &is, const Implicacio &i){
/* Pre: cert */
/* Post: el punt p passa a tenir els atributs llegits del canal  
    estandard d'entrada */



}
}