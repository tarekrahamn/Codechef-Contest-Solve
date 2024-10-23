#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    
    int query(int l, int r) const {
        return query(0, 0, n - 1, l, r);
    }

private:
    vector<int> tree;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] & tree[2 * node + 2];
        }
    }

    int query(int node, int start, int end, int l, int r) const {
        if (r < start || l > end) return INT_MAX; // All bits set (large number)
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int left_query = query(2 * node + 1, start, mid, l, r);
        int right_query = query(2 * node + 2, mid + 1, end, l, r);
        return left_query & right_query;
    }
};

long long getMaxBeauty(const SegmentTree& st, int N, int K, int X) {
    int initialBeauty = st.query(0, N - 1);

    int beautyAfterXOR = initialBeauty;
    for (int i = 0; i < N; ++i) {
        beautyAfterXOR &= (~(X)) ^ X;
    }

    if (K == 1) {
        return max(initialBeauty, beautyAfterXOR);
    } else {
        int maxBeauty = max(initialBeauty, beautyAfterXOR);
        return maxBeauty;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    
    while (T--) {
        int N, Q;
        cin >> N >> Q;
        
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        SegmentTree st(A);

        while (Q--) {
            int K, X;
            cin >> K >> X;
            cout << getMaxBeauty(st, N, K, X) << endl;
        }
    }
    
    return 0;
}
