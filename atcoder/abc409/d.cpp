// https://atcoder.jp/contests/abc409/tasks/abc409_d
// 2025年06月07日 21時27分45秒
#include <bits/stdc++.h>
#include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
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
using namespace std;
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

    auto cal = []() -> void {
        ll N;
        string S;
        cin >> N >> S;

        int start = -1;
        rep(i, N - 1) {
            if (S[i] > S[i + 1]) {
                start = i;
                break;
            }
        }
        if (start == -1) {
            cout << S << endl;
            return;
        }

        int fin = -1;
        rep2(i, start + 1, N) {
            if (S[start] < S[i]) {
                fin = i;
                break;
            }
        }

        if (fin == -1) {
            S.push_back(S[start]);
        } else {
            string t = "";
            t.push_back(S[start]);
            S.insert(fin, t);
        }

        S.erase(start, 1);
        cout << S << endl;
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
