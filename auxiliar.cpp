#include "auxiliar.hpp"


vector<implicacio> calculaBase(const vector<implicacio>&){
/// PRE:  cert.
/// POST: H és a r (la variable que conté el valor de retorn)
///		  si i només si es compleixen TOTES aquestes condicions conjuntament:
///		  (1) H és al paràmetre
///		  (2) no hi ha cap altra H' al paràmetre tal que H' |= H tal que H != H'.


}


vector<char> letrasImplicaciones(stack<char> q){
//PRE: cert.
//POST: ordena y elimina las letras repetidas y lo devuelve como vector
    stack<char> aux;
    while(!q.empty()){
        char x = q.top();
        q.pop();
        while(!aux.empty() and aux.top() < x){

            q.push(aux.top());
            aux.pop();

        }
        aux.push(x);
    }
    vector<char> order;

    //vector = stack
    char repeCheck;
    bool firstIt = true;
    while(!aux.empty()){
        if(!firstIt){
            if(repeCheck != aux.top()){
                order.push_back(aux.top());
            }
            repeCheck = aux.top();
            aux.pop();
        }
        else{
            firstIt = false;
            order.push_back(aux.top());
            repeCheck = aux.top();
            aux.pop();            
        }

    }
    return order;
}