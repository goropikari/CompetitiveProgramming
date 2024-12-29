/*https://atcoder.jp/contests/abc334/tasks/abc334_c*/
/*2024年12月26日 21時50分27秒*/
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
    int N, K;
    cin >> N >> K;
    vll A(N, 2);
    vll cand;
    rep(i, K) {
        int a;
        cin >> a;
        A[a - 1]--;
        cand.push_back(a - 1);
    }

    ll ans = 0;
    int l = -1;
    if (K % 2 == 0 || K == 1) {
        for (ll x : cand) {
            if (l == -1) {
                l = x;
            } else {
                ans += x - l;
                l = -1;
            }
        }
        cout << ans << endl;
        return;
    }

    vll fd, bd;
    for (int i = 0; i + 1 < cand.size(); i += 2) {
        fd.push_back(abs(cand[i + 1] - cand[i]));
    }
    for (int i = 1; i + 1 < cand.size(); i += 2) {
        bd.push_back(abs(cand[i + 1] - cand[i]));
    }

    int nf = fd.size();
    int nb = bd.size();
    vll cf(nf + 1, 0), cb(nb + 1, 0);
    rep2(i, 1, nf + 1) cf[i] = cf[i - 1] + fd[i - 1];
    rep2(i, 1, nb + 1) cb[i] = cb[i - 1] + bd[i - 1];

    ans = INF;
    rep(i, cand.size()) {
        if (i % 2 == 0) {
            ll tmp = cf[i / 2] - cf[0] + cb[nb] - cb[i / 2];
            chmin(ans, tmp);
        } else {
            ll tmp = cf[i / 2] - cf[0] + cb[nb] - cb[(i + 1) / 2];
            if (i - 1 >= 0 && i + 1 < cand.size())
                tmp += abs(cand[i - 1] - cand[i + 1]);
        }
    }
    cout << ans << endl;
}
