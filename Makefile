CXX=g++
CXXFLAGS=-O3 -march=native

all: ASMT5

ASMT5: main.o init.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

init.o: init.cpp init.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

main.o: main.cpp init.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) init.o main.o

.PHONY: all clean
