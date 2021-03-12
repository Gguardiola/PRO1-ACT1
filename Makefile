OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

all: test.exe

test.exe: test.o assignacio.o implicacio.o auxiliar.o
	g++ -o test.exe test.o assignacio.o implicacio.o auxiliar.o

#	Descomenteu les següents línies si voleu executar tots
#	els jocs de proves.

	./test.exe < sample1.inp
	./test.exe < sample2.inp	
	./test.exe < sample3.inp
	./test.exe < sample4.inp 
	./test.exe < sample5.inp	
#	./test.exe < sample1.inp > sample1.cor
#	./test.exe < sample2.inp > sample2.cor
#	./test.exe < sample3.inp > sample3.cor
#	./test.exe < sample4.inp > sample4.cor
#	./test.exe < sample5.inp > sample5.cor
		
test.o: test.cpp assignacio.hpp implicacio.hpp auxiliar.hpp
	g++ -c test.cpp $(OPCIONS)
	
assignacio.o: assignacio.cpp assignacio.hpp
	g++ -c assignacio.cpp $(OPCIONS)

implicacio.o: implicacio.cpp implicacio.hpp assignacio.hpp
	g++ -c implicacio.cpp $(OPCIONS)

auxiliar.o: auxiliar.cpp auxiliar.hpp auxiliar.hpp
	g++ -c auxiliar.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
