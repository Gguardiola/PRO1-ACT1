#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "implicacio.hpp"

vector<implicacio> calculaBase(const vector<implicacio>&);
/// PRE:  cert.
/// POST: H és a r (la variable que conté el valor de retorn)
///		  si i només si es compleixen TOTES aquestes condicions conjuntament:
///		  (1) H és al paràmetre
///		  (2) no hi ha cap altra H' al paràmetre tal que H' |= H tal que H != H'.

