CC = g++ -std=c++11

all : greedyChange recursiveChange dynamicChange

greedyChange : greedy.o
	./greedy 11 4 1 5 10 25
	./greedy 21 4 1 5 10 25
	./greedy 31 4 1 5 10 25
	./greedy 51 4 1 5 10 25
	./greedy 73 4 1 5 10 25
	./greedy 83 4 1 5 10 25
	./greedy 91 4 1 5 10 25
	./greedy 99 4 1 5 10 25
	./greedy 63 5 1 5 10 21 25

recursiveChange : recursive.o
	./recursive 11 4 1 5 10 25
	./recursive 21 4 1 5 10 25
	./recursive 31 4 1 5 10 25
	./recursive 51 4 1 5 10 25

dynamicChange : dynamic.o
	./dynamic 11 4 1 5 10 25
	./dynamic 21 4 1 5 10 25
	./dynamic 31 4 1 5 10 25
	./dynamic 51 4 1 5 10 25
	./dynamic 73 4 1 5 10 25
	./dynamic 83 4 1 5 10 25
	./dynamic 91 4 1 5 10 25
	./dynamic 99 4 1 5 10 25
	./dynamic 63 5 1 5 10 21 25

greedy.o : greedyChange.cpp
	$(CC) greedyChange.cpp -o greedy

recursive.o : recursiveChange.cpp
	$(CC) recursiveChange.cpp -o recursive

dynamic.o : dynamicChange.cpp
	$(CC) dynamicChange.cpp -o dynamic

clean :
	rm -f *.o