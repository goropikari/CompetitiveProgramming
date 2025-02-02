/*https://atcoder.jp/contests/abc330/tasks/abc330_e*/
/*2025年02月02日 13時13分01秒*/
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
    ll N, Q;
    cin >> N >> Q;
    vll A(N);
    rep(i, N) cin >> A[i];

    vll cnt(N + 1, 0);
    set<ll> memo;

    for (ll x : A) {
        if (x > N)
            continue;
        cnt[x]++;
    }

    rep(i, N + 1) if (cnt[i] == 0) memo.insert(i);

    rep(_, Q) {
        ll i, x;
        cin >> i >> x;
        i--;
        if (A[i] <= N) {
            if (cnt[A[i]] == 1) {
                memo.insert(A[i]);
            }
            cnt[A[i]]--;
        }
        if (x <= N) {
            if (cnt[x] == 0) {
                memo.erase(x);
            }
            cnt[x]++;
        }
        A[i] = x;

        cout << *memo.begin() << endl;
    }
}
