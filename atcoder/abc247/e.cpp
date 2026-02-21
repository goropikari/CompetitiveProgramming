// https://atcoder.jp/contests/abc247/tasks/abc247_e
// Fri 20 Feb 2026 12:36:13 AM JST
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

struct S {
    ll mx, mi;
};

S op(S a, S b) {
    return {max(a.mx, b.mx), min(a.mi, b.mi)};
}

S e() {
    return {-INF, INF};
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, X, Y;
    cin >> N >> X >> Y;
    vll A(N);
    rep(i, N) cin >> A[i];
    A.push_back(INF);
    N++;

    vvll segs(1);
    int j = 0;
    rep(i, N) {
        if (clamp(A[i], Y, X) != A[i]) {
            j++;
            segs.push_back(vll());
            continue;
        }

        segs[j].push_back(A[i]);
    }

    ll ans = 0;
    for (auto v : segs) {
        int M = v.size();
        if (M == 0) continue;

        {
            ll mx = *max_element(all(v));
            ll mi = *min_element(all(v));
            if (mi != Y || mx != X) continue;
        }

        segtree<S, op, e> seg(M);
        rep(i, M) seg.set(i, {v[i], v[i]});

        ll r = 0;
        rep(l, M) {
            chmax(r, l);
            while (r < M) {
                auto [mx, mi] = seg.prod(l, r);
                if (mx == X && mi == Y) {
                    break;
                }
                r++;
            }

            auto [mx, mi] = seg.prod(l, r);
            if (mx == X && mi == Y) {
                ans += M - r + 1;
            }
        }
    }

    cout << ans << endl;
}
