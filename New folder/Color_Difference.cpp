#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAX_N = 300000;

void solve() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        vector<int> colors(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> colors[i];
        }
        
        vector<int> left(M), right(M);
        for (int i = 0; i < M; ++i) {
            cin >> left[i] >> right[i];
        }
        
        vector<int> distinct_left(M);
        vector<int> distinct_right(M);
    
        vector<int> count(MAX_N + 1, 0);
        int distinct_count = 0;
        
        // Calculate distinct colors in each range
        for (int i = 0; i < M; ++i) {
            int L = left[i];
            int R = right[i];
            
            // Reset count array and distinct count
            fill(count.begin(), count.end(), 0);
            distinct_count = 0;
            
            // Calculate distinct colors in range [L, R]
            for (int j = L; j <= R; ++j) {
                if (count[colors[j]] == 0) {
                    distinct_count++;
                }
                count[colors[j]]++;
            }
            
            distinct_left[i] = distinct_count;
        }
        
        // Calculate distinct_right using the same approach
        for (int i = 0; i < M; ++i) {
            int L = left[i];
            int R = right[i];
            
            // Reset count array and distinct count
            fill(count.begin(), count.end(), 0);
            distinct_count = 0;
            
            // Calculate distinct colors in range [L, R]
            for (int j = R; j >= L; --j) {
                if (count[colors[j]] == 0) {
                    distinct_count++;
                }
                count[colors[j]]++;
            }
            
            distinct_right[i] = distinct_count;
        }
        
        // Calculate D_i values
        vector<int64_t> D(M);
        for (int i = 0; i < M; ++i) {
            int64_t Di = 0;
            for (int j = 0; j < M; ++j) {
                if (i != j) {
                    Di += abs(distinct_left[i] - distinct_right[j]);
                }
            }
            D[i] = Di;
        }
        
        // Output D values for this test case
        for (int i = 0; i < M; ++i) {
            cout << D[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
