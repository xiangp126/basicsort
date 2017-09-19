#include <iostream>
#include <utility>
#include <vector>

using namespace std;
void quickSort(vector<int> &, int);
void printArray(vector<int> &, int);
void qSort(vector<int> &, int, int);
pair<int, int>
partition(vector<int> &, int, int);

int main(int argc, const char *argv[]) {
    vector<int> nums {13, 2, 7, 11, 8, -4, 9, 12, 6, 11};

//    vector<int> nums {-94, -82, -81, -81, -78, -68, -68, -58, -56, -51, -51, 
//    -47, -45, -41, -28, -25, -14, -11, -5, -4, 4, 5, 19, 25, 29, 32, 36, 37, 
//    41, 42, 44, 46, 63, 64, 71, 87, 91, 9, 5, 98, 98};
    const int N = nums.size();
    printArray(nums, N);
    quickSort(nums, N);
    cout << "After Quick Sorted: " << endl;
    printArray(nums, N);

    return 0;
}

void quickSort(vector<int> &nums, int N) {
    return qSort(nums, 0, N - 1);
}

void qSort(vector<int> &nums, int left, int right) {
    if (left < right) {
        auto pivot = partition(nums, left, right);
        qSort(nums, left, pivot.first - 1);
        qSort(nums, pivot.second + 1, right);
    }
    return;
}

pair<int, int>
partition(vector<int> &nums, int left, int right) {
    int i = left, k = left;
    int j = right - 1;
    const int sentinel = nums[right];
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
    int dupCnt = right - j;
    int swpCnt = min(dupCnt, j - k + 1);
    for (int index = 0; index < swpCnt; ++index) {
        swap(nums[k + index], nums[right - index]);
    }
    return make_pair(k, k + dupCnt - 1);
}

void printArray(vector<int> &nums, int N) {
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
    return;
}

