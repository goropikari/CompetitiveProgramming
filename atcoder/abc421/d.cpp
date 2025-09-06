// https://atcoder.jp/contests/abc421/tasks/abc421_d
// 2025年09月06日 13時33分56秒
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

// const ll INF = (ll)2e18+9;
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll rt, ct, ra, ca;
    cin >> rt >> ct >> ra >> ca;

    ll N, M, L;
    cin >> N >> M >> L;
    using P = pair<char, ll>;
    deque<P> S, T;
    rep(i, M) {
        char c;
        ll x;
        cin >> c >> x;
        S.push_back({c, x});
    }
    rep(i, L) {
        char c;
        ll x;
        cin >> c >> x;
        T.push_back({c, x});
    }

    auto same_pos = [&]() -> bool {
        return rt == ra && ct == ca;
    };

    // rt + x*nrt = ra + x*nra => x = (ra - rt) / (nrt - nra)
    // ct + x*nct = ca + x*nca => x = (ca - ct) / (nct - nca)

    map<char, pair<ll, ll>> dir;
    dir['U'] = {-1, 0};
    dir['D'] = {1, 0};
    dir['R'] = {0, 1};
    dir['L'] = {0, -1};

    ll ans = 0;
    while (N) {
        auto [dt, nt] = S.front();
        auto [da, na] = T.front();

        ll advance = min(nt, na);
        if (dt == da) {
            if (same_pos()) {
                ans += advance;
            }
        } else {
            auto [nrt, nct] = dir[dt];
            auto [nra, nca] = dir[da];

            if (nrt - nra == 0) {  // 左右
                ll x = (ca - ct) / (nct - nca);
                if (rt == ra && (ca - ct) % (nct - nca) == 0 && 0 < x && x <= advance) ans++;
            } else if (nct - nca == 0) {  // 上下
                ll x = (ra - rt) / (nrt - nra);
                if (ct == ca && (ra - rt) % (nrt - nra) == 0 && 0 < x && x <= advance) ans++;
            } else {
                ll lx = (ra - rt) / (nrt - nra);
                ll rx = (ca - ct) / (nct - nca);

                if (lx == rx && (ra - rt) % (nrt - nra) == 0 && (ca - ct) % (nct - nca) == 0 && 0 < lx && lx <= advance) ans++;
            }
        }

        {
            auto [nr, nc] = dir[dt];
            rt += nr * advance;
            ct += nc * advance;
        }
        {
            auto [nr, nc] = dir[da];
            ra += nr * advance;
            ca += nc * advance;
        }

        S.front().second -= advance;
        T.front().second -= advance;
        if (S.front().second == 0) {
            S.pop_front();
        }
        if (T.front().second == 0) {
            T.pop_front();
        }

        N -= advance;
    }

    cout << ans << endl;
}
