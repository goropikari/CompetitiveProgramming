// https://atcoder.jp/contests/abc446/tasks/abc446_f
// Sat 21 Feb 2026 10:32:04 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
// const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) { a = min(a, b); }
template <typename T>
void chmax(T& a, T b) { a = max(a, b); }

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

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vvint to(N), from(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        u--, v--;
        to[u].push_back(v);
        from[v].push_back(u);
    }

    vint mark(N), reachable(N);
    int mark_cnt = 0, del_cnt = 0;
    queue<int> que;
    auto add = [&](int v) -> void {
        if (mark[v]) return;
        mark[v] = 1;
        mark_cnt++;
        que.push(v);
    };

    rep(k, N) {
        if (reachable[k]) del_cnt--;
        if (reachable[k] || k == 0) add(k);
        while (que.size()) {
            ll x = que.front();
            que.pop();
            for (int nx : to[x]) {
                if (nx <= k)
                    add(nx);
                else if (!reachable[nx]) {
                    reachable[nx] = 1;
                    del_cnt++;
                }
            }
        }

        if (k + 1 == mark_cnt) {
            cout << del_cnt << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
