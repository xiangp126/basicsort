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
    // right included
    int sentinel = nums[right];
    int i = left, k = left, r = right - 1;
    while (i <= r) {
        if (nums[i] <= sentinel) {
            swap(nums[i], nums[k++]);
        } else if (nums[i] == sentinel) {
            swap(nums[i], nums[r--]);
            continue;
        }
        ++i;
    }
    int dupCnt = right - r;
    int cnt = min(dupCnt, r - k + 1);
    for (int m = 0; m < cnt; ++m) {
        swap(nums[right - m], nums[k + m]);
    }
    return make_pair(k, k + dupCnt - 1);
}

