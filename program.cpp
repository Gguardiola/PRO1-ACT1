#include <iostream>
#include <string>

using namespace std;

#include "assignacio.hpp"
#include "implicacio.hpp"
#include "auxiliar.hpp"

int main()
{
	vector<implicacio> v_imps;
	stack<char> letrasImps;
	string line;
	while (getline (cin,line))
	{
		if (line.size() > 0) {
			v_imps.push_back(implicacio(line));

			for(int i = 0; i<int(line.size());i++){
				if(line[i] !=' ' and line[i] !='-' and line[i] !='>') letrasImps.push(line[i]);
			}			
		}
	}
    vector<char> letrasAss = letrasImplicaciones(letrasImps);
      

	vector<implicacio> base;
	base = calculaBase(v_imps);

	for (implicacio h: base) cout << h << endl;

	return 0;
}


