/*
 * author:QuantumQuotient
 * created: 2024-07-10 20:38:31
 */
#pragma GCC optimize("O3,unroll-loops")


#pragma GCC diagnostic ignored "-Wunused-variable" // Ignore unused variable warning
#pragma GCC diagnostic ignored "-Wunknown-pragmas" // Ignore unknown pragmas warning
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <functional> // for less  
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;


#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>// find_by_order, order_of_key
#define int long long int
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz size()
#define YES cout<<"YES"<<endl;
#define NO  cout<<"NO"<<endl;
#define ONLINE_JUDGE
#define nl              "\n"
#define dbug(...)  __f (#__VA_ARGS__, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define des(x) (x).rbegin(), (x).rend()
#define fora(i,a,b)    for(int i=a;i<b;i++)
#define fora2(i,a,b)   for(int i=a;i<=b;i++)
#define rof(i, a, b)   for (int i=a;i>=b;i--)
#define rof2(i, a, b)  for (int i=a;i>b;i--)
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*----------------------------------------------------------------------------------------------------------------------------------*/
template <typename T> istream &operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template <typename T> ostream &operator<<(ostream &ostream, const vector<T> &c){for (auto &it : c) cout << it << " "; return ostream;}
template<typename T1, typename T2>istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T1, typename T2> ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int gcd(int a, int b) {if (b > a) {return gcd(b, a);}if (b == 0) {return a;}return gcd(b, a % b);}
int expo(int a, int b, int mod) {int res = 1;while (b > 0) {if (b & 1) {res = (res * a) % mod;}a = (a * a) % mod;b = b >> 1;}return res;}
void extendgcd(int a, int b, int *v) {if (b == 0) {v[0] = 1;v[1] = 0;v[2] = a;return;}extendgcd(b, a % b, v);int x = v[1];v[1] = v[0] - v[1] * (a / b);v[0] = x;return;}//pass an arry of size1 3
int mminv(int a, int b) {int arr[3];extendgcd(a, b, arr);return arr[0];} //for non prime b  

/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
const int MAX_A = 1e9;

int lagbe(int target, const vector<int>& a) {
     int currentOR = 0;
    int elementsUsed = 0;
    
    for (const auto& val : a) {
        if (val <= target) {
            currentOR |= val;
            elementsUsed++;
        }
    }
    
    if (currentOR == target) {
        return a.sz - elementsUsed;
    } else {
        return a.sz;
    }
}
   

void Broken_Heart(int t){
    int  n,k,m;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    // auto valid = lagbe();
    // int orr = 0;
    // for (int num : a) {
    //     orr |= num;
    // }
    // if (valid.count(orr)) {
    //         cout << 0 << nl;
    // } else {
         int minn = n;
    //         for (int value : valid) {
    //             int current_or = 0, count = 0;
    //             for (int num : a) {
    //                 if ((current_or | num) <= value) {
    //                     current_or |= num;
    //                 } else {
    //                     count++;
    //                 }
    //             }
    //             if (current_or >= value) {
    //                 minn = min(minn, count);
    //             }
    //         }
    //         cout << minn << nl;
    fora(i,0,32){
        int ind = (1 << i) - 1;
        minn = min(minn, lagbe(ind, a));
    }
    cout << minn << nl;
    
}
int32_t main() {
    fastio();
    auto start1 = high_resolution_clock::now();
    int t=1;
    cin >>t ; 
    while(t--){
        //cout << "Case " << t++ << ": ";
        Broken_Heart(t);
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifdef ONLINEJUDGE
        cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
}