test: FacadeApp.cpp MIS_Department.o Electrical_Department.o Facilities_Department.o
	g++ -o test FacadeApp.cpp MIS_Department.o Electrical_Department.o Facilities_Department.o

MIS_Department.o: MIS_Department.cpp
	g++ -c MIS_Department.cpp

Electrical_Department.o: Electrical_Department.cpp
	g++ -c Electrical_Department.cpp

Facilities_Department.o: Facilities_Department.cpp
	g++ -c Facilities_Department.cpp

clean:
	rm *.o test
