// https://atcoder.jp/contests/awc0028/tasks/awc0028_d
// Wed 18 Mar 2026 08:13:13 PM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
bool chmin(T& a, T b) {
    bool change = a > b;
    a = min(a, b);
    return change;
}
template <typename T>
bool chmax(T& a, T b) {
    bool change = a < b;
    a = max(a, b);
    return change;
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

    ll N, M;
    cin >> N >> M;
    vll A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }

    vvint to(N), rev(N);
    rep(i, M) {
        to[A[i]].pb(B[i]);
        rev[B[i]].pb(A[i]);
    }

    vint starts;
    rep(i, N) {
        auto v = rev[i];
        if (v.size() == 0) starts.pb(i);
    }

    priority_queue<ll, vll, greater<ll>> pq;
    for (auto s : starts) pq.push(s);

    vint visited(N);
    vint ans;
    rep(i, N) visited[i] = rev[i].size();
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        ans.pb(now + 1);
        for (int nx : to[now]) {
            visited[nx]--;
            if (visited[nx] == 0) pq.push(nx);
        }
    }
    print(ans);
}
