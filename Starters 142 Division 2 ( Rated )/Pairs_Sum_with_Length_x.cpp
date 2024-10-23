#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int countDigits(int64_t num) {
    if (num == 0) return 1;
    return floor(log10(num) + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        int N, X;
        cin >> N >> X;
        
        vector<int64_t> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        // To store the count of valid pairs
        int64_t totalCount = 0;
        
        // Frequency map to keep track of digits counts
        unordered_map<int, int> digitCount;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < N; ++j) {
                int64_t sum = A[i] + A[j];
                if (countDigits(sum) == X) {
                    ++totalCount;
                }
            }
        }
        
        cout << totalCount << "\n";
    }
    
    return 0;
}
