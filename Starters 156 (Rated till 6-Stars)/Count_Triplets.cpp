#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;  
    while (T--) {
        int N;
        cin >> N;  
        vector<int> A(N + 1);  
        for (int i = 1; i <= N; ++i) {
            cin >> A[i]; 
        }

        long long count_triplets = 0;  

        for (int i = 1; i <= N; ++i) {
            for (int k = 1; k <= N; ++k) {
                int abs_diff_A = abs(A[i] - A[k]);
               
                for (int j = 1; j <= N; ++j) {
                    int abs_diff_index = abs(i - j) + abs(j - k);
                    if (abs_diff_A == abs_diff_index) {
                        count_triplets++;  
                    }
                }
            }
        }

        cout << count_triplets << endl;  
    }
    return 0;
}


