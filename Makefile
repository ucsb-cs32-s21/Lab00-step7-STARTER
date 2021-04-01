CXX=g++

CXXFLAGS= -O3 -Wall
#CXXFLAGS= -O3 -std=c++14 -stdlib=libc++

BINARIES=dataProj testDemog1 

all: ${BINARIES}

tests: ${BINARIES}
	./testDemog1

dataProj: parse.o main.o
	${CXX} $^ -o $@

testDemog1: testDemog1.o tddFuncs.o parse.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o 
