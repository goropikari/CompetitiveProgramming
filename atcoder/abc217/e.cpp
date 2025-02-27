/*https://atcoder.jp/contests/abc217/tasks/abc217_e*/
/*2025年02月27日 03時07分18秒*/
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
    int q;
    cin >> q;

    multiset<int> s;
    deque<int> deq;

    rep(_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            deq.push_back(x);
        } else if (t == 2) {
            int x;
            if (s.size()) {
                auto it = s.begin();
                x = *it;
                s.erase(it);
            } else {
                x = deq.front();
                deq.pop_front();
            }
            cout << x << endl;
        } else {
            for (auto x : deq)
                s.insert(x);
            deq = deque<int>();
        }
    }
}
