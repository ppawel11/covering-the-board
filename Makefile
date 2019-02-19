test: test.o plansza.o figury.o
	g++ test.o plansza.o figury.o -o test
	rm *o
test.o: test.cpp
	g++ -c test.cpp
plansza.o: plansza.cpp
	g++ -c plansza.cpp
figury.o: figury.cpp
	g++ -c figury.cpp
