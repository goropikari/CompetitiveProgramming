/*https://atcoder.jp/contests/abc274/tasks/abc274_d*/
/*2025年02月02日 16時17分39秒*/
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

bool search(vll& X, vll& cumsum, ll x, bool isx) {
    int ok = 0;
    set<ll> pos = {0};
    rep(i, X.size()) {
        set<ll> tmp;
        for (ll t : pos) {
            ll r = t + X[i];
            if (abs(r - x) <= cumsum[X.size()] - cumsum[i]) {
                tmp.insert(r);
            }

            ll l = t - X[i];
            bool can_reach = abs(l - x) <= cumsum[X.size()] - cumsum[i];
            if (isx) {
                if (i != 0 && can_reach) {
                    tmp.insert(l);
                }
            } else {
                if (can_reach) {
                    tmp.insert(l);
                }
            }
        }
        pos = tmp;

        if (i == X.size() - 1) {
            for (ll t : pos) {
                if (t == x) {
                    ok = 1;
                    break;
                }
            }
        }
    }
    return ok;
}

void solve() {
    ll N, x, y;
    cin >> N >> x >> y;
    vll A(N);
    rep(i, N) cin >> A[i];

    vll X, Y;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0)
            X.push_back(A[i]);
        else
            Y.push_back(A[i]);
    }

    vll cumsumX(X.size() + 1), cumsumY(Y.size() + 1);
    rep(i, X.size()) {
        cumsumX[i + 1] = cumsumX[i] + X[i];
    }
    rep(i, Y.size()) {
        cumsumY[i + 1] = cumsumY[i] + Y[i];
    }

    int okx = search(X, cumsumX, x, true);
    int oky = search(Y, cumsumY, y, false);
    yesno(okx && oky);
}
