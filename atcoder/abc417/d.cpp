// https://atcoder.jp/contests/abc417/tasks/abc417_d
// 2025年08月02日 21時24分21秒
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
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

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
}

void solve();

int main() {
    solve();
    return 0;
}

template <typename T>
struct Cumsum {
    vector<T> data;

    Cumsum(vector<T> v) {
        int n = v.size();
        data.resize(n + 1);

        data[0] = 1;
        rep(i, n) {
            data[i + 1] = data[i] + v[i];
        }
    }

    // sum of range [l,r)
    ll sum(int l, int r) {
        return data[r] - data[l];
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<tuple<ll, ll, ll>> ps;
    rep(i, N) {
        ll p, a, b;
        cin >> p >> a >> b;
        ps.push_back({p, a, b});
    }

    ll Q;
    cin >> Q;
    vll xs(Q);
    rep(i, Q) cin >> xs[i];

    vll uppers(N);

    rep(i, N) {
        ll ac = INF, wa = -1;
        while (ac - wa > 1) {
            ll wj = (ac + wa) / 2;
            ll x = wj;
            int cnt = 0;
            rep2(j, i, N) {
                auto [p, a, b] = ps[j];
                if (x <= p)
                    x += a;
                else {
                    x -= b;
                    cnt++;
                    chmax(x, 0ll);
                }
            }

            if (cnt == N - i) {
                ac = wj;
            } else {
                wa = wj;
            }
        }
        uppers[i] = ac;
    }

    vll bs;
    for (auto [p, a, b] : ps) bs.push_back(b);
    Cumsum bcumsum(bs);

    vector<map<ll, ll>> mp(N);
    auto f = [&](auto f, ll x, ll depth) -> ll {
        if (depth == N) return x;
        if (mp[depth].count(x)) return mp[depth][x];

        if (x >= uppers[depth]) return mp[depth][x] = max(x - bcumsum.sum(depth, N), 0ll);

        auto [p, a, b] = ps[depth];
        ll t = x;
        if (t <= p)
            t += a;
        else
            t -= b;
        chmax(t, 0ll);
        return mp[depth][x] = f(f, t, depth + 1);
    };

    ll bsum = bcumsum.sum(0, N);
    rep(i, uppers[0])
        f(f, i, 0);
    for (ll x : xs) {
        ll ans = x;
        if (x >= uppers[0])
            ans -= bsum;
        else
            ans = mp[0][x];
        cout << ans << endl;
    }
}
