#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> possible_contender(int T, vector<vector<int>>& test_cases) {
    vector<string> results;
    
    for (int t = 0; t < T; ++t) {
        vector<int>& A = test_cases[t];
        int N = A.size();
        
        vector<int> possible(N, 0);
        
        // Two heaps: max_heap (left) and min_heap (right)
        priority_queue<int> max_heap; // max heap (default)
        priority_queue<int, vector<int>, greater<int>> min_heap; // min heap
        
        // Process each element in A
        for (int i = 0; i < N; ++i) {
            // Insert current element into max_heap
            max_heap.push(A[i]);
            
            // Balance heaps
            if (max_heap.size() > min_heap.size() + 1) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            
            // Check if A[i] can become the sole remaining element
            if (max_heap.size() == min_heap.size()) {
                possible[i] = 1;
            }
        }
        
        // Convert possible vector to string and store in results
        string result;
        for (int num : possible) {
            result += to_string(num);
        }
        results.push_back(result);
    }
    
    return results;
}

int main() {
    int T;
    cin >> T;
    
    vector<vector<int>> test_cases(T);
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        test_cases[t].resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> test_cases[t][i];
        }
    }
    
    // Calling function
    vector<string> results = possible_contender(T, test_cases);
    
    // Printing results
    for (string result : results) {
        cout << result << endl;
    }
    
    return 0;
}
