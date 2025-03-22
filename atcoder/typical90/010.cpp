// https://atcoder.jp/contests/typical90/tasks/typical90_j
/*2025年03月20日 15時40分33秒*/
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

    int n;
    cin >> n;
    vll c(n), pt(n);
    rep(i, n) {
        cin >> c[i] >> pt[i];
        c[i]--;
    }

    vvll cumsum(2, vll(n + 1));
    rep(i, n) {
        rep(j, 2) cumsum[j][i + 1] += cumsum[j][i];

        if (c[i] == 0) {
            cumsum[0][i + 1] += pt[i];
        } else {
            cumsum[1][i + 1] += pt[i];
        }
    }

    int q;
    cin >> q;
    rep(_, q) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << cumsum[0][r + 1] - cumsum[0][l] << ' ' << cumsum[1][r + 1] - cumsum[1][l] << endl;
    }
}
