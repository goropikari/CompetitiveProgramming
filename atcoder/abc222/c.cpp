/*https://atcoder.jp/contests/abc222/tasks/abc222_c*/
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

struct Person {
    int id, win;
};

bool operator<(const Person& a, const Person& b) {
    if (a.win != b.win)
        return a.win < b.win;
    return a.id > b.id;
}

int judge(char a, char b) {
    if (a == 'G' && b == 'C')
        return -1;
    if (a == 'G' && b == 'P')
        return 1;
    if (a == 'C' && b == 'G')
        return 1;
    if (a == 'C' && b == 'P')
        return -1;
    if (a == 'P' && b == 'G')
        return -1;
    if (a == 'P' && b == 'C')
        return 1;
    return 0;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> A(2 * N);
    rep(i, 2 * N) cin >> A[i];

    priority_queue<Person> pq;
    rep(i, N * 2) pq.push({i, 0});
    rep(r, M) {
        vector<Person> v;
        rep(i, N) {
            Person first = pq.top();
            pq.pop();
            Person second = pq.top();
            pq.pop();

            char lc = A[first.id][r];
            char rc = A[second.id][r];
            int result = judge(lc, rc);
            if (result == -1) {
                first.win++;
            } else if (result == 1) {
                second.win++;
            }

            v.push_back(first);
            v.push_back(second);
        }

        for (auto x : v)
            pq.push(x);
    }

    while (pq.size()) {
        auto [id, win] = pq.top();
        pq.pop();
        // cout << id + 1 << ' ' << win << endl;
        cout << id + 1 << endl;
    }
}

int main() {
    solve();
    return 0;
}
