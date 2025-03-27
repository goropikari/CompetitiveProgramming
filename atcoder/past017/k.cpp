// https://atcoder.jp/contests/past17-open/tasks/past17_k
/*2025年03月27日 22時15分13秒*/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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
    string S;
    cin >> N >> S;
    S = "_" + S;

    vvint dp(N + 1, vint(10, 0));
    dp[0][0] = 1;

    rep2(i, 1, N + 1) {
        rep(j, 10) {
            if (dp[i - 1][j] == 0)
                continue;
            if (S[i] != '?') {
                int k = S[i] - '0';
                dp[i][(j + i * k) % 10] = 1;
            } else {  // S[i] = '?'
                rep(k, 10) {
                    dp[i][(j + i * k) % 10] = 1;
                }
            }
        }
    }

    if (dp[N][0] == 0) {
        yesno(false);
        return;
    }

    vint ans;
    int now = 0;
    for (int i = N; i >= 1; i--) {
        if (S[i] == '?') {
            rep(j, 10) {
                int t = 10 - (j * i) % 10;
                t %= 10;

                int nx = (now + t) % 10;
                if (dp[i - 1][nx]) {
                    ans.push_back(j);
                    now = nx;
                    break;
                }
            }
        } else {
            int t = 10 - (S[i] - '0') * i % 10;
            t %= 10;
            int nx = (now + t) % 10;
            ans.push_back(S[i] - '0');
            now = nx;
        }
    }
    reverse(all(ans));
    rep(i, N) {
        if (S[i + 1] == '?') {
            S[i + 1] = '0' + ans[i];
        }
    }
    yesno(true);
    cout << S.substr(1, N) << endl;
}
