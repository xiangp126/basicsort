
CC = g++
CFLAGXX = -Wall -std=c++11 -g3
OBJS = mysort.o

all: main
main:${OBJS}
	${CC} -o $@ ${OBJS}	
mysort.o: sortgallery.cpp sortgallery.h
	${CC} -o $@ ${CFLAGXX} -c $< 
.PHONY: 
clean:
	@echo "Removing binary and object files..."
	-rm -f *.o main core data.txt
	
