// https://atcoder.jp/contests/abc377/tasks/abc377_g
// Sun 28 Dec 2025 12:21:07 AM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

struct Node {
    ll fin, len;
    map<char, Node*> to;

    Node() {
        fin = 0;
        len = INF;
        to = map<char, Node*>();
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    auto root = new Node();

    auto add = [&](string s) -> void {
        auto now = root;
        rep(i, (int)s.size()) {
            char c = s[i];
            if (now->to.count(c)) {
                now = now->to[c];
            } else {
                auto tmp = new Node();
                now->to[c] = tmp;
                now = tmp;
            }
            chmin(now->len, (ll)s.size());
            if (i == (int)s.size() - 1) {
                now->fin = 1;
            }
        }
    };

    auto dfs = [&](auto dfs, Node* now, string& s, ll depth, ll ans) -> ll {
        if (depth == (ll)s.size()) return ans;
        char c = s[depth];
        if (!now->to.count(c)) return ans;
        now = now->to[c];
        if (now->fin) {
            chmin(ans, (ll)s.size() - (depth + 1));
        }
        chmin(ans, (now->len - depth - 1) + ((ll)s.size() - depth - 1));
        chmin(ans, dfs(dfs, now, s, depth + 1, ans));
        return ans;
    };

    for (auto s : S) {
        ll ans = dfs(dfs, root, s, 0, s.size());
        cout << ans << endl;
        add(s);
    }
}
