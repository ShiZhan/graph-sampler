CC = g++

CXXFLAGS = --std=c++0x -O3

all:
	make reservoir ses sns pies pies-min pies-inv

reservoir: reservoir.cpp
	$(CC) reservoir.cpp $(CXXFLAGS) -o reservoir

ses:      ses.cpp
	$(CC) ses.cpp $(CXXFLAGS) -o ses

sns:      sns.cpp
	$(CC) sns.cpp $(CXXFLAGS) -o sns

pies:     pies.cpp
	$(CC) pies.cpp $(CXXFLAGS) -o pies

pies-min: pies-min.cpp
	$(CC) pies-min.cpp $(CXXFLAGS) -o pies-min

pies-inv: pies-inv.cpp
	$(CC) pies-inv.cpp $(CXXFLAGS) -o pies-inv

test:
	make all
	echo "sns sampling:"
	./sns      -s 256 | wc -l
	echo "ses sampling:"
	./ses      -s 256 | wc -l
	echo "pies sampling:"
	./pies     -s 256 | wc -l
	echo "pies-min sampling:"
	./pies-min -s 256 | wc -l
	echo "pies-inv sampling:"
	./pies-inv -s 256 | wc -l

clean:
	rm *.exe *.o reservoir sns ses pies pies-min pies-inv

