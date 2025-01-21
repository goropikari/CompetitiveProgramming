/*https://atcoder.jp/contests/abc285/tasks/abc285_d*/
/*2025年01月21日 09時47分59秒*/
#include <atcoder/all>
using namespace atcoder;
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
    int N;
    cin >> N;
    vector<string> S(N), T(N);
    rep(i, N) cin >> S[i] >> T[i];

    map<string, int> mp;
    rep(i, 2 * N) {
        if (i < N) {
            mp[S[i]] = i;
        } else {
            mp[T[i - N]] = i;
        }
    }

    dsu uf(N * 2);
    rep(i, N) {
        int a = mp[S[i]], b = mp[T[i]];
        if (uf.same(a, b)) {
            yesno(false);
            return;
        }
        uf.merge(a, b);
    }
    yesno(true);
}
