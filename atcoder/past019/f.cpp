// https://atcoder.jp/contests/past19-open/tasks/past19_f
// 2025年03月30日 17時41分56秒
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
    cin >> N;
    string X, Y;
    cin >> X >> Y;

    vector<string> ss(N), tt(N);
    rep(i, N) {
        cin >> ss[i] >> tt[i];
    }

    map<string, int> label;
    {
        set<string> uniq;
        uniq.insert(X);
        uniq.insert(Y);

        rep(i, N) {
            uniq.insert(ss[i]);
            uniq.insert(tt[i]);
        }

        int i = 0;
        for (string s : uniq) {
            label[s] = i;
            i++;
        }
    }

    int m = label.size();
    vvint graph(m);
    rep(i, N) {
        graph[label[ss[i]]].push_back(label[tt[i]]);
    }

    vint visited(m, 0);
    visited[label[X]] = 1;

    auto dfs = [&](auto dfs, int now, int p = -1) -> void {
        for (int nx : graph[now]) {
            if (nx == p)
                continue;
            if (visited[nx])
                continue;
            visited[nx] = 1;
            dfs(dfs, nx, now);
        }
    };

    dfs(dfs, label[X]);
    yesno(visited[label[Y]]);
}
