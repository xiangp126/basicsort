#include <iostream>
#include <vector>
using namespace std;

void insertSort(vector<int> &, int);
void showArray(vector<int> &, int);

int main() {
    vector<int> nums {13, 2, 7, 11, -8, 4, 9, 12, 6, 11};
    const int N = nums.size();
    cout << "Original Array: " << endl;
    showArray(nums, N);
    insertSort(nums, N);
    cout << "Insert Sorted: " << endl;
    showArray(nums, N);
    
    return 0;
}

void showArray(vector<int> &nums, int N) {
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

void insertSort(vector<int> &nums, int N) {
    int sentinel = 0, j = 0;
    for (int i = 1; i < N; ++i) {
        sentinel = nums[i];
        for (j = i; j >= 1; j -= 1) {
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
