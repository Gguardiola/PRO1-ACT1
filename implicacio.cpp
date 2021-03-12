#include "implicacio.hpp"
#include <iostream>
using namespace std;

implicacio::implicacio(){
    /* Pre: cert */
    /* Post: Si no hay implicación no se puede construir un objeto generico */

}

implicacio::implicacio(const string &i){
    /* Pre: cert */
    /* Post: Si no hay implicación no se puede construir un objeto generico */
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
    // DEBUG
    /*
    for(int line = 0; line<int(izq.size());line++){
        cout<<izq[line]<<endl;
    }	
    for(int line = 0; line<int(der.size());line++){
        cout<<der[line]<<endl;
    }	*/    
    //getAllVariables();
}

implicacio:: ~implicacio(){
  /* Post: esborra automaticament els objectes locals en sortir d'un ambit 
	   de visibilitat */
   
}

//Consultors

vector<char> implicacio::getAllVariables() const{
   //PRE: Cert
   //POST: Devuelve un VECTOR de char con todas las variables EJ.: [a,b,c,d..]
 
   //DEBUG
   /*
    for(int i = 0; i<int(all.size());i++){
        cout<<all[i]<<endl;
    }*/
    
   return all;
}
   
//Lectura i escriptura
///ostream& operator<<(ostream &os, const Implicacio &i){
/* Pre: cert (completem els detalls de format quan coneguem la 
    implementacio) */
/* Post: s'han escrit els atributs del punt p al canal estandard de 
    sortida */

//os<<parte izquierda<<"->"<<parte derecha<<endl;
//return os;

///}
//istream& operator>>(istream &is, const Implicacio &i){
/* Pre: cert */
/* Post: el punt p passa a tenir els atributs llegits del canal  
    estandard d'entrada */



//}
//}