#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "sortgallery.h"

using namespace std;
/* 63 for big screen, 43 for 15 inch notebook. */
const int PRINTGAP = 23;

int main(int argc, const char *argv[]) {
    srand (unsigned(time(0)));
#ifdef DEBUG
    int nums[N];
    initArray(nums, N);
#endif
#ifndef DEBUG
    makeBigData (FILENAME, N);
    int nums[N];
    initArray(FILENAME, nums, N);
#endif
    time_t endClock, elapsedTime, startClock;
    int selected = 1;
#ifdef DEBUG 
    printBanner(banners[0], PRINTGAP);
    printArray(nums, N);
    cout << endl;
#endif
    while (1) {
        usage ();
#ifndef CGDB
        cin >> selected;
#endif
        startClock = clock();
#ifdef DEBUG 
        printBanner(banners[0], PRINTGAP);
        printArray(nums, N);
#endif
        switch (selected) {
            case 1:
                bubbleSort (nums, N);
                break;
            case 2:
                insertSort (nums, N);
                break;
            case 3:
                quickSort (nums, N);
                break;
            case 4:
                quickSort2 (nums, N);
                break;
            case 5:
                shellSort (nums, N);
                break;
            case 6:
                heapSort(nums, N);
                break;
            case 7:
                mergeSort(nums, N);
                break;
            case 8:
                bucketSort(nums, N);
                break;
            case 9:
                radixSort(nums, N);
                break;
            case 10:
                sort(nums, nums + N);
                break;
            default:
                return 0;
        }
        endClock = clock();
        printBanner(banners[selected], PRINTGAP + 1);
#ifdef SHOWSORTED
        printArray(nums, N);
#endif
#ifdef DEBUG
        initArray(nums, N);
#endif
#ifndef DEBUG
        initArray(FILENAME, nums, N);
#endif
        elapsedTime = ((endClock - startClock) * 1000000)/ (double)CLOCKS_PER_SEC;
        printBanner(banners[selected], PRINTGAP + 1);
        cout << "Time Elapsed: " << elapsedTime / 1000 << " ms. " << elapsedTime % 1000 
            << " us.  " << "& Restore Array Done.\n" << endl;
    }

    return 0;
}

void initArray (const char *fileName, int *nums, int n) {
    ifstream in (fileName);
    // skip first element
    in >> nums[0];
    for (int i = 0; i < N; ++i) {
        in >> nums[i];
    }
    return;
}

void initArray (int *nums, int N) {
    int dir;
    for (int i = 0; i < N; ++i) {
        dir = rand() % 2 ? 1 : -1;
        nums[i] = dir * (rand() % 100);
    }
    return;
}

void makeBigData (const char *fileName, int n) {
    int val = 0, dir;
    ofstream out (fileName);
    out << N << endl;
    if (out.is_open()) {
        for (int i = 0; i < n; ++i) {
            dir = rand() % 2 ? 1 : -1;
            val = dir * (rand() % MAXVAL);
            out << val << endl;
        }

        out.close();
    }
    return;
}

void usage () {
    cout << "||=>> Select Sort Algorithm @" << endl;
    cout << 
        "[1]: Bubble Sort       "
        "[2]: Insert Sort       "
        "[3]: Quick  Sort     \n"
        "[4]: Quick  Sort(Op)   "
        "[5]: Shell  Sort       "
        "[6]: Heap   Sort     \n"
        "[7]: Merge  Sort       "
        "[8]: Bucket Sort       "
        "[9]: Radix  Sort     \n"
        "[10]:Library Fun       "
        "[*]: Quit Selection  \n";
    cout << "Input Here: ";
    return;
}

inline void printSharp (int cnt = 20) {
    for (int i = 0; i < cnt; ++i) {
        cout << "-";
    }
    return;
}

void printBanner (const char *banner, int nRepeat) {
    printSharp(nRepeat);
    cout << banner;
    printSharp(nRepeat);
    cout << endl;
    return;
}

void printArray (int *nums, int N) {
    int numOfLine = 9;
    for (int i = 0; i < N; ++i) {
        if ((i > 0) && (i % numOfLine == 0))
          cout << endl;
        printf("%6d ", nums[i]);
        //cout << nums[i] << " ";
    }
    cout << endl;
    return;
}

void quickSort (int *nums, int N) {
    qSort(nums, 0, N - 1);
    return;
}

void qSort (int *nums, int left, int right) {
    if (left >= right) return;
    /* this pivot is index. */
    int pivot = partition(nums, left, right);
    qSort(nums, left, pivot - 1);
    qSort(nums, pivot + 1, right);
    return;
}

int partition (int *nums, int left, int right) {
    int sentinel = nums[right];
    int i = left, k = left;
    while (i < right) {
        if (nums[i] <= sentinel) {
            swap(nums[i], nums[k++]);
        }
        ++i;
    }
    swap (nums[k], nums[right]);
    return k;
}

void quickSort2 (int *nums, int N) {
    qSort2(nums, 0, N - 1);
    return;
}

void qSort2 (int *nums, int left, int right) {
    if (left >= right) return;
    /* includeed in pair return */
    auto pivotPair = partition2(nums, left, right);
    qSort2(nums, left, pivotPair.first - 1);
    qSort2(nums, pivotPair.second + 1, right);
    return;
}

pair<int, int> 
partition2 (int *nums, int left, int right) {
    int i = left, j = right - 1, k = left;
    int sentinel = nums[right];
    while (i <= j) {
        if (nums[i] < sentinel) {
            swap(nums[i], nums[k++]);
        } else {
            if (nums[i] == sentinel) {
                swap(nums[i], nums[j--]);
                continue;
            }
        }
        ++i;
    }
    /* optimized with min */
    int dupCnt = right - j;
    int swpCnt = min(dupCnt, j - k + 1);
    for (int index = 0; index < swpCnt; ++index) {
        swap(nums[k + index], nums[right - index]);
    }
    return make_pair(k, k + dupCnt - 1);
}

void insertSort (int *nums, int N) {
    int sentinel = 0, j;
    for (int i = 1; i < N; ++i) {
        sentinel = nums[i];
        for (j = i; j >= 1; --j) {
            if (sentinel < nums[j - 1]) {
                nums[j] = nums[j - 1];
            } else {
                break;
            }
        }
        nums[j] = sentinel;
    }
    return;
}

void shellSort (int *nums, int N) {
    int j, sentinel;
    /* optimize use 2.2 instead of 2. increment is better to be coprime.
    */
    float stepGap = 2.2;
    /* stepGap is float, step is int, so step = N / stepGap still be int.
    */
    for (int step = N / stepGap; step > 0; step /= stepGap) {
        for (int i = step; i < N; ++i) {
            sentinel = nums[i];
            for (j = i; j >= step ; j -= step) {
                if (sentinel < nums[j - step]) {
                    nums[j] = nums[j - step];
                } else {
                    break;
                }
            }
            nums[j] = sentinel;
        }
    }
    return;
}

void bubbleSort (int *nums, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (nums[j] < nums[i]) {
                swap (nums[i], nums[j]);
            }
        }
    }
    return;
}

void heapSort (int *nums, int N) {
    makeHeap(nums, N);
    for (int i = N - 1; i > 0; --i) {
        swap(nums[0], nums[i]);
        percolateDown(nums, 0, i - 1);
    }
    return;
}

void percolateDown (int *nums, int start, int end) {
    int childIndex, sentinel;
    sentinel = nums[start];
    while (start <= end) {
        childIndex = start * 2 + 1;
        if (childIndex > end) break;
        if (childIndex + 1 <= end && 
                    nums[childIndex] < nums[childIndex + 1]) {
            ++childIndex;
        }
        if (sentinel < nums[childIndex]) {
            nums[start] = nums[childIndex];
            start = childIndex;
        } else {
            break;
        }
    }
    nums[start] = sentinel;

    return;
}

void makeHeap (int *nums, int N) {
    //int left = 0; 
    int right = N - 1;
    for (int i = right / 2; i >= 0; --i) {
        percolateDown(nums, i, right);
    }

    return;
}

void bucketSort (int *nums, int N) {
    // already know, val range in [-MAXVAL, MAXVAL]
    int len = 2 * MAXVAL + 1;
    int buckets[len];
    // take care of last parameter of memset, unit of bytes.
    memset(buckets, 0, sizeof(int) * len);
    for (int i = 0; i < N; ++i) {
        ++buckets[nums[i] + MAXVAL];
    }
    int k = 0;
    for (int i = 0; i < len; ++i) {
        if (buckets[i] && k <= N) {
            for (int j = 0; j < buckets[i]; ++j) {
                nums[k++] = i - MAXVAL;
            }
        }
    }
#ifdef DEBUG
    if (k != N) {
        cout << "[k - N = " << k - N << "]" << endl;
        exit(1);
    }
#endif

    return;
}

void radixSort (int *nums, int N) {
    vector<vector<int> > radix(10, vector<int>());
    int tmpNums[N];
    for (int i = 0; i < N; ++i) {
        tmpNums[i] = nums[i] + MAXVAL;
    }
    int loop = 0, maxVal = MAXVAL * 2;
    while (maxVal) {
        ++loop;
        maxVal /= 10;
    }

    int divisor = 1, k = 0;
    while (loop--) {
        for (int i = 0; i < N; ++i) {
            radix[ (tmpNums[i] / divisor) % 10].push_back(tmpNums[i]);
        }
        k = 0;
        for (auto &pVal : radix) {
            for (auto val : pVal) {
                tmpNums[k++] = val;
            }
            vector<int>().swap(pVal);
        }
#ifdef DEBUG
        if (k != N) {
            cout << "[k - N = " << k - N << "]" << endl;
            exit(1);
        }
#endif
        divisor *= 10;
    }
    // restore tmpNums to nums
    for (int i = 0; i < N; ++i) {
        nums[i] = tmpNums[i] - MAXVAL;
    }
    return;
}

void mergeSort(int *nums, int N) {
    int left = 0; 
    int right = N - 1;
    int *pArray = new int[N];
    memset(pArray, 0, sizeof(int) * N);
    mSort(pArray, nums, left, right);
    delete pArray;
    return;
}

void mSort(int *merged, int *nums, int left, int right) {
    if (left >= right)
      return;
    int mid = (right + left) >> 1;
    mSort(merged, nums, left, mid);
    mSort(merged, nums, mid + 1, right);
    orderedMerger(merged, nums, left, right);
    return;
}

void orderedMerger(int *merged, int *nums, int left, int right) {
    int mid = (right + left) >> 1;
    // [left, mid] [mid + 1, right]
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        merged[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
    }
    while (i <= mid) {
        merged[k++] = nums[i++];
    }
    while (j <= right) {
        merged[k++] = nums[j++];
    }
    for (int index = left; index <= right; ++index) {
        nums[index] = merged[index];
    }
    return;
}

