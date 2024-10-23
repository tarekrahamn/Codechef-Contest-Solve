#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int min_sum_after_operations(const vector<int>& Q) {
    int N = Q.size();
    vector<int> dp(N, 0);
    dp[0] = Q[0];
    
    for (int i = 1; i < N; ++i) {
        dp[i] = Q[i];
        for (int j = 0; j < i; ++j) {
            if (Q[j] < Q[i]) {
                dp[i] = min(dp[i], dp[j] + Q[i]);
            }
        }
    }
    
    return dp[N - 1];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        vector<int> P(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
        }
        
        // Calculate number of permutations
        int permutation_count = 1;
        for (int num : P) {
            if (num == 0) {
                permutation_count *= 1;
            }
        }
        
        int total_sum = 0;
        
        // Generate permutations and compute sum of f(Q)
        do {
            vector<int> Q(N);
            int current_perm = 1;
            
            for (int i = 0; i < N; ++i) {
                if (P[i] == 0) {
                    Q[i] = current_perm++;
                } else {
                    Q[i] = P[i];
                }
            }
            
            total_sum += min_sum_after_operations(Q);
            total_sum %= MOD;
        } while (next_permutation(P.begin(), P.end()));
        
        cout << total_sum << endl;
    }
    
    return 0;
}
