/*https://atcoder.jp/contests/abc301/tasks/abc301_c*/
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

bool isatcoder(char c) {
    string s = "atcoder";
    for (char x : s)
        if (c == x)
            return true;
    return false;
}

void solve() {
    string S, T;
    cin >> S >> T;
    map<char, int> smap, tmap;
    int sat = 0, tat = 0;
    for (char c : S) {
        if (c != '@')
            smap[c]++;
        else
            sat++;
    }
    for (char c : T) {
        if (c != '@')
            smap[c]--;
        else
            tat++;
    }

    bool ok = true;
    for (auto it = smap.begin(); it != smap.end(); it++) {
        char c = it->first;
        int n = it->second;
        if (n == 0)
            continue;

        if (n < 0) {
            if (!isatcoder(c)) {
                ok = false;
                break;
            }
            if (n + sat < 0) {
                ok = false;
                break;
            }
            sat += n;
        } else {
            if (!isatcoder(c)) {
                ok = false;
                break;
            }
            if (tat - n < 0) {
                ok = false;
                break;
            }
            tat -= n;
        }
    }
    yesno(ok);
}
