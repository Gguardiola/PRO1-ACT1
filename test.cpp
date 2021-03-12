#include <iostream>
#include <string>

using namespace std;

#include "assignacio.hpp"
#include "implicacio.hpp"
#include "auxiliar.hpp"

int main()
{
	vector<implicacio> teoria;

	string linia;
	while (getline (cin,linia))
	{
		if (linia.size() > 0) teoria.push_back(implicacio(linia));
		
	}
	
	vector<implicacio> base;
	base = calculaBase(teoria);

	//for (implicacio h: base) cout << h << endl;

	//return 0;
}


