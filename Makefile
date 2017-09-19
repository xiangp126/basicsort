
CC = g++
CFLAGXX = -Wall -std=c++11 -g3
OBJS = mysort.o

all: sortgallery

mysort.o: sortgallery.cpp sortgallery.h
	${CC} -o $@ ${CFLAGXX} -c $< 

sortgallery:${OBJS}
	${CC} -o $@ ${OBJS}	

.PHONY: 
clean:
	@echo "Removing binary and object files..."
	-rm -f *.o sortgallery core data.txt
