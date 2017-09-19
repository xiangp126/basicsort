#include <iostream>
#include <vector>
using namespace std;

void showArray(vector<int> &, int);
void mergeSort(vector<int> &, int);
void mSort(int *, vector<int> &, int, int);
void merge(int *, vector<int> &, int, int);

int main() {
    vector<int> nums {13, 2, 7, 12, 8, -4, 9, 12, 6, 3};
    const int N = nums.size();
    cout << "Original Array: " << endl;
    showArray(nums, N);
    mergeSort(nums, N);
    cout << "Merge Sorted: " << endl;
    showArray(nums, N);
    
    return 0;
}

void mergeSort(vector<int> &nums, int N) {
    int *pArray = new int[N];
    mSort(pArray, nums, 0, N - 1);
    delete pArray;
    return;
}

void mSort(int *mArray, vector<int> &nums, int left, int right) {
    if (left >= right) return;
    //int mid = left >> 1 + right >> 1;
    int mid = (left & right) + ((left ^ right) >> 1);
    mSort(mArray, nums, left, mid);
    mSort(mArray, nums, mid + 1, right);
    return merge(mArray, nums, left, right);
}

void merge(int *mArray, vector<int> &nums, int left, int right) {
    int mid = (left & right) + ((left ^ right) >> 1);
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        mArray[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
    }
    while (i <= mid) {
        mArray[k++] = nums[i++];
    }
    while (j <= right) {
        mArray[k++] = nums[j++];
    }
    for (int cnt = left; cnt < k; ++cnt) {
        nums[cnt] = mArray[cnt];
    }
    return;
}

void showArray(vector<int> &nums, int N) {
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

