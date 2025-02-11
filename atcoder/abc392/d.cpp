/*https://atcoder.jp/contests/abc392/tasks/abc392_d*/
/*2025年02月09日 14時13分54秒*/
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
    ll n;
    cin >> n;
    vector<map<ll, ll>> A(n);
    vll K(n);
    rep(i, n) {
        int k;
        cin >> k;
        K[i] = k;
        rep(j, k) {
            int a;
            cin >> a;
            A[i][a]++;
        }
    }

    double ans = 0.0;
    rep(i, n) {
        rep2(j, i + 1, n) {
            ll tmp = 0;
            for (auto it = A[j].begin(); it != A[j].end(); it++) {
                tmp += A[i][it->first] * it->second;
            }
            chmax(ans, (double)tmp / K[i] / K[j]);
        }
    }
    printf("%.9lf\n", ans);
}
