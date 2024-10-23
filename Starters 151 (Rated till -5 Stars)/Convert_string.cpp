#include <iostream>
#include <string>
using namespace std;

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int N; // Length of the string
        cin >> N;
        string S;
        cin >> S;
        
        // Count the number of '1's and '0's
        int count_ones = 0, count_zeros = 0;
        for (char ch : S) {
            if (ch == '1') count_ones++;
            else count_zeros++;
        }
        
        // The string is already uniform if all are '1's or all are '0's
        if (count_ones == N || count_zeros == N) {
            // If the string is already uniform, any k >= 1 will work
            cout << N << endl;
        } else {
            // We want to flip to make all '1's or all '0's
            // The minimum k to flip either all 0's to 1's or all 1's to 0's
            int min_flips = min(count_ones, count_zeros);
            // We can make the string uniform by flipping either all the 1's or all the 0's
            cout << min_flips << endl;
        }
    }

    return 0;
}
