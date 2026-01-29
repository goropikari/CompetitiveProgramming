// https://atcoder.jp/contests/abc429/tasks/abc429_f
// Fri 30 Jan 2026 12:29:42 AM JST
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
    vvll mat;

    S() {
        mat = vvll(3, vll(3, INF));
    }

    S operator*(const S& other) {
        S v;

        rep(i, 3) rep(j, 3) {
            ll t = INF;
            rep(k, 3) {
                chmin(t, mat[i][k] + other.mat[k][j]);
            }
            v.mat[i][j] = t;
        }

        return v;
    }
};

S op(S a, S b) {
    return a * b;
}

S e() {
    S ret;
    ret.mat = {{0, INF, INF}, {INF, 0, INF}, {INF, INF, 0}};
    return ret;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vint state(N);

    {
        vector<string> grid(3);
        rep(i, 3) cin >> grid[i];

        rep(j, N) {
            int t = 0;
            rep(i, 3) {
                if (grid[i][j] == '#') t += 1 << i;
            }
            state[j] = t;
        }
    }

    vector<S> V(8);
    rep(st, 1 << 3) {
        S tmp;
        rep(i, 3) {
            vll v(3, INF);
            if (st >> i & 1) continue;

            // index, cost
            using P = pair<ll, ll>;
            queue<P> que;
            v[i] = 0;
            que.push({i, 0});

            while (que.size()) {
                auto [id, cost] = que.front();
                que.pop();

                for (auto d : {-1, 1}) {
                    ll nid = id + d;
                    if (clamp(nid, 0ll, 2ll) != nid) continue;
                    if (!(st >> nid & 1) && v[nid] > cost + 1) {
                        v[nid] = cost + 1;
                        que.push({nid, cost + 1});
                    }
                }
            }

            rep(j, 3) tmp.mat[i][j] = v[j];
        }

        V[st] = tmp;
    }

    segtree<S, op, e> seg(N);
    rep(i, N) {
        seg.set(i, V[state[i]]);
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        ll x, y;
        cin >> x >> y;
        x--, y--;

        state[y] ^= 1 << x;
        seg.set(y, V[state[y]]);

        S ret = seg.prod(0, N);

        ll ans = INF;
        chmin(ans, N - 1 + ret.mat[0][2]);
        if (ans == INF) ans = -1;
        cout << ans << '\n';
    }
}
