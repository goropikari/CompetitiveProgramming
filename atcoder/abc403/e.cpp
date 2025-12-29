// https://atcoder.jp/contests/abc403/tasks/abc403_e
// Mon 29 Dec 2025 01:33:11 AM JST
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
    ll ver;
    map<char, Node*> to;

    Node() {
        ver = INF;
        to = map<char, Node*>();
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    auto root = new Node();
    vll ans(Q + 1);

    auto add = [&](ll ver, string s) -> void {
        int n = s.size();
        auto now = root;
        rep(i, n) {
            char c = s[i];
            auto nx = now->to[c];
            if (nx == nullptr) {
                nx = new Node();
            }

            now->to[c] = nx;
            now = nx;
        }

        chmin(now->ver, ver);
    };

    auto memo = [&](ll ver, string s) -> void {
        int n = s.size();
        auto now = root;
        ans[ver]++;
        ll tmp_ver = INF;
        rep(i, n) {
            char c = s[i];
            auto nx = now->to[c];
            if (nx == nullptr) {
                break;
            }
            if (nx->ver != INF && nx->ver < ver) {
                ans[ver]--;
                return;
            }
            if (nx->ver != INF && nx->ver > ver) {
                chmin(tmp_ver, nx->ver);
            }
            now = nx;
        }
        if (tmp_ver != INF) {
            ans[tmp_ver]--;
        }
    };

    vector<pair<ll, string>> qs;
    rep(i, Q) {
        ll t;
        string s;
        cin >> t >> s;
        qs.push_back({t, s});

        if (t == 1) add(i, s);
    }

    rep(i, Q) {
        auto [t, s] = qs[i];
        if (t == 1) continue;
        memo(i, s);
    }

    rep2(i, 1, Q + 1) ans[i] += ans[i - 1];
    rep(i, Q) cout << ans[i] << endl;
}
