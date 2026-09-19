#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Use hashing to track presence of unique elements
    unordered_set<int> unique_elements;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        unique_elements.insert(val);
    }

    int k;
    cin >> k;

    // Move unique elements to a vector
    vector<int> v(unique_elements.begin(), unique_elements.end());

    // Sort ascending to easily pick the least k unique elements
    sort(v.begin(), v.end());

    // Take the first k (smallest k values)
    vector<int> result(v.begin(), v.begin() + k);

    // Display in reverse sorted order (largest to smallest)
    sort(result.begin(), result.end(), greater<int>());

    cout << "[";
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
        if (i != (int)result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}