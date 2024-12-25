/*https://atcoder.jp/contests/abc324/tasks/abc324_c*/
/*2024年12月25日 23時33分59秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
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

bool check(string& s, string& t) {
    int ns = s.size();
    int nt = t.size();

    // same or change
    if (ns == nt) {
        int cnt = 0;
        rep(i, nt) cnt += s[i] != t[i];
        return cnt <= 1;
    }

    if (abs(ns - nt) > 1)
        return false;

    // add
    if (ns < nt) {
        int i = 0, j = 0, cnt = 0;
        while (i < ns && j < nt) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                cnt++;
                j++;
            }
        }
        return cnt <= 1;
    }

    // delete
    // ns > nt
    int i = 0, j = 0, cnt = 0;
    while (i < ns && j < nt) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            cnt++;
            i++;
        }
    }
    return cnt <= 1;
}

void solve() {
    int N;
    string T;
    cin >> N >> T;
    vector<string> S(N);

    rep(i, N) cin >> S[i];
    vint ans;
    rep(i, N) {
        if (check(S[i], T))
            ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    print(ans);
}
