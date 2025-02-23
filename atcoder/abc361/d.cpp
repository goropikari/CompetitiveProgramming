/*https://atcoder.jp/contests/abc361/tasks/abc361_d*/
/*2025年02月22日 16時26分16秒*/
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

ll tonum(string s) {
    ll ret = 0;
    for (char c : s) {
        ret *= 10;
        if (c == 'B')
            ret += 1;
        if (c == 'W')
            ret += 2;
        if (c == '.')
            ret += 3;
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    n += 2;
    s.push_back('.');
    s.push_back('.');
    t.push_back('.');
    t.push_back('.');

    if (s == t) {
        cout << 0 << endl;
        return;
    }

    {
        string ts = s, tt = t;
        sort(all(ts)), sort(all(tt));
        if (ts != tt) {
            cout << -1 << endl;
            return;
        }
    }

    map<ll, vll> graph;
    {
        queue<ll> que;
        que.push(tonum(s));
        while (que.size()) {
            ll now = que.front();
            que.pop();

            if (graph.count(now))
                continue;

            string tmp = to_string(now);
            int a;
            rep(i, n - 1) {
                if (tmp[i] == '3') {
                    a = i;
                    break;
                }
            }

            {
                string x;
                rep(i, n - 1) {
                    x = tmp;
                    if (x[i] == '3' || x[i + 1] == '3')
                        continue;
                    swap(x[i], x[a]);
                    swap(x[i + 1], x[a + 1]);

                    ll nx = stoll(x);
                    graph[now].push_back(nx);
                    que.push(nx);
                }
            }
        }
    }

    ll start = tonum(s);
    ll goal = tonum(t);
    queue<pair<ll, ll>> que;
    que.push({start, 0});
    set<ll> visited;
    visited.insert(start);
    while (que.size()) {
        auto [now, cnt] = que.front();
        que.pop();

        for (auto nx : graph[now]) {
            if (visited.count(nx))
                continue;
            if (nx == goal) {
                cout << cnt + 1 << endl;
                return;
            }

            visited.insert(nx);
            que.push({nx, cnt + 1});
        }
    }
    cout << -1 << endl;
}
