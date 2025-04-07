// https://atcoder.jp/contests/abc324/tasks/abc324_e
// 2025年04月08日 02時23分48秒
#include <bits/stdc++.h>
#include <atcoder/all>
#include <atcoder/fenwicktree.hpp>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;

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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string T;
    cin >> N >> T;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    string revT = T;
    reverse(all(revT));
    vector<string> revS = S;
    rep(i, N) reverse(all(revS[i]));

    auto cal = [](vector<string> ss, string t) -> vll {
        vll ret(t.size() + 1);
        for (string s : ss) {
            int i = 0;
            for (char c : s) {
                if (i >= (int)t.size())
                    break;
                if (c == t[i])
                    i++;
            }
            ret[i]++;
        }
        return ret;
    };

    vll head = cal(S, T);
    vll tail = cal(revS, revT);

    int tsz = T.size();
    fenwick_tree<ll> cumsum_tail(tsz + 1);
    rep(i, tsz + 1) cumsum_tail.add(i, tail[i]);

    ll ans = 0;
    rep(i, tsz + 1) {
        ans += head[i] * cumsum_tail.sum(tsz - i, tsz + 1);
    }

    cout << ans << endl;
}
