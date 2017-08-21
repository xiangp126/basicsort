#ifndef MYSORT_H_
#define MYSORT_H_

#include <utility>

using namespace std;
/* unless using gdb, always comment out this. */
//#define CGDB

/* uncomment it to debug. */
#define DEBUG 
#define SHOWSORTED
const int MAXVAL = 10000;
const char *FILENAME = "data.txt";

#ifdef DEBUG 
const int N = 15; // Small Case for Debug
#endif
#ifndef DEBUG 
const int N = 1000000; // normal 
#endif

const char *banners[] = {
    " Original Array ",         // [0] 
    " Bubble Sort ",            // [1]  
    " Insert Sort ",            // [2]  
    " Quick  Sort ",            // [3] 
    " Opti  Quick ",            // [4] 
    " Shell  Sort ",            // [5]  
    " Heap   Sort ",            // [6] 
    " Merge  Sort ",            // [7] 
    " Bucket Sort ",            // [8] 
    " Radix  Sort ",            // [9] 
    " Library Fun "             // [10] 
};

void printSharp(int);
void printBanner(const char *, int);
void makeBigData(const char *, int);
void printArray(int *, int);
void initArray(const char *, int *, int);
void initArray(int *, int);
void usage();

/* swap kind sort algorighms */
void bubbleSort(int *, int);
void quickSort(int *, int);
void qSort(int *, int, int);
int  partition(int *, int, int);
void quickSort2(int *, int);
void qSort2(int *, int, int);
pair<int, int> partition2(int *, int, int);

/* insert kind sort algorithm */
void insertSort(int*, int);
void shellSort(int *, int);

/* select kind sort algorithms */
void heapSort(int *, int);
void makeHeap(int *, int);
void percolateDown(int *, int, int);

/* merge kind sort algorithms */
void mergeSort(int *, int);
void mSort(int *, int *, int, int);
void orderedMerger(int *, int *, int, int);

/* linear like sort algorithms */
void bucketSort(int *, int); // need number range
void radixSort(int *, int);  // need number range

class myPair {
    int first;
    int second;
    myPair(int x, int y) {
        first = x;
        second = y;
    }
};

#endif
