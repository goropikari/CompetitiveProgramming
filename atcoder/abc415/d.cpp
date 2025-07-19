// https://atcoder.jp/contests/abc415/tasks/abc415_d
// 2025年07月19日 21時25分25秒
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

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
}

void solve();

int main() {
    solve();
    return 0;
}

struct Change {
    ll A, B;
};

bool operator>(const Change& p, const Change& q) {
    return p.A - p.B > q.A - q.B;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vll A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    priority_queue<Change, vector<Change>, greater<Change>> pq;
    rep(i, M) {
        pq.push({A[i], B[i]});
    }

    ll akibin = N;
    ll ans = 0;
    while (pq.size()) {
        auto [A, B] = pq.top();
        if (akibin < A) {
            pq.pop();
            continue;
        }
        ll x = (akibin - A) / (A - B) + 1;
        akibin -= x * (A - B);
        ans += x;
    }
    cout << ans << endl;
}
