STD=-std=c++11
CXX=g++ $(STD)
DEBUG=-g -O3
CXXFLAGS=-Wall $(DEBUG)
LFLAGS=-Wall $(DEBUG)
DEPS=pref_attach.o

pref_attach: $(DEPS)
	$(CXX) $(LFLAGS) $^ -o $@

%.o: %.c
	$(CXX) $(CXXFLAGS)

clean:
	rm *.o 
