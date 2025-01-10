/*https://atcoder.jp/contests/abc216/tasks/abc216_d*/
/*2025年01月08日 23時50分41秒*/
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
    vector<deque<int>> A(M);
    rep(i, M) {
        int k;
        cin >> k;
        int a;
        rep(j, k) {
            cin >> a;
            A[i].push_back(a);
        }
    }

    map<int, vint> mp;
    queue<int> que;
    rep(i, M) {
        if (A[i].size() != 0) {
            int num = A[i].front();
            A[i].pop_front();
            mp[num].push_back(i);

            if (mp[num].size() == 2) {
                que.push(num);
            }
        }
    }
    while (que.size()) {
        int num = que.front();
        que.pop();

        for (int x : mp[num]) {
            if (A[x].size()) {
                int t = A[x].front();
                A[x].pop_front();
                mp[t].push_back(x);
                if (mp[t].size() == 2) {
                    que.push(t);
                }
            }
        }
    }

    bool ok = true;
    rep(i, M) ok = ok && A[i].size() == 0;
    yesno(ok);
}
