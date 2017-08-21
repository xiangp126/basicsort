#include <iostream>
#include <vector>
#include "string.h"
using namespace std;

void radixSort(vector<int> &, int);
void showArray(vector<int> &, int);
const int MAXVAL = 20;

int main() {
    vector<int> nums {13, 2, 7, 11, -8, 4, 9, 12, 6, 11};
    const int N = nums.size();
    cout << "Original Array: " << endl;
    showArray(nums, N);
    radixSort(nums, N);
    cout << "Bucket Sorted: " << endl;
    showArray(nums, N);
    
    return 0;
}

void radixSort(vector<int> &nums, int N) {
    vector<vector<int> > radix(10, vector<int>());
    vector<int> tNums(nums);
    int level = 0, maxVal = MAXVAL * 2;
    while (maxVal) {
        ++level;
        maxVal /= 10;
    }
    
    for (auto &val : tNums) {
        val += MAXVAL;
    }
    
    int divisor = 1, residue, tmpVal;
    int k = 0;
    while (level--) {
        for (auto val : tNums) {
            residue = (val / divisor) % 10;
            radix[residue].push_back(val);
        }
        
        k = 0;
        for (auto &pVal : radix) {
            for (auto val : pVal) {
               tNums[k++] = val; 
            }
            vector<int>().swap(pVal);
        }
        divisor *= 10;
    }
    for (auto &val : tNums) {
        val -= MAXVAL;
    }
    nums.swap(tNums);
        
    return;
}

void showArray(vector<int> &nums, int N) {
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

