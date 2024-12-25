// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_aa
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

int N, A[200009], C[200009];

// A[l], A[l+1], ..., A[r−1] を小さい順に整列する関数
void MergeSort(int l, int r) {
    // r−l=1 の場合、すでにソートされているので何もしない
    if (r - l == 1)
        return;

    // 2 つに分割した後、小さい配列をソート
    int m = (l + r) / 2;
    MergeSort(l, m);
    MergeSort(m, r);

    // この時点で以下の 2 つの配列がソートされている：
    // 列 A' に相当するもの [A[l], A[l+1], ..., A[m−1]]
    // 列 B' に相当するもの [A[m], A[m+1], ..., A[r−1]]
    // 以下が Merge 操作となります。
    int c1 = l, c2 = m, cnt = 0;
    while (c1 != m || c2 != r) {
        if (c1 == m) {
            C[cnt] = A[c2];
            c2++;
        } else if (c2 == r) {
            C[cnt] = A[c1];
            c1++;
        } else {
            if (A[c1] < A[c2]) {
                C[cnt] = A[c1];
                c1++;
            } else {
                C[cnt] = A[c2];
                c2++;
            }
        }
        cnt++;
    }

    // 列 A', 列 B' を合併した配列 C を A に移す
    // [C[0], ..., C[cnt−1]] −> [A[l], ..., A[r−1]]
    for (int i = 0; i < cnt; i++)
        A[l + i] = C[i];
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    cin >> N;
    rep(i, N) cin >> A[i + 1];

    MergeSort(1, N + 1);
    rep2(i, 1, N + 1) {
        if (i != 1)
            cout << ' ';
        cout << A[i];
    }
    cout << endl;
}
