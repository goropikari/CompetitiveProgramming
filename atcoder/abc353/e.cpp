// https://atcoder.jp/contests/abc353/tasks/abc353_e
// 2025年05月21日 02時08分25秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
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

struct Trie {
    vector<map<char, int>> to;
    vll cnt;

    Trie()
        : to(1), cnt(1) {};

    int add(string s) {
        int v = 0;
        for (char c : s) {
            if (to[v].count(c) == 0) {
                int u = to.size();
                to.push_back(map<char, int>());
                to[v][c] = u;
                cnt.push_back(0);
            }
            v = to[v][c];
            cnt[v]++;
        }
        return v;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    Trie trie;

    for (string s : S)
        trie.add(s);

    ll ans = 0;
    for (ll x : trie.cnt) {
        ans += x * (x - 1) / 2;
    }
    cout << ans << endl;
}
