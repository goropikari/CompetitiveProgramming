#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,k,n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
// using P = pair<ll,ll>;

const ll INF = (ll)1e18;
// const int INF = (int)1e9+7;
template<typename T>
void chmin(T &a, T b) { a = min(a, b); }
template<typename T>
void chmax(T &a, T b) { a = max(a, b); }

void solve() {
    int ns[] = {100, 1000, 10000, 100000, 1000000, 10000000};
    cout << "multiset" << endl;
    cout << "size\telapsed time (sec)" << endl;
    for (int n : ns) {
        multiset<int> ms;
        clock_t start = clock();
        rep(i,n) ms.insert(i);
        clock_t end = clock();
        cout << n << "\t" << (double)(end - start) / CLOCKS_PER_SEC << endl;
    }

    cout << endl;
    cout << "vector" << endl;
    cout << "size\telapsed time (sec)" << endl;
    for (int n : ns) {
        vector<int> v(n);
        clock_t start = clock();
        rep(i,n) v[i] = i;
        sort(all(v));
        clock_t end = clock();
        cout << n << "\t" << (double)(end - start) / CLOCKS_PER_SEC << endl;
    }
}

int main() {
    solve();
    return 0;
}
