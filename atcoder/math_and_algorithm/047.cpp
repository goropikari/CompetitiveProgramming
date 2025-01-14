// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_ao
/*2025年01月12日 03時09分49秒*/
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

void solve() {
    int N, M;
    cin >> N >> M;
    vll A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }

    vvint graph(N);
    rep(i, M) {
        graph[A[i]].push_back(B[i]);
        graph[B[i]].push_back(A[i]);
    }

    vint col(N, -1);
    rep(i, N) {
        if (col[i] >= 0)
            continue;
        col[i] = 0;
        queue<int> que;
        que.push(i);
        while (que.size()) {
            int x = que.front();
            que.pop();
            int c = col[x];
            for (int nx : graph[x]) {
                if (col[nx] == c) {
                    yesno(false);
                    return;
                }
                if (col[nx] < 0) {
                    que.push(nx);
                    col[nx] = 1 - c;
                }
            }
        }
    }
    yesno(true);
}
