#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> B(N),a(N);

        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        bool possible = true;

        for (int i = 0; i < N-1; ++i) {
            a[i] == (B[i]+B[i + 1 ])%2;
            if (a[i]!=B[i]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
