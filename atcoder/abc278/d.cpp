/*https://atcoder.jp/contests/abc278/tasks/abc278_d*/
/*2025年01月20日 22時11分37秒*/
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
    ll N;
    cin >> N;
    vector<pair<ll, ll>> A(N);
    rep(i, N) {
        ll a;
        cin >> a;
        A[i] = {0, a};
    }

    int Q;
    cin >> Q;
    pair<ll, ll> memo = {0, 0};
    rep(_, Q) {
        int q;
        cin >> q;
        if (q == 1) {
            ll x;
            cin >> x;
            ll gen = memo.first;
            memo = {gen + 1, x};
        } else if (q == 2) {
            ll k, x;
            cin >> k >> x;
            k--;
            if (memo.first != A[k].first) {
                A[k] = memo;
            }
            A[k].second += x;
        } else {
            ll k;
            cin >> k;
            k--;
            if (memo.first != A[k].first) {
                A[k] = memo;
            }
            cout << A[k].second << endl;
        }
    }
}
