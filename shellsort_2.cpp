#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int> &, int);
void showArray(vector<int> &, int);

int main() {
    vector<int> nums {13, 2, 7, 11, -8, 4, 9, 12, 6, 11};
    const int N = nums.size();
    cout << "Original Array: " << endl;
    showArray(nums, N);
    shellSort(nums, N);
    cout << "Shell Sorted: " << endl;
    showArray(nums, N);
    
    return 0;
}

void showArray(vector<int> &nums, int N) {
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

void shellSort(vector<int> &nums, int N) {
    int sentinel = 0;
    int j, stepGap = 2.2;
    for (int step = N / stepGap; step > 0; step /= stepGap) {
        for (int i = step; i < N; ++i) {
            sentinel = nums[i];
            for (j = i; j >= step; j -= step) {
                if (sentinel < nums[j - step] ) {
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
