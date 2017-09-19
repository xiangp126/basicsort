#include <iostream>
#include <vector>
#include "string.h"
using namespace std;

void bucketSort(vector<int> &, int);
void showArray(vector<int> &, int);
const int MAXVAL = 20;

int main() {
    vector<int> nums {13, 2, 7, 11, -8, 4, 9, 12, 6, 11};
    const int N = nums.size();
    cout << "Original Array: " << endl;
    showArray(nums, N);
    bucketSort(nums, N);
    cout << "Bucket Sorted: " << endl;
    showArray(nums, N);
    
    return 0;
}

void bucketSort(vector<int> &nums, int N) {
    for (auto &val : nums) {
        val += MAXVAL;
    }
    int len = MAXVAL * 2 + 1;
    int buckets[len];
    memset(buckets, 0, sizeof(int) * len);
    for (auto val : nums) {
        ++buckets[val];
    }
    int k = 0;
    for (int i = 0; i < len; ++i) {
        while (buckets[i]--) {
            nums[k++] = i - MAXVAL;
        }
    }
    return;
}

void showArray(vector<int> &nums, int N) {
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

