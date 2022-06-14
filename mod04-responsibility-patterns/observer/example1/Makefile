test: ObserverApp.cpp Subject.o DummyProduct.o Shop.o 
	g++ -o test ObserverApp.cpp Subject.o DummyProduct.o Shop.o

Shop.o: Shop.cpp
	g++ -c Shop.cpp

Subject.o: Subject.cpp Subject.h
	g++ -c Subject.cpp

DummyProduct.o: DummyProduct.cpp DummyProduct.h
	g++ -c DummyProduct.cpp

clean:
	rm *.o test
