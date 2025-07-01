// https://atcoder.jp/contests/arc175/tasks/arc175_b
// 2025年07月02日 07時08分25秒
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
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
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

    ll N, A, B;
    string S;
    cin >> N >> A >> B >> S;

    string T = "";

    rep(i, N * 2) {
        if (T.size() && S[i] == ')' && T.back() == '(') {
            T.pop_back();
        } else {
            T.push_back(S[i]);
        }
    }

    ll numl = 0, numr = 0;
    for (char c : T) {
        if (c == ')')
            numl++;
        else
            numr++;
    }

    ll num = min(numl, numr);
    ll q = num / 2;

    ll ans = 0;
    ans += min(A, B * 2) * q;

    numl -= q * 2;
    numr -= q * 2;

    if (min(numl, numr) == 1) {
        ans += min(A, B * 2);
        numl--;
        numr--;
    }

    num = max(numr, numl);
    ans += num / 2 * B;
    cout << ans << endl;
}
