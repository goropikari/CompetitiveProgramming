/*https://atcoder.jp/contests/abc319/tasks/abc319_d*/
/*2025年01月24日 02時10分27秒*/
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ll N, M;
    cin >> N >> M;

    vll L(N);
    rep(i, N) cin >> L[i];

    ll ok = INF, ng = 0;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll cnt = 1;
        bool top = true;
        ll len = 0;
        bool pass = true;
        for (ll l : L) {
            if (l > mid) {
                pass = 0;
                break;
            }
            if (top) {
                len += l;
                top = false;
            } else {
                if (len + l + 1 > mid) {
                    cnt++;
                    len = l;
                } else {
                    len += l + 1;
                }
            }
        }

        if (cnt > M)
            pass = false;
        if (pass)
            ok = mid;
        else
            ng = mid;
    }

    cout << ok << endl;
}
