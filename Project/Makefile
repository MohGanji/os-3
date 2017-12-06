SHELL := /bin/bash

CC = g++ -std=c++0x
THREAD = -pthread
CFLAG = -c
DEBUG = -g
FLAGS = $(CFLAG) $(THREAD)

ALL.H = $(shell cut -d'.' -f1 <(ls *.h)  | sed 's/$$/.h/')
ALL.O = $(shell cut -d'.' -f1 <(ls *.cpp) | sed 's/$$/.o/')

all: $(ALL.O)
	$(CC) $(THREAD) $(ALL.O) -o main.out

main.o: main.cpp $(ALL.H)
	$(CC) $(FLAGS) main.cpp

utils.o: utils.cpp utils.h NeuronData.h
	$(CC) $(FLAGS) utils.cpp

Neuron.o: Neuron.cpp Neuron.h utils.h NeuronData.h
	$(CC) $(FLAGS) Neuron.cpp

InputNeuron.o: Neuron.h Neuron.cpp Neuron.o InputNeuron.cpp InputNeuron.h utils.h NeuronData.h
	$(CC) $(FLAGS) InputNeuron.cpp

OutputNeuron.o: Neuron.h Neuron.cpp InputNeuron.cpp InputNeuron.h OutputNeuron.cpp OutputNeuron.h utils.h NeuronData.h
	$(CC) $(FLAGS) OutputNeuron.cpp

clean:
	rm *.o *.out

debug: $(ALL.O)
	$(CC) $(DEBUG) $(THREAD) $(ALL.O) -o main.out