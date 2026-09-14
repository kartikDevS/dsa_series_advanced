#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canEatAll(vector<int>& piles, int h, int k) {
    long long hours = 0;
    for (int bananas : piles) {
        hours += (bananas + k - 1) / k; // ceil division
    }
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canEatAll(piles, h, mid)) {
            ans = mid;
            high = mid - 1; // try smaller speed
        } else {
            low = mid + 1;  // need faster speed
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; i++) cin >> piles[i];
    int h;
    cin >> h;

    cout << minEatingSpeed(piles, h) << endl;
    return 0;
}
