#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted halves and count split inversions
long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    vector<int> temp;
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            // All remaining elements in left half form inversions
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    // Copy back to original array
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }

    return inv_count;
}

// Recursive merge sort + inversion count
long long mergeSortAndCount(vector<int>& arr, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSortAndCount(arr, left, mid);       // left inversions
        inv_count += mergeSortAndCount(arr, mid + 1, right);  // right inversions
        inv_count += mergeAndCount(arr, left, mid, right);    // split inversions
    }
    return inv_count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long result = mergeSortAndCount(arr, 0, n - 1);
    cout << result << endl;
    return 0;
}
