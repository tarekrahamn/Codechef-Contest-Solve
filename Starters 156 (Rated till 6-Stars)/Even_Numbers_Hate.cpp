#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

int main() {
    int T;
    cin >> T; // Number of test cases
    while (T--) {
        int N;
        cin >> N; // Size of the array
        vector<int> A(N);

        for (int i = 0; i < N; ++i) {
            cin >> A[i]; // Input the elements of the array
        }

        // Create the suffix sum array
        vector<int> suffix_sum(N);
        suffix_sum[N - 1] = A[N - 1]; // Last element of suffix sum is the last element of A

        for (int i = N - 2; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i + 1] + A[i]; // Calculate suffix sums
        }

        // Count odd and even numbers in the suffix sum array
        int odd_count = 0, even_count = 0;
        for (int i = 0; i < N; ++i) {
            if (suffix_sum[i] % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
        }

        // Output the results
        cout << "Odd Count: " << odd_count << ", Even Count: " << even_count << endl;
    }
    return 0;
}
