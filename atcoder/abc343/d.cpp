/*https://atcoder.jp/contests/abc343/tasks/abc343_d*/
/*2025年01月25日 01時01分31秒*/
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
    ll N, T;
    cin >> N >> T;

    vll A(T), B(T);
    rep(i, T) {
        cin >> A[i] >> B[i];
        A[i]--;
    }

    vll scores(N, 0);
    map<ll, ll> cnt;
    cnt[0] = N;

    rep(i, T) {
        ll a = A[i], b = B[i];
        ll w = scores[a];
        cnt[w]--;
        if (cnt[w] == 0) {
            cnt.erase(w);
        }
        w += b;
        scores[a] = w;
        cnt[w]++;
        cout << cnt.size() << endl;
    }
}
