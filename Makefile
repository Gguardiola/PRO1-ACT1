OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

all: program.exe

program.exe: program.o assignacio.o implicacio.o auxiliar.o
	g++ -o program.exe program.o assignacio.o implicacio.o auxiliar.o

#	Descomenteu les següents línies si voleu executar tots
#	els jocs de proves.

	./program.exe < sample1.inp
	./program.exe < sample2.inp	
	./program.exe < sample3.inp
	./program.exe < sample4.inp 
	./program.exe < sample5.inp	
#	./program.exe < sample1.inp > sample1.cor
#	./program.exe < sample2.inp > sample2.cor
#	./program.exe < sample3.inp > sample3.cor
#	./program.exe < sample4.inp > sample4.cor
#	./program.exe < sample5.inp > sample5.cor
		
program.o: program.cpp assignacio.hpp implicacio.hpp auxiliar.hpp
	g++ -c program.cpp $(OPCIONS)
	
assignacio.o: assignacio.cpp assignacio.hpp
	g++ -c assignacio.cpp $(OPCIONS)

implicacio.o: implicacio.cpp implicacio.hpp assignacio.hpp
	g++ -c implicacio.cpp $(OPCIONS)

auxiliar.o: auxiliar.cpp auxiliar.hpp auxiliar.hpp
	g++ -c auxiliar.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
