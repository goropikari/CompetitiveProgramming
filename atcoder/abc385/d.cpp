// https://atcoder.jp/contests/abc385/tasks/abc385_d
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

struct Segment {
    ll start, fin;
};

bool operator<(const Segment& a, const Segment& b) {
    return a.start < b.start;
}

bool search(ll target, vector<Segment>& segs) {
    for (auto seg : segs) {
        if (seg.start <= target && target <= seg.fin) {
            return true;
        }
    }

    return false;
}

void solve() {
    ll N, M, Sx, Sy;
    cin >> N >> M >> Sx >> Sy;
    vll X(N), Y(N), C(M);
    vector<char> D(M);
    rep(i, N) cin >> X[i] >> Y[i];
    rep(i, M) cin >> D[i] >> C[i];

    map<ll, deque<Segment>> xm, ym;
    map<ll, vector<Segment>> segx, segy;

    ll nx, ny;
    rep(i, M) {
        if (D[i] == 'U') {
            nx = Sx;
            ny = Sy + C[i];
        } else if (D[i] == 'D') {
            nx = Sx;
            ny = Sy - C[i];
        } else if (D[i] == 'L') {
            nx = Sx - C[i];
            ny = Sy;
        } else {  // R
            nx = Sx + C[i];
            ny = Sy;
        }

        ll sx = Sx, sy = Sy, fx = nx, fy = ny;
        if (sx == fx) {
            if (sy < fy)
                xm[sx].push_back({sy, fy});
            else
                xm[sx].push_back({fy, sy});
        } else {
            if (sx < fx)
                ym[sy].push_back({sx, fx});
            else
                ym[sy].push_back({fx, sx});
        }
        Sx = nx, Sy = ny;
    }

    for (auto it = xm.begin(); it != xm.end(); it++) {
        auto que = it->second;
        ll posx = it->first;
        sort(all(que));
        while (que.size()) {
            auto top = que.front();
            que.pop_front();
            if (segx[posx].size() == 0) {
                segx[posx].push_back(top);
                continue;
            }

            auto prev = segx[posx].back();
            if (prev.fin < top.start) {
                segx[posx].push_back(top);
            } else {
                segx[posx].pop_back();
                segx[posx].push_back({prev.start, max(prev.fin, top.fin)});
            }
        }
    }
    for (auto it = ym.begin(); it != ym.end(); it++) {
        auto que = it->second;
        ll posy = it->first;
        sort(all(que));
        while (que.size()) {
            auto top = que.front();
            que.pop_front();
            if (segy[posy].size() == 0) {
                segy[posy].push_back(top);
                continue;
            }

            auto prev = segy[posy].back();
            if (prev.fin < top.start) {
                segy[posy].push_back(top);
            } else {
                segy[posy].pop_back();
                segy[posy].push_back({prev.start, max(prev.fin, top.fin)});
            }
        }
    }

    int ans = 0;
    rep(i, N) {
        bool isin = false;
        isin = isin || search(Y[i], segx[X[i]]);
        isin = isin || search(X[i], segy[Y[i]]);
        if (isin)
            ans++;
    }

    cout << nx << ' ' << ny << ' ' << ans << endl;
}

int main() {
    solve();
    return 0;
}
