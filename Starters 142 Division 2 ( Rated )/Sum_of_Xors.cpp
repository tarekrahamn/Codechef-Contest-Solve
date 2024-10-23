#include <iostream>
#include <vector>
using namespace std;

long long calculate_uptil(long long N, long long M) {
    // Function to calculate the sum of F(i) for i from 1 to N*M
    long long sum = 0;
    for (long long i = 1; i <= N * M; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N, M;
        cin >> N >> M;

        // Calculate result for each test case
        long long result = calculate_uptil(N, M);

        // Output the result for the current test case
        cout << result << endl;
    }

    return 0;
}
