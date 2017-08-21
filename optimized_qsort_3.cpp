#include <iostream>
#include <utility>
#include <vector>

using namespace std;
void printArray(vector<int> &, int);
void quickSort(vector<int> &, int);
void qSort(vector<int> &, int, int);
pair<int, int>
partition(vector<int> &nums, int left, int right);

int main(int argc, const char *argv[]) {
    vector<int> nums {13, 2, 7, 11, 8, -4, 9, 12, 6, 11, -1, -4, 5};

    const int N = nums.size();
    printArray(nums, N);
    quickSort(nums, N);
    cout << "After Quick Sorted: " << endl;
    printArray(nums, N);

    return 0;
}

void printArray(vector<int> &nums, int N) {
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
    return;
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
    int i = left, r = right - 1;
    int k = left;
    int sentinel = nums[right];
    while (i <= r) {
        if (nums[i] < sentinel) {
            swap(nums[i], nums[k++]);
        } else if (nums[i] == sentinel) {
            swap(nums[i], nums[r--]);
            continue;
        }
        ++i;
    }
    // tackle when done.
    int dupNum = right - r;
    int swpTimes = min(dupNum, r - k + 1);
    for (int i = 0; i < swpTimes; ++i) {
        swap(nums[k + i], nums[right - i]);
    }
    return make_pair(k, k + dupNum - 1);
}
