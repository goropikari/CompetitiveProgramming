// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_aj
/*2025年01月12日 01時42分48秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
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
    ll N, Q;
    cin >> N >> Q;
    vll snow(N + 1);
    rep(i, Q) {
        ll l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        snow[l] += x;
        snow[r + 1] -= x;
    }
    rep2(i, 1, N) {
        snow[i] += snow[i - 1];
    }

    string ans = "";
    rep(i, N - 1) {
        char c;
        if (snow[i] > snow[i + 1])
            c = '>';
        if (snow[i] == snow[i + 1])
            c = '=';
        if (snow[i] < snow[i + 1])
            c = '<';
        ans.push_back(c);
    }
    cout << ans << endl;
}
