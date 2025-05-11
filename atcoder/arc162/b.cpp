// https://atcoder.jp/contests/arc162/tasks/arc162_b
// 2025年05月12日 00時42分57秒
#include <bits/stdc++.h>
#include <atcoder/all>
#include <atcoder/fenwicktree.hpp>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

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
    vint P(N);
    rep(i, N) {
        cin >> P[i];
        P[i]--;
    }

    {
        vector<pair<int, int>> ids;
        rep(i, N) {
            ids.emplace_back(P[i], i);
        }
        sort(all(ids));
        fenwick_tree<int> fw(N);
        int tento = 0;
        for (auto [_, i] : ids) {
            tento += fw.sum(i, N);
            fw.add(i, 1);
        }
        if (tento % 2 == 1) {
            yesno(false);
            return;
        }
    }

    vector<pair<int, int>> histories;
    int cnt = 0;
    int nx = 0;
    int sorted_pos = -1;
    while (true) {
        if (is_sorted(all(P)))
            break;
        cnt++;
        int pos = distance(P.begin(), find(all(P), nx));
        if (pos < N - 1) {
            sorted_pos++;
            histories.emplace_back(pos + 1, sorted_pos);

            vint tmpP;
            rep(i, sorted_pos) {
                tmpP.push_back(P[i]);
            }
            tmpP.push_back(P[pos]);
            tmpP.push_back(P[pos + 1]);
            rep2(i, sorted_pos, N) {
                if (i == pos || i == pos + 1)
                    continue;
                tmpP.push_back(P[i]);
            }
            nx++;
            swap(tmpP, P);
        } else {
            vint tmpP;
            pos -= 2;
            rep(i, N) {
                if (i == pos || i == pos + 1)
                    continue;
                tmpP.push_back(P[i]);
            }
            tmpP.push_back(P[pos]);
            tmpP.push_back(P[pos + 1]);
            histories.emplace_back(pos + 1, N - 2);
            swap(tmpP, P);
        }
    }

    yesno(true);
    cout << cnt << endl;
    for (auto [i, j] : histories)
        cout << i << ' ' << j << endl;
}
