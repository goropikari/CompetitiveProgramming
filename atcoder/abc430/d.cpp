// https://atcoder.jp/contests/abc430/tasks/abc430_d
// Sat 01 Nov 2025 10:05:37 PM JST
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vll X(N);
    rep(i, N) cin >> X[i];

    map<ll, ll> pos_to_id;
    rep(i, N) {
        pos_to_id[X[i]] = i + 1;
    }

    pos_to_id[0] = 0;
    pos_to_id[INF] = INF;

    vll dist(N + 1, INF);

    set<ll> pos;
    pos.insert(0);
    pos.insert(INF);

    ll ans = 0;

    auto update = [&](ll p) -> void {
        ll id = pos_to_id[p];
        auto it = pos.lower_bound(p);
        ll lpos = *prev(it);
        ll lid = pos_to_id[lpos];
        ll rpos = *next(it);
        ll rid = pos_to_id[rpos];

        if (rpos == INF) {
            dist[id] = p - lpos;
            ans += dist[id];

            ll now = dist[lid];
            if (now != INF)
                ans -= now;
            chmin(dist[lid], dist[id]);
            ans += dist[lid];
        } else {
            dist[id] = min(p - lpos, rpos - p);
            ans += dist[id];

            ans -= dist[lid] + dist[rid];
            chmin(dist[lid], p - lpos);
            chmin(dist[rid], rpos - p);
            ans += dist[rid] + dist[lid];
        }
    };

    rep(i, N) {
        ll x = X[i];
        pos.insert(x);
        update(x);
        cout << ans << '\n';
    }
}
