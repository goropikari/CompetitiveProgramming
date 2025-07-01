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

    int n;
    long long a, b;
    cin >> n >> a >> b;
    a = min(a, 2 * b);
    string s;
    cin >> s;
    int p = count(s.begin(), s.end(), '(');
    int m = 2 * n - p;
    int d = p - m;
    long long res = 0;
    if (p > m) {
        for (int i = 2 * n - 1; i >= 0; --i) {
            if (s[i] == '(' and d) {
                d -= 2;
                s[i] = ')';
                res += b;
            }
        }
    } else {
        for (int i = 0; i < 2 * n; i++) {
            if (s[i] == ')' and d) {
                d += 2;
                s[i] = '(';
                res += b;
            }
        }
    }
    long long cum = 0, mn = 0;
    for (int i = 0; i < 2 * n; i++) {
        cum += (s[i] == '(' ? 1 : -1);
        mn = min(mn, cum);
    }
    res += (-mn + 1) / 2 * a;
    cout << res << endl;
}
