#include <iostream>
#include <vector>
#include "string.h"
using namespace std;

void percoDown(vector<int> &, int, int);
void makeHeap(vector<int> &, int);
void heapSort(vector<int> &, int);
void showArray(vector<int> &, int);
const int MAXVAL = 20;

int main() {
    vector<int> nums {13, 2, 7, 11, -8, 4, 9, 12, 6, 11};
    const int N = nums.size();
    cout << "Original Array: " << endl;
    showArray(nums, N);
    heapSort(nums, N);
    cout << "Heap Sorted: " << endl;
    showArray(nums, N);
    
    return 0;
}

void heapSort(vector<int> &nums, int N) {
    makeHeap(nums, N);
    for (int i = N - 1; i > 0; --i) {
        swap(nums[0], nums[i]);
        percoDown(nums, 0, i - 1);
    }
    return;
}

// big-head heap
void percoDown(vector<int> &nums, int start, int end) {
    int childIndex, sentinel;
    sentinel = nums[start];
    while (start <= end) {
        childIndex = start * 2 + 1;
        if (childIndex > end) break;
        if (childIndex + 1 <= end && 
                nums[childIndex] < nums[childIndex + 1])
            ++childIndex;
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

void makeHeap(vector<int> &nums, int N) {
    for (int i = N / 2; i >= 0; --i) {
        percoDown(nums, i, N - 1);
    }
    return;
}

void showArray(vector<int> &nums, int N) {
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

