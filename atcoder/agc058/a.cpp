// https://atcoder.jp/contests/agc058/tasks/agc058_a
// 2025年05月13日 01時07分15秒
#include <bits/stdc++.h>
#include <algorithm>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vint P(N * 2);
    rep(i, N * 2) cin >> P[i];

    vint ans;
    for (int i = 0; i < N * 2 - 1; i += 2) {
        if (i == N * 2 - 2) {
            if (P[i] > P[i + 1]) {
                swap(P[i], P[i + 1]);
                ans.push_back(i);
            }
        } else {
            if (P[i] < P[i + 1] && P[i + 1] < P[i + 2]) {
                swap(P[i + 1], P[i + 2]);
                ans.push_back(i + 1);
            } else if (P[i] > P[i + 1] && P[i + 1] > P[i + 2]) {
                swap(P[i], P[i + 1]);
                ans.push_back(i);
            } else if (P[i] > P[i + 1] && P[i + 1] < P[i + 2]) {
                if (P[i] > P[i + 2]) {
                    swap(P[i], P[i + 1]);
                    ans.push_back(i);
                } else {
                    swap(P[i + 1], P[i + 2]);
                    ans.push_back(i + 1);
                }
            }
        }
    }
    for (int& x : ans)
        x++;
    cout << ans.size() << endl;
    print(ans);
}
