#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &, int);
void qSort(vector<int> &, int, int);
int partition(vector<int> &, int, int);
void showArray(vector<int> &, int N);

int main() {
    vector<int> nums {-17, 79, -69, 51, -50, -40, 64, 38, -77, 83};
    const int N = nums.size();
    cout << "Original Array: " << endl;
    showArray(nums, N);
    quickSort(nums, N);
    cout << "Quick Sorted: " << endl;
    showArray(nums, N);
    
    return 0;
}

void quickSort(vector<int> &nums, int N) {
    qSort(nums, 0, N - 1);
} 

void qSort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int pivot = partition(nums, left, right);
    qSort(nums, left, pivot - 1);
    qSort(nums, pivot + 1, right);
}

int partition(vector<int> &nums, int left, int right) {
    int sentinel = nums[right];
    int i = 0, k = 0;
    while (i < right) {
        if (nums[i] <= sentinel) {
            swap(nums[i], nums[k++]);
        }
        ++i;
    }
    swap(nums[k], nums[right]);
    return k;
}

void showArray(vector<int> &nums, int N) {
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

