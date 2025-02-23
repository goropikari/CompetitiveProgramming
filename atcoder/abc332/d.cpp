/*https://atcoder.jp/contests/abc332/tasks/abc332_d*/
/*2025年02月22日 14時08分27秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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
    int h, w;
    cin >> h >> w;
    vvint A(h, vint(w)), B(h, vint(w));
    rep(i, h) rep(j, w) cin >> A[i][j];
    rep(i, h) rep(j, w) cin >> B[i][j];

    vint permr(h), permc(w);
    iota(all(permr), 0);
    iota(all(permc), 0);

    ll ans = INF;
    do {
        // iota(all(permr), 0);
        do {
            int ok = 1;
            rep(i, h) rep(j, w) {
                if (A[permr[i]][permc[j]] != B[i][j])
                    ok = 0;
            }
            if (ok) {
                vint r = permr, c = permc;
                ll cnt = 0;
                for (auto v : {r, c}) {
                    int n = v.size();
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n - 1 - i; j++) {
                            if (v[j] > v[j + 1]) {
                                cnt++;
                                swap(v[j], v[j + 1]);
                            }
                        }
                    }
                }
                chmin(ans, cnt);
            }
        } while (next_permutation(all(permr)));
    } while (next_permutation(all(permc)));

    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}
