// https://atcoder.jp/contests/abc091/tasks/arc092_a
// Thu 26 Feb 2026 07:42:24 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define pb push_back
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
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

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v) cout << x << '\n';
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

    int N;
    cin >> N;
    using P = pair<int, int>;
    vector<P> red(N), blue(N);
    rep(_, 2) {
        rep(i, N) {
            int a, b;
            cin >> a >> b;
            red[i] = {a, b};
        }
        swap(red, blue);
    }

    mf_graph<int> graph(N * 2 + 2);
    int s = N * 2, f = N * 2 + 1;
    rep(i, N) graph.add_edge(s, i, 1);
    rep(i, N) graph.add_edge(N + i, f, 1);

    rep(i, N) rep(j, N) {
        if (red[i].first < blue[j].first && red[i].second < blue[j].second) {
            graph.add_edge(i, N + j, 1);
        }
    }

    cout << graph.flow(s, f) << endl;
}
