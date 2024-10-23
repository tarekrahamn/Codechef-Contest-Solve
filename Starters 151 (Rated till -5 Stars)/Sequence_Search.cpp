#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Function to find the Kth element in the sequence for given A, B, and K
int find_kth_element(int A, int B, int K) {
    vector<int> sequence = {0, A, B};
    map<tuple<int, int, int>, int> seen;  // Map to store triplet and its index

    // Start generating the sequence and detect the cycle
    for (int i = 3; ; i++) {
        int next = sequence[i - 1] + sequence[i - 2] - sequence[i - 3];
        sequence.push_back(next);

        // Check the current 3-element state
        auto current_state = make_tuple(sequence[i - 2], sequence[i - 1], sequence[i]);
        if (seen.find(current_state) != seen.end()) {
            // Cycle detected; calculate cycle length
            int cycle_start = seen[current_state];
            int cycle_length = i - cycle_start;
            return sequence[cycle_start + (K - 1 - cycle_start) % cycle_length];
        }

        seen[current_state] = i;  // Store the triplet with its index
    }

    // If no cycle is detected (theoretically, we should always detect a cycle)
    return sequence[K - 1];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B, K;
        cin >> A >> B >> K;
        cout << find_kth_element(A, B, K) << endl;
    }

    return 0;
}
