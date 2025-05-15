// https://atcoder.jp/contests/arc170/tasks/arc170_b
// 2025年05月16日 00時36分19秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vint A(N);
    rep(i, N) cin >> A[i];

    auto is_seq = [&](int l, int r) -> bool {
        bool ok = false;
        r++;
        rep2(i, l, r) {
            rep2(j, i + 1, r) {
                rep2(k, j + 1, r) {
                    if (A[j] - A[i] == A[k] - A[j])
                        ok = true;
                }
            }
        }
        return ok;
    };

    ll ans = N * (N + 1) / 2;
    rep(l, N) {
        rep2(r, l, N) {
            if (is_seq(l, r)) {
                break;
            } else {
                ans--;
            }
        }
    }
    cout << ans << endl;
}

