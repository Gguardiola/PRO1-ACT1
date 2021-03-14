#ifndef IMPLICACIO_HPP
#define IMPLICACIO_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class implicacio{
// Tipus de modul: dades
// Descripcio del tipus: Guarda conjunciones logicas de variables (implicaciones) ejemplo: ab -> c.
//Esta clase trata literalmente la implicacion de la parte izquierda de -> respecto a la parte derecha

    
private:
   vector<char> izq; //Guarda la parte izquierda de la implicación
   vector<char> der; //Guarda la parte derecha de la implicación
   vector<char> all; //Guarda todas las variables para poder juntar el tamaño de todas las implicaciones y crear las asignaciones. (linea 15-27 auxiliar.cpp)
    
public:
        
    //Constructors 
    implicacio();
    /* Pre: cert */
    /* Post: Si no hay implicación no se puede construir un objeto generico */
    implicacio(const string& i);
    /// PRE: cert
    /// POST: Partiendo del parametro implicito i, divida las variables del lado izq y lado der teniendo ">" como referencia de cada lado
    // también guarda todas en un vector all para tratarlas en el getter getAllVariables()

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

   friend ostream& operator<<(ostream &os, const implicacio &i);
   /* Pre: cert  */
   /* Post: devuelve por el canal estandar de salida una string con el lado izq y derecho con el formato: ejemplo:"ab -> c" */
   

};
#endif