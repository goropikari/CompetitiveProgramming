/*https://atcoder.jp/contests/abc293/tasks/abc293_d*/
/*2025年02月02日 23時58分02秒*/
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
    ll N, M;
    cin >> N >> M;

    dsu uf(2 * N);
    rep(i, N) uf.merge(i, i + N);

    ll cnt = 0;
    rep(i, M) {
        int a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a--, c--;

        int u = a, v = c;
        if (b == 'B')
            u += N;
        if (d == 'B')
            v += N;

        if (uf.same(u, v)) {
            cnt++;
        }
        uf.merge(u, v);
    }

    set<int> s;
    rep(i, N) {
        s.insert(uf.leader(i));
    }
    cout << cnt << ' ' << s.size() - cnt << endl;
}
