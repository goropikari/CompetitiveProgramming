// https://atcoder.jp/contests/math-and-algorithm/tasks/typical90_j
/*2025年01月16日 21時57分25秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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

struct Student {
    ll id, score;
};

bool operator<(const Student& a, const Student& other) {
    return a.id < other.id;
}

void solve() {
    ll N;
    cin >> N;
    vector<vector<Student>> scores(2);
    rep(i, N) {
        ll c, p;
        cin >> c >> p;
        c--;
        scores[c].push_back({i, p});
    }

    vvll cumsum(2, vll(1, 0));
    rep(i, 2) {
        ll size = scores[i].size();
        rep(j, size) {
            cumsum[i].push_back(scores[i][j].score);
            cumsum[i][j + 1] += cumsum[i][j];
        }
    }

    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll l, r;
        cin >> l >> r;
        l--, r--;

        vll ans;
        rep(k, 2) {
            auto lit = lower_bound(all(scores[k]), Student({l, -1}));
            auto rit = upper_bound(all(scores[k]), Student({r, INF}));

            int lid = distance(scores[k].begin(), lit);
            int rid = distance(scores[k].begin(), rit);
            ans.push_back(cumsum[k][rid] - cumsum[k][lid]);
        }
        print(ans);
    }
}
