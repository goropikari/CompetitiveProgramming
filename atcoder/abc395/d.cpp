/*https://atcoder.jp/contests/abc395/tasks/abc395_d*/
/*2025年03月16日 00時07分03秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) {
    a = min(a, b);
}
template <typename T>
void chmax(T& a, T b) {
    a = max(a, b);
}

template <typename T>
void print(vector<T> v) {
    int n = v.size();
    rep(i, n) {
        if (i == 0)
            cout << v[i];
        else
            cout << ' ' << v[i];
    }
    cout << endl;
}

void yesno(bool x) {
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vint p2b(n), b2n(n), n2b(n);
    iota(all(p2b), 0);
    iota(all(b2n), 0);
    iota(all(n2b), 0);

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;

            p2b[a] = n2b[b];
        } else if (t == 2) {
            int a, b;
            cin >> a >> b;
            a--, b--;

            swap(n2b[a], n2b[b]);
            swap(b2n[n2b[a]], b2n[n2b[b]]);
        } else {
            int a;
            cin >> a;
            a--;
            cout << b2n[p2b[a]] + 1 << endl;
        }
    }
}
