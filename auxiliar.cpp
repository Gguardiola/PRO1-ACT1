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

    int maxSize = int(totalAssig.size());
	Assignacio a(maxSize);
	a.setVariables(totalAssig);

    vector<vector<bool>> opImp;
    for(int i = 0;i<int(teoria.size());i++){
        vector<bool> column;
       
        while(!a.isFinal()){
            vector<char> izq = teoria[i].getIzq();
            vector<char> der = teoria[i].getDer();
            
            vector<bool> boolIzq,boolDer;
            bool opIzq,opDer;

            bool current;
            for(int i = 0; i<int(izq.size());i++){
                current = a.getVariable(izq[i]);
                current = not current;
                boolIzq.push_back(current);
            } 
            bool first = true;
            for(int i = 0; i<int(boolIzq.size());i++){
                if(first) {
                    opIzq = boolIzq[i];
                    first = false;
                }
                else{
                    opIzq = opIzq || boolIzq[i];
                }                        
            }   

            for(int i = 0; i<int(der.size());i++){
                boolDer.push_back(a.getVariable(der[i]));
            } 

            first = true;
            for(int i = 0; i<int(boolDer.size());i++){
                if(first) {
                    opDer = boolDer[i];
                    first = false;
                }
                else{
                    opDer = opDer || boolDer[i];
                }                      
            }                         
            bool row = opIzq || opDer;
            column.push_back(row);
            ++a;
        }

        opImp.push_back(column);
              
        a.resetAssig();
    }

    vector<implicacio> base;
    bool detecModel;
    int models;
    for(int i = 0;i<int(teoria.size());i++){
        models = 0;
        for(int x = 0;x<int(teoria.size());x++){
            detecModel = true;
            if(x!=i){
                int j = 0;
                while(j<int(opImp[i].size()) and detecModel){
                    if(opImp[x][j] == true and opImp[i][j] == false){
                        detecModel = false;
                        models++;
                    }
                    j++;
                }
            }      
        }

        if(models == int(teoria.size())-1){
            base.push_back(teoria[i]);
        }                
    }

return base;

}

