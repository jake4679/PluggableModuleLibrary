CPP_FLAGS = \
	-g

all: main.o Registrant.o
	g++ -o example main.o Registrant.o

main.o: main.cpp Registry.h Registrant.h
	g++ -c $(CPP_FLAGS) main.cpp

Registrant.o: Registrant.cpp Registrant.h Registry.h
	g++ -c $(CPP_FLAGS) Registrant.cpp

clean:
	rm -f *.o example

run:
	@./example

debug:
	gdb example
