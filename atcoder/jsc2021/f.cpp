// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_f
// Tue 17 Feb 2026 09:55:51 AM JST
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

    ll N, M, Q;
    cin >> N >> M >> Q;

    vector<tuple<ll, ll, ll>> queries(Q);
    vll pos;
    rep(i, Q) {
        ll t, x, y;
        cin >> t >> x >> y;
        pos.push_back(y);
        queries[i] = {t, x, y};
    }

    pos.push_back(0);
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());

    auto op = [](ll a, ll b) -> ll {
        return a + b;
    };
    auto e = []() -> ll {
        return 0;
    };

    ll sz = pos.size();
    segtree<ll, op, e> cnta(sz), cntb(sz), suma(sz), sumb(sz);
    cnta.set(0, N), cntb.set(0, M);

    vll A(N), B(M);

    ll ans = 0;
    for (auto [ti, xi, yi] : queries) {
        xi--;
        if (ti == 2) {
            swap(A, B);
            swap(cnta, cntb);
            swap(suma, sumb);
        }
        ll pr = A[xi];
        ll r = upper_bound(all(pos), pr) - pos.begin();
        ans -= pr * cntb.prod(0, r);
        ans -= sumb.prod(r, sz);
        cnta.set(r - 1, cnta.get(r - 1) - 1);
        suma.set(r - 1, suma.get(r - 1) - pos[r - 1]);

        r = upper_bound(all(pos), yi) - pos.begin();
        ans += yi * cntb.prod(0, r);
        ans += sumb.prod(r, sz);
        A[xi] = yi;
        cnta.set(r - 1, cnta.get(r - 1) + 1);
        suma.set(r - 1, suma.get(r - 1) + pos[r - 1]);
        if (ti == 2) {
            swap(A, B);
            swap(cnta, cntb);
            swap(suma, sumb);
        }
        cout << ans << '\n';
    }
}
