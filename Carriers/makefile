CXX = g++
CXXFLAGS = -Wall -g

proj4: MailHouse.o Ups.o FedEx.o Carrier.o Package.o Letter.o Mail.o driver.cpp
	$(CXX) $(CXXFLAGS) MailHouse.o Ups.o FedEx.o Carrier.o Package.o Letter.o Mail.o driver.cpp -o proj4

MailHouse.o: MailHouse.cpp MailHouse.h Ups.o FedEx.o Carrier.o Package.o Letter.o
	$(CXX) $(CXXFLAGS) -c MailHouse.cpp

Ups.o: Ups.cpp Ups.h Carrier.o
	$(CXX) $(CXXFLAGS) -c Ups.cpp

FedEx.o: FedEx.cpp FedEx.h Carrier.o
	$(CXX) $(CXXFLAGS) -c FedEx.cpp

Carrier.o: Carrier.cpp Carrier.h Mail.o
	$(CXX) $(CXXFLAGS) -c Carrier.cpp

Package.o: Package.cpp Package.h Mail.o
	$(CXX) $(CXXFLAGS) -c Package.cpp

Letter.o: Letter.cpp Letter.h Mail.o
	$(CXX) $(CXXFLAGS) -c Letter.cpp

Mail.o: Mail.h Mail.cpp
	$(CXX) $(CXXFLAGS) -c Mail.cpp

clean:
	rm *~

run:
	./proj4

run1:
	./proj4 proj4_t1.txt

val1:
	valgrind ./proj4 proj4_t1.txt

run2:
	./proj4 proj4_t2.txt

val2:
	valgrind ./proj4 proj4_t2.txt

run3:
	./proj4 proj4_t3.txt

val3:
	valgrind ./proj4 proj4_t3.txt

run4:
	./proj4 proj4_t4.txt

val4:
	valgrind ./proj4 proj4_t4.txt