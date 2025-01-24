/*https://atcoder.jp/contests/abc329/tasks/abc329_d*/
/*2025年01月24日 20時12分18秒*/
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
    int N, M;
    cin >> N >> M;

    vint A(M);
    rep(i, M) {
        cin >> A[i];
        A[i]--;
    }

    vint cnt(N, 0);

    // i 番目を開票したときに当選するのはそれまで投票数が一番多かった人物か
    // 開票した結果の人のいずれか
    int now = A[0];
    cnt[now]++;
    vint ans = {now};
    rep2(i, 1, M) {
        int nx = A[i];
        cnt[nx]++;
        if (cnt[now] == cnt[nx]) {
            now = min(now, nx);
            ans.push_back(now);
        } else if (cnt[now] < cnt[nx]) {
            now = nx;
            ans.push_back(nx);
        } else {
            ans.push_back(now);
        }
    }

    for (int x : ans)
        cout << x + 1 << endl;
}
