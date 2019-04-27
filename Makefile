transfer.o:transfer.cpp transfer.h
	g++ -pedantic-errors -std=c++11 -g -c transfer.cpp
customer.o:customer.cpp customer.h transfer.cpp transfer.h
	g++ -pedantic-errors -std=c++11 -g -c customer.cpp
password.o:password.cpp password.h
	g++ -pedantic-errors -std=c++11 -g -c password.cpp
interface.o:interface.cpp interface.h customer.cpp customer.h password.cpp password.h
	g++ -pedantic-errors -std=c++11 -g -c interface.cpp
main.o:main.cpp interface.cpp interface.h password.cpp password.h
	g++ -pedantic-errors -std=c++11 -g -c main.cpp
accountingpro:main.o password.o interface.o customer.o transfer.o
	g++ -pedantic-errors -std=c++11 main.o password.o interface.o customer.o transfer.o -g -o accountingpro
clean:
	rm *.txt *.o accountingpro
tar:
	tar -czvf accountingpro.tgz *.cpp *.h *.txt
