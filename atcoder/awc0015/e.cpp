// https://atcoder.jp/contests/awc0015/tasks/awc0015_e
// Sat 28 Feb 2026 01:04:34 AM JST
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

    int N, Q;
    cin >> N >> Q;

    vint C(N);
    rep(i, N) cin >> C[i];

    unordered_map<int, int> last;

    auto op = [](int a, int b) -> int {
        return a + b;
    };
    auto e = []() -> int {
        return 0;
    };
    segtree<int, op, e> seg(N);

    // l, r, index
    using T = tuple<int, int, int>;
    vector<T> qs(Q);
    rep(i, Q) {
        int l, r;
        cin >> l >> r;
        l--;
        qs[i] = {l, r, i};
    }

    sort(all(qs), [](T a, T b) -> bool {
        return get<1>(a) < get<1>(b);
    });

    vint ans(Q);

    int qi = 0;
    rep(i, N) {
        int c = C[i];
        if (last.count(c)) {
            seg.set(last[c], 0);
        }

        seg.set(i, 1);
        last[c] = i;

        while (qi < Q && get<1>(qs[qi]) == i + 1) {
            auto [l, r, id] = qs[qi];
            ans[id] = seg.prod(l, r);
            qi++;
        }
    }

    vprint(ans);
}
