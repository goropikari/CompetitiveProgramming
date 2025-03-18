/*https://atcoder.jp/contests/typical90/tasks/typical90_a*/
/*2025年03月17日 00時02分17秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, L, K;
    cin >> N >> L >> K;
    vll A(N);
    rep(i, N) cin >> A[i];

    A.insert(A.begin(), 0);
    A.push_back(L);
    vll diff;
    rep(i, N + 1) {
        diff.push_back(A[i + 1] - A[i]);
    }

    int m = diff.size();
    ll ac = 0, wa = L + 1;
    while (abs(ac - wa) > 1) {
        ll wj = (ac + wa) / 2;
        int i = 0;
        ll cnt = 0;
        ll sum = 0;
        rep(i, m) {
            sum += diff[i];
            if (sum >= wj) {
                sum = 0;
                cnt++;
            }
        }

        if (cnt >= K + 1) {
            ac = wj;
        } else {
            wa = wj;
        }
    }
    cout << ac << endl;
}
