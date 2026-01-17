// https://atcoder.jp/contests/abc344/tasks/abc344_e
// Sat 17 Jan 2026 04:32:18 PM JST
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
    vll A(N);
    rep(i, N) cin >> A[i];

    ll head = A[0];

    unordered_map<ll, ll> to, pr;
    rep(i, N - 1) {
        to[A[i]] = A[i + 1];
    }
    for (int i = N - 1; i > 0; i--) {
        pr[A[i]] = A[i - 1];
    }

    int Q;
    cin >> Q;
    rep(i, Q) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x, y;
            cin >> x >> y;
            ll l = x, r = to[x];
            to[l] = y;
            to[y] = r;
            pr[y] = x;
            pr[r] = y;
        } else {
            ll x;
            cin >> x;

            if (x == head) {
                head = to[x];
            }

            ll l = pr[x], r = to[x];
            if (l != 0)
                to[l] = r;
            if (r != 0)
                pr[r] = l;
        }
    }

    vll ans;
    ll now = head;
    do {
        ans.push_back(now);
        now = to[now];
    } while (now != 0);
    print(ans);
}
