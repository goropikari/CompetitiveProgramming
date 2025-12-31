// https://atcoder.jp/contests/abc428/tasks/abc428_c
// Wed 31 Dec 2025 03:31:07 AM JST
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

// const ll INF = (ll)2e18 + 9;
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

    int Q;
    cin >> Q;
    string S = "";

    vint invalid(Q + 1);
    ll unpaired_left, invalid_right;
    unpaired_left = invalid_right = 0;

    rep(i, Q) {
        int t;
        cin >> t;
        if (t == 1) {
            char c;
            cin >> c;

            if (c == '(') {
                unpaired_left++;
            } else {  // )
                if (unpaired_left) {
                    unpaired_left--;
                } else {
                    invalid[S.size()] = 1;
                    invalid_right++;
                }
            }

            S.push_back(c);
        } else {
            char c = S.back();

            if (c == '(') {
                unpaired_left--;
            } else {
                if (invalid[(int)S.size() - 1]) {
                    invalid[(int)S.size() - 1] = 0;
                    invalid_right--;
                } else {
                    unpaired_left++;
                }
            }
            S.pop_back();
        }

        yesno(unpaired_left == 0 && invalid_right == 0);
    }
}
