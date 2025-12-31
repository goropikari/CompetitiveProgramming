// https://atcoder.jp/contests/abc429/tasks/abc429_d
// Tue 30 Dec 2025 05:31:13 PM JST
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

    ll N, M, C;
    cin >> N >> M >> C;
    vll A(N);
    rep(i, N) cin >> A[i];

    map<ll, ll> pos_num;
    pos_num[0] = pos_num[M] = 0;
    for (auto a : A) {
        pos_num[a]++;
        pos_num[(a + 1) % M] = pos_num[(a + 1) % M];
    }

    vll pos, cnt;
    for (auto [p, v] : pos_num) {
        pos.push_back(p);
        cnt.push_back(v);
    }

    int sz = (int)pos.size();
    ll ans = 0;
    ll sum = 0;
    ll fin = 0;
    vint used(sz);
    rep(start, sz - 1) {
        if (!used[start]) {
            sum += cnt[start];
            used[start] = 1;
        }
        while (sum < C) {
            fin++;
            fin %= sz;
            used[fin] = 1;
            sum += cnt[fin];
        }
        ans += sum;
        sum -= cnt[start];
        used[start] = 0;
        if (start == fin) fin++;

        if (sum >= C) {
            ans += sum * (pos[start + 1] - pos[start] - 1);
        }
    }
    cout << ans << endl;
}
