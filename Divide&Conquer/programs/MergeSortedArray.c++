#include <iostream>
#include <sstream>
using namespace std;

int main() {

    int A[1000];
    int totalSize = 0;
    string line;
    getline(cin, line);
    stringstream ss(line);
    while (ss >> A[totalSize]) totalSize++;

    int m;
    cin >> m;  

    int B[1000];
    int sizeB = 0;
    cin.ignore();   
    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> B[sizeB]) sizeB++;

    int n;
    cin >> n;   

    int i = m - 1;      
    int j = n - 1;      
    int k = m + n - 1;   

    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[k--] = A[i--];
        } else {
            A[k--] = B[j--];
        }
    }
    while (j >= 0) {
        A[k--] = B[j--];
    }

    cout << "[";
    for (int idx = 0; idx < m+n; idx++) {
        cout << A[idx];
        if (idx != m+n-1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
