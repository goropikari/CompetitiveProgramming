// https://atcoder.jp/contests/abc361/tasks/abc361_d
// Wed 07 Jan 2026 09:20:14 PM JST
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

ll intpow(ll x, ll n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1)
            ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    string S, T;
    cin >> N >> S >> T;
    N += 2;

    auto toid = [&](string s) -> ll {
        ll ret = 0;
        for (char c : s) {
            ret *= 3;
            if (c == 'B') {
                ret += 2;
            }
            if (c == 'W') {  // W
                ret += 1;
            }
        }
        return ret;
    };

    auto idtos = [&](ll id) -> string {
        string ret = "";
        rep(i, N) {
            if (id % 3 == 0) {
                ret.push_back('_');
            } else if (id % 3 == 1) {
                ret.push_back('W');
            } else {
                ret.push_back('B');
            }
            id /= 3;
        }
        reverse(all(ret));
        return ret;
    };

    S += "__";
    T += "__";

    vll dist(intpow(3, N), INF);
    dist[toid(S)] = 0;
    ll goal = toid(T);

    // cost, id
    using P = pair<ll, ll>;
    queue<P> que;
    que.push({0, toid(S)});
    while (que.size()) {
        auto [cost, id] = que.front();
        que.pop();

        if (dist[id] < cost) continue;
        string t = idtos(id);
        int space_id = -1;
        rep(j, N - 1) {
            if (t[j] == '_' && t[j + 1] == '_') {
                space_id = j;
                break;
            }
        }
        if (space_id < 0) continue;

        int ok = 0;
        rep(i, N - 1) {
            if (t[i] != '_' && t[i + 1] != '_') {
                string tmp = t;
                swap(tmp[space_id], tmp[i]);
                swap(tmp[space_id + 1], tmp[i + 1]);
                ll nxid = toid(tmp);
                if (dist[nxid] > cost + 1) {
                    dist[nxid] = cost + 1;
                    que.push({cost + 1, nxid});
                    if (nxid == goal) {
                        ok = 1;
                        break;
                    }
                }
            }
        }
        if (ok) break;
    }

    ll ans = -1;
    if (dist[goal] != INF) ans = dist[goal];
    cout << ans << endl;
}
