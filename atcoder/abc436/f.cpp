// https://atcoder.jp/contests/abc436/tasks/abc436_f
// Mon 19 Jan 2026 11:09:08 PM JST
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
    cin >> N;
    vll B(N);
    rep(i, N) {
        cin >> B[i];
        B[i]--;
    }

    // number, id
    using P = pair<ll, ll>;
    vector<P> ps;
    rep(i, N) ps.emplace_back(B[i], i);
    sort(rall(ps), [](P a, P b) -> bool {
        return a.first < b.first;
    });

    fenwick_tree<ll> fw(N);
    rep(i, N) fw.add(i, 1);

    ll ans = 0;
    for (auto [_, id] : ps) {
        ll l = 1, r = 1;
        if (0 < id) {
            l += fw.sum(0, id);
        }
        if (id + 1 < N) {
            r += fw.sum(id + 1, N);
        }
        ans += l * r;
        fw.add(id, -1);
    }
    cout << ans << endl;
}
