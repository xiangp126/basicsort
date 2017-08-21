
CC = g++
CFLAGXX = -Wall -std=c++11 -g3
OBJS = mysort.o

all: sortgallery

main:${OBJS}
	${CC} -o $@ ${OBJS}	
mysort.o: sortgallery.cpp sortgallery.h
	${CC} -o $@ ${CFLAGXX} -c $< 

.PHONY: 
clean:
	@echo "Removing binary and object files..."
	-rm -f *.o sortgallery core data.txt
	
