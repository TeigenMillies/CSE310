all	:MAIN

MAIN	:main.o merge_sort.o
	 g++ -Wall -o MAIN main.o merge_sort.o

main.o	:main.cpp merge_sort.h
	 g++ -Wall -c main.cpp

merge_sort.o	:merge_sort.cpp merge_sort.h
	g++ -Wall -c merge_sort.cpp

clean	:
	rm *.o MAIN
