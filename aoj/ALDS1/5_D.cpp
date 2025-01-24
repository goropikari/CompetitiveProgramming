// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
/*2025年01月22日 23時10分23秒*/
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

vint L, R;

ll merge(vint& v, int l, int mid, int r) {
    int n1 = mid - l;
    int n2 = r - mid;

    rep(i, n1) L[i] = v[l + i];
    rep(i, n2) R[i] = v[mid + i];
    L[n1] = R[n2] = INF;

    int i = 0, j = 0;
    ll cnt = 0;
    rep2(k, l, r) {
        if (L[i] <= R[j]) {
            v[k] = L[i++];
        } else {
            v[k] = R[j++];
            cnt += n1 - i;
        }
    }

    return cnt;
}

ll mergeSort(vint& v, int l, int r) {
    if (r - l <= 1)
        return 0;
    ll mid = (l + r) / 2;
    ll v1 = mergeSort(v, l, mid);
    ll v2 = mergeSort(v, mid, r);
    ll v3 = merge(v, l, mid, r);
    return v1 + v2 + v3;
}

void solve() {
    int n;
    cin >> n;
    vint a(n);
    rep(i, n) cin >> a[i];

    L = vint(n);
    R = vint(n);

    ll cnt = mergeSort(a, 0, n);
    cout << cnt << endl;
}
