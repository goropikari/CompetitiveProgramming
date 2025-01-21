/*https://atcoder.jp/contests/abc299/tasks/abc299_d*/
/*2025年01月22日 00時01分20秒*/
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
    int N;
    cin >> N;
    vint num(N, -1);
    num[0] = 0;
    num[N - 1] = 1;
    int l = 0, r = N - 1;
    while (abs(l - r) > 1) {
        int mid = (l + r) / 2;
        cout << "? " << mid + 1 << endl;
        cout << flush;

        int s;
        cin >> s;
        num[mid] = s;
        if (s) {
            r = mid;
        } else {
            l = mid;
        }
        if (num[l + 1] == 1) {
            cout << "! " << l + 1 << endl;
            cout << flush;
            return;
        }
        if (num[r - 1] == 0) {
            cout << "! " << r << endl;
            cout << flush;
            return;
        }
    }
    cout << "! " << r << endl;
    cout << flush;
    return;
}
