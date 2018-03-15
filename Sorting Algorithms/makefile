OBJS = insertion.o quicksort.o heapsort.o
CC = g++ -std=c++11
DEBUG = -g


all : insertion.o quicksort.o heapsort.o
	./insertion 10kRandom.txt
	./quicksort 10kRandom.txt
	./heapsort 10kRandom.txt
	./insertion 10kSorted.txt
	./quicksort 10kSorted.txt
	./heapsort 10kSorted.txt
	./insertion 10kIdentical.txt
	./quicksort 10kIdentical.txt
	./heapsort 10kIdentical.txt
	./insertion 10kReverse.txt
	./quicksort 10kReverse.txt
	./heapsort 10kReverse.txt

	./insertion 20kRandom.txt
	./quicksort 20kRandom.txt
	./heapsort 20kRandom.txt
	./insertion 20kSorted.txt
	./quicksort 20kSorted.txt
	./heapsort 20kSorted.txt
	./insertion 20kIdentical.txt
	./quicksort 20kIdentical.txt
	./heapsort 20kIdentical.txt
	./insertion 20kReverse.txt
	./quicksort 20kReverse.txt
	./heapsort 20kReverse.txt

	./insertion 40kRandom.txt
	./quicksort 40kRandom.txt
	./heapsort 40kRandom.txt
	./insertion 40kSorted.txt
	./quicksort 40kSorted.txt
	./heapsort 40kSorted.txt
	./insertion 40kIdentical.txt
	./quicksort 40kIdentical.txt
	./heapsort 40kIdentical.txt
	./insertion 40kReverse.txt
	./quicksort 40kReverse.txt
	./heapsort 40kReverse.txt

	./insertion 80kRandom.txt
	./quicksort 80kRandom.txt
	./heapsort 80kRandom.txt
	./insertion 80kSorted.txt
	./quicksort 80kSorted.txt
	./heapsort 80kSorted.txt
	./insertion 80kIdentical.txt
	./quicksort 80kIdentical.txt
	./heapsort 80kIdentical.txt
	./insertion 80kReverse.txt
	./quicksort 80kReverse.txt
	./heapsort 80kReverse.txt

tenthousand : insertion.o quicksort.o heapsort.o
	./insertion 10kRandom.txt
	./quicksort 10kRandom.txt
	./heapsort 10kRandom.txt
	./insertion 10kSorted.txt
	./quicksort 10kSorted.txt
	./heapsort 10kSorted.txt
	./insertion 10kIdentical.txt
	./quicksort 10kIdentical.txt
	./heapsort 10kIdentical.txt
	./insertion 10kReverse.txt
	./quicksort 10kReverse.txt
	./heapsort 10kReverse.txt

twentythousand : insertion.o quicksort.o heapsort.o
	./insertion 20kRandom.txt
	./quicksort 20kRandom.txt
	./heapsort 20kRandom.txt
	./insertion 20kSorted.txt
	./quicksort 20kSorted.txt
	./heapsort 20kSorted.txt
	./insertion 20kIdentical.txt
	./quicksort 20kIdentical.txt
	./heapsort 20kIdentical.txt
	./insertion 20kReverse.txt
	./quicksort 20kReverse.txt
	./heapsort 20kReverse.txt

fortythousand : insertion.o quicksort.o heapsort.o
	./insertion 40kRandom.txt
	./quicksort 40kRandom.txt
	./heapsort 40kRandom.txt
	./insertion 40kSorted.txt
	./quicksort 40kSorted.txt
	./heapsort 40kSorted.txt
	./insertion 40kIdentical.txt
	./quicksort 40kIdentical.txt
	./heapsort 40kIdentical.txt
	./insertion 40kReverse.txt
	./quicksort 40kReverse.txt
	./heapsort 40kReverse.txt

eightythousand : insertion.o quicksort.o heapsort.o
	./insertion 80kRandom.txt
	./quicksort 80kRandom.txt
	./heapsort 80kRandom.txt
	./insertion 80kSorted.txt
	./quicksort 80kSorted.txt
	./heapsort 80kSorted.txt
	./insertion 80kIdentical.txt
	./quicksort 80kIdentical.txt
	./heapsort 80kIdentical.txt
	./insertion 80kReverse.txt
	./quicksort 80kReverse.txt
	./heapsort 80kReverse.txt

insertion : insertion.o
	./insertion 10kRandom.txt
	./insertion 10kSorted.txt
	./insertion 10kIdentical.txt
	./insertion 10kReverse.txt

	./insertion 20kRandom.txt
	./insertion 20kSorted.txt
	./insertion 20kIdentical.txt
	./insertion 20kReverse.txt

	./insertion 40kRandom.txt
	./insertion 40kSorted.txt
	./insertion 40kIdentical.txt
	./insertion 40kReverse.txt

	./insertion 80kRandom.txt
	./insertion 80kSorted.txt
	./insertion 80kIdentical.txt
	./insertion 80kReverse.txt

quicksort : quicksort.o
	./quicksort 10kRandom.txt
	./quicksort 10kSorted.txt
	./quicksort 10kIdentical.txt
	./quicksort 10kReverse.txt

	./quicksort 20kRandom.txt
	./quicksort 20kSorted.txt
	./quicksort 20kIdentical.txt
	./quicksort 20kReverse.txt

	./quicksort 40kRandom.txt
	./quicksort 40kSorted.txtt
	./quicksort 40kIdentical.txt
	./quicksort 40kReverse.txtt

	./quicksort 80kRandom.txt
	./quicksort 80kSorted.txt
	./quicksort 80kIdentical.txt
	./quicksort 80kReverse.txt

heapsort : heapsort.o
	./heapsort 10kRandom.txt
	./heapsort 10kSorted.txt
	./heapsort 10kIdentical.txt
	./heapsort 10kReverse.txt

	./heapsort 20kRandom.txt
	./heapsort 20kSorted.txt
	./heapsort 20kIdentical.txt
	./heapsort 20kReverse.txt

	./heapsort 40kRandom.txt
	./heapsort 40kSorted.txt
	./heapsort 40kIdentical.txt
	./heapsort 40kReverse.txt

	./heapsort 80kRandom.txt
	./heapsort 80kSorted.txt
	./heapsort 80kIdentical.txt
	./heapsort 80kReverse.txt


insertion.o : insertion.h insertion.cpp	insertionmain.cpp
	$(CC) insertion.cpp insertionmain.cpp -o insertion

quicksort.o : quicksortmain.cpp
	$(CC) quicksortmain.cpp -o quicksort

heapsort.o : heapsortmain.cpp
	$(CC) heapsortmain.cpp -o heapsort

clean :
	rm -f *.o
