#include "auxiliar.hpp"
#include <math.h>
#include "assignacio.hpp"
vector<implicacio> calculaBase(const vector<implicacio> &teoria){
/// PRE:  cert.
/// POST: H és a r (la variable que conté el valor de retorn)
///		  si i només si es compleixen TOTES aquestes condicions conjuntament:
///		  (1) H és al paràmetre
///		  (2) no hi ha cap altra H' al paràmetre tal que H' |= H tal que H != H'.
    vector <char> totalAssig;
    vector<char> varsImp;
    bool repe = false;

    for(int i = 0;i<int(teoria.size());i++){
        varsImp = teoria[i].getAllVariables();
        for (char h: varsImp){
            for (char x: totalAssig){
                if(h==x) repe = true;
            }            
            if(!repe){
                totalAssig.push_back(h); 

            }else{repe = false;}            
        }
    }
    //DEBUG
    //for (char x: totalAssig)   cout<<x<<endl;
    
    bool detec = true;
    while(detec){
        detec = false;
        for (int i = 0; i < int(totalAssig.size())-1; i++) {
            if(totalAssig[i] > totalAssig[i+1]){
                totalAssig[i] += totalAssig[i+1];
                totalAssig[i+1] = totalAssig[i] - totalAssig[i+1];
                totalAssig[i] -=totalAssig[i+1];
                detec = true;
            }
        }
    }
    //DEBUG
    //for (char x: totalAssig)   cout<<x<<endl;
	Assignacio a(int(totalAssig.size()));

	a.setVariables(totalAssig);

//DEBUG PRUEBAS
	int max = pow(2,(int(totalAssig.size())));
	cout<<max<<endl;
	cout<<"final?"<<a.isFinal()<<endl;
	while(max>0){

		int i = 0;
		while(i<int(totalAssig.size())){
			cout<<a.getVariable(totalAssig[i])<<endl;
			i++;
			
			
		}
		++a;
		cout<<"============"<<endl;
		max--;
		//cout<<"final?"<<a.isFinal()<<endl;
	}
	cout<<"final?"<<a.isFinal()<<endl;
	a.resetAssig();

	cout<<"final?"<<a.isFinal()<<endl;
	max = pow(2,(int(totalAssig.size())));
	while(max>0){

		int i = 0;
		while(i<int(totalAssig.size())){
			cout<<a.getVariable(totalAssig[i])<<endl;
			i++;
			
			
		}
		++a;
		cout<<"============"<<endl;
		max--;
		//cout<<"final?"<<a.isFinal()<<endl;
	}	    
return teoria;

}


/*vector<char> letrasImplicaciones(stack<char> q){
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
}*/