/*https://atcoder.jp/contests/abc221/tasks/abc221_c*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
#include <cstddef>
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

ll cal(string x) {
    int n = x.size();
    ll ans = 0;
    rep2(i, 1, n) {
        string ls = x.substr(0, i), rs = x.substr(i);
        if (ls[0] == '0' || rs[0] == '0')
            continue;
        ll l = stoi(ls), r = stoi(rs);
        chmax(ans, l * r);
    }
    return ans;
}

void solve() {
    string N;
    cin >> N;
    sort(all(N));

    ll ans = 0;

    do {
        chmax(ans, cal(N));
    } while (next_permutation(all(N)));

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
