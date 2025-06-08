// https://atcoder.jp/contests/abc409/tasks/abc409_f
// 2025年06月07日 22時04分24秒
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
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

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;

    vector<pair<ll, ll>> pos;
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        pos.emplace_back(x, y);
    }

    vvll queries(Q);
    rep(i, Q) {
        int t;
        cin >> t;
        if (t == 1) {
            ll a, b;
            cin >> a >> b;
            queries[i] = {t, a, b};
        } else if (t == 2) {
            queries[i] = {t, -1, -1};
        } else {
            ll u, v;
            cin >> u >> v;
            u--, v--;
            queries[i] = {t, u, v};
        }
    }

    ll numv = N;
    for (auto v : queries) {
        if (v[0] == 1) numv++;
    }

    map<ll, vector<pair<ll, ll>>> dist_memo;
    rep(i, N) {
        rep2(j, i + 1, N) {
            ll d = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
            dist_memo[d].push_back({i, j});
        }
    }

    dsu uf(numv);
    ll unite_num = N;

    for (auto v : queries) {
        ll t = v[0], a = v[1], b = v[2];

        if (t == 1) {
            unite_num++;
            int nx = N;
            rep(i, N) {
                ll d = abs(pos[i].first - a) + abs(pos[i].second - b);
                dist_memo[d].push_back({i, nx});
            }
            N++;
            pos.emplace_back(a, b);
        } else if (t == 2) {
            if (unite_num == 1) {
                cout << -1 << endl;
                continue;
            }

            ll k = -1;
            vll erase_cand;
            for (auto [key, val] : dist_memo) {
                int ok = 0;
                k = key;
                erase_cand.push_back(key);
                for (auto p : val) {
                    auto [u, v] = p;
                    if (uf.same(u, v)) continue;
                    ok = 1;
                    uf.merge(u, v);
                    unite_num--;
                }
                if (ok) break;
            }
            for (ll x : erase_cand) dist_memo.erase(x);
            cout << k << endl;
        } else {
            ll u = a, v = b;
            yesno(uf.same(u, v));
        }
    }
}
