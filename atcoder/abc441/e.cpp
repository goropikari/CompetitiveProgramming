// https://atcoder.jp/contests/abc441/tasks/abc441_e
// Sat 17 Jan 2026 09:50:34 PM JST
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

    ll N;
    string S;
    cin >> N >> S;

    vll cm(N);
    if (S[0] == 'A') cm[0] = 1;
    if (S[0] == 'B') cm[0] = -1;
    rep2(i, 1, N) {
        ll x = 0;
        if (S[i] == 'A') x = 1;
        if (S[i] == 'B') x = -1;
        cm[i] = cm[i - 1] + x;
    }

    map<ll, ll> cnts;
    rep(i, N) {
        cnts[cm[i]]++;
    }

    int m = cnts.size();
    fenwick_tree<ll> fw(m);

    vll ks;
    {
        int i = 0;
        for (auto [key, freq] : cnts) {
            ks.push_back(key);
            fw.add(i, freq);
            i++;
        }
    }

    ll offset = 0;
    ll ans = 0;
    rep(i, N) {
        char c = S[i];
        auto it = upper_bound(all(ks), offset);
        if (it != ks.end()) {
            ll l = it - ks.begin();
            ans += fw.sum(l, m);
        }

        if (c == 'A') {
            offset++;
        }
        if (c == 'B') {
            offset--;
        }
        ll l = lower_bound(all(ks), cm[i]) - ks.begin();
        fw.add(l, -1);
    }
    cout << ans << endl;
}
