CC =g++
CFLAGS = -Wall -Werror -pedantic --std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = FibLFSR.h 

all: PhotoMagic style
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS)  -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -c $<
PhotoMagic: PhotoMagic.o FibLFSR.o
	$(CC) $(CFLAGS)  -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)
clean:
	rm -f *.o 
	rm -f PhotoMagic
style:
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h FibLFSR.cpp
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h FibLFSR.h
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h PhotoMagic.cpp