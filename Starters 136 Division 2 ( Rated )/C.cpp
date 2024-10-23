#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void largestLexicographically(int t) {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    
    // Input array A and sort it in non-increasing order
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<int>());
    
    // Construct array B
    B[0] = A[0];
    for (int i = 1; i < n; ++i) {
        B[i] = max(0, B[i - 1] & A[i]);
    }
    
    // Output array B
    for (int i = 0; i < n; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        largestLexicographically(t);
    }
    return 0;
}
