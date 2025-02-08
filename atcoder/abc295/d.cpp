/*https://atcoder.jp/contests/abc295/tasks/abc295_d*/
/*2025年02月05日 22時40分11秒*/
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
    string S;
    cin >> S;

    int n = S.size();
    vvll v(n + 1, vll(10, 0));
    rep(i, n) {
        v[i + 1][S[i] - '0']++;
    }

    rep(k, 10) {
        rep(i, n) {
            v[i + 1][k] += v[i][k];
            v[i + 1][k] %= 2;
        }
    }

    vll cnt(1 << 10, 0);
    rep2(i, 0, n + 1) {
        int x = 0;
        rep(k, 10) {
            x *= 2;
            if (v[i][k])
                x += 1;
        }
        cnt[x]++;
    }

    ll ans = 0;
    rep(i, 1 << 10) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << endl;
}
