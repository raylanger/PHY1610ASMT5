CXX=g++
CXXFLAGS=-O3 -march=native

all: ASMT5

ASMT5: main.o init.o iterate.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

init.o: init.cpp init.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

iterate.o: iterate.cpp iterate.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

main.o: main.cpp init.h iterate.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) init.o main.o

.PHONY: all clean
