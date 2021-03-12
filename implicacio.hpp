#ifndef IMPLICACIO_HPP
#define IMPLICACIO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class implicacio{
// Tipus de modul: dades
// Descripcio del tipus: Guarda conjunciones logicas de variables (implicaciones) ejemplo: ab -> c.
//Esta clase trata literalmente la implicacion de la parte izquierda de -> respecto a la parte derecha

    
private:
   vector<char> izq;
   vector<char> der;
   vector<char> all;
    
public:
        
    //Constructors 
    implicacio();
    /* Pre: cert */
    /* Post: Si no hay implicación no se puede construir un objeto generico */
    implicacio(const string& i);
    /// PRE: cert
    /// POST: el parametre implıcit conte els atributs de l’string
    /// que t´e la sintaxi e1 e2 e3 ... e_n -> d1 d2 d3 ... d_m
    /// on e_i i d_i s´on car`acters entre ’a’... ’z’ i
    /// n >= 1 i m >= 1.


    ~implicacio();
    /* Post: esborra automaticament els objectes locals en sortir d'un ambit 
	   de visibilitat */
   
   
    //Modificadors

    //Consultors
   vector<char> getAllVariables() const;
   //PRE: Cert
   //POST: Devuelve un VECTOR de char con todas las variables EJ.: [a,b,c,d..]
   vector<char> getIzq() const;
   //PRE: Cert
   //POST: Devuelve un VECTOR de char con todas las variables de la izquierda de "->"" EJ.: [a,b,c,d..]
   vector<char> getDer() const;
   //PRE: Cert
   //POST: Devuelve un VECTOR de char con todas las variables de la derecha "->"" EJ.: [a,b,c,d..]   
    //Lectura i escriptura
   friend ostream& operator<<(ostream &os, const implicacio &i);
    /* Pre: cert (completem els detalls de format quan coneguem la 
       implementacio) */
    /* Post: s'han escrit els atributs del punt p al canal estandard de 
       sortida */
  // friend istream& operator>>(istream &is, const implicacio &i);
    /* Pre: cert */
    /* Post: el punt p passa a tenir els atributs llegits del canal  
       estandard d'entrada */
   

};
#endif