/*https://atcoder.jp/contests/abc398/tasks/abc398_f*/
/*2025年03月22日 21時27分15秒*/
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
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

    string s;
    cin >> s;

    string rs = s;
    reverse(all(rs));

    mint base = 29;
    vector<mint> power;

    int n = s.size();
    rep(i, n + 1) {
        power.push_back(base.pow(i));
    }

    vector<mint> v, rv;
    for (char c : s) {
        v.push_back(c - 'A');
    }
    rv = v;
    reverse(all(rv));

    vector<mint> l(n), r(n);

    r[0] = rv[0];
    l[0] = rv[0];
    rep2(i, 1, n) {
        r[i] = r[i - 1] * base + rv[i];
        l[i] = power[i] * rv[i] + l[i - 1];
    }
    reverse(all(l));

    ll common = 0;
    rep(i, n) {
        if (l[n - i - 1].val() == r[i].val()) {
            common = i + 1;
        }
    }
    // cout << common << endl;
    cout << s;
    string b = rs.substr(common, n - common);
    cout << b << endl;
}
