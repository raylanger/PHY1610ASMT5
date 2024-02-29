CXX=g++
CXXFLAGS=-O3 -march=native

all: ASMT5

ASMT5: main.o init.o iterate.o output.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

init.o: init.cpp init.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

iterate.o: iterate.cpp iterate.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

output.o: output.cpp output.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

main.o: main.cpp init.h iterate.h output.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) init.o main.o

.PHONY: all clean
