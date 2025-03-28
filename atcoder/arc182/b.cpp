/*https://atcoder.jp/contests/arc182/tasks/arc182_b*/
/*2025年03月21日 02時15分36秒*/
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

    vvll tp(31);
    tp[0].push_back(1);
    rep2(i, 1, 31) {
        ll cnt = 0;
        int ex = 0;
        rep(j, 2) {
            for (ll x : tp[i - 1]) {
                tp[i].push_back((x << 1) + j);
                cnt++;
                if (cnt > 2e5 + 5) {
                    ex = 1;
                    break;
                }
            }
            if (ex)
                break;
        }
    }

    auto cal = [&](ll n, ll k) -> void {
        vll ans;
        rep(i, n) {
            if (i < tp[k - 1].size())
                ans.push_back(tp[k - 1][i]);
            else
                ans.push_back(1);
        }
        print(ans);
    };

    int t;
    cin >> t;
    rep(i, t) {
        ll n, k;
        cin >> n >> k;
        cal(n, k);
    }
}
