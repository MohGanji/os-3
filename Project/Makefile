CC = g++ -std=c++0x
THREAD = -pthread
CFLAG = -c
DEBUG = -g
FLAGS = $(CFLAG) $(THREAD)

ALL.O = utils.o Neuron.o

all: $(ALL.O)
	$(CC) $(THREAD) main.cpp $(ALL.O) -o main.out

utils.o: utils.cpp utils.h
	$(CC) $(FLAGS) utils.cpp

Neuron.o: Neuron.cpp Neuron.h utils.h
	$(CC) $(FLAGS) Neuron.cpp

clean:
	rm *.o *.out
