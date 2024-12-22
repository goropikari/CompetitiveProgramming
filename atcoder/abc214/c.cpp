// https://atcoder.jp/contest/abc214/tasks/abc214_c
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <queue>
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

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;
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

struct Person {
    int id;
    ll t;
};

bool operator>(const Person& a, const Person& b) {
    return a.t > b.t;
}

void solve() {
    int N;
    cin >> N;
    vll S(N), T(N);
    rep(i, N) cin >> S[i];
    rep(i, N) cin >> T[i];

    priority_queue<Person, vector<Person>, greater<Person>> pq;
    rep(i, N) pq.push({i, T[i]});

    vll ans(N, INF);

    while (pq.size()) {
        auto [id, t] = pq.top();
        pq.pop();

        if (ans[id] > t) {
            ans[id] = t;
            int nxid = (id + 1) % N;
            if (ans[nxid] > t + S[id])
                pq.push({nxid, t + S[id]});
        }
    }

    for (ll x : ans)
        cout << x << endl;
}

int main() {
    solve();
    return 0;
}
