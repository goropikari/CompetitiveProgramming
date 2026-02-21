// https://atcoder.jp/contests/abc381/tasks/abc381_d
// Thu 19 Feb 2026 11:59:55 PM JST
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

template <typename T>
vector<pair<T, ll>> runLengthEncode(const vector<T>& input) {
    vector<pair<T, ll>> encoded;
    int size = input.size();
    for (int i = 0; i < size; ++i) {
        long long int count = 1;
        while (i + 1 < size && input[i] == input[i + 1]) {
            ++i;
            ++count;
        }
        encoded.emplace_back(input[i], count);
    }
    return encoded;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    using P = pair<ll, ll>;
    vector<P> vs;
    for (auto [a, cnt] : runLengthEncode(A)) {
        if (cnt <= 2) {
            vs.push_back({a, cnt});
        } else {
            vs.push_back({a, 2});
            vs.push_back({a, 2});
        }
    }

    vint used(N + 1);
    ll M = vs.size();
    ll r = 0, ans = 0;
    rep(l, M) {
        if (vs[l].second == 1) continue;
        chmax(r, l);
        while (r < M && vs[r].second == 2 && used[vs[r].first] == 0) {
            used[vs[r].first] = 1;
            r++;
        }

        used[vs[l].first] = 0;
        chmax(ans, (r - l) * 2);
    }

    cout << ans << endl;
}
