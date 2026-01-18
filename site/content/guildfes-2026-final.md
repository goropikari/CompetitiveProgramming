+++
date = '2026-01-18T20:43:20+09:00'
title = 'Guildfes 2026 Final'
+++

<https://atcoder.jp/contests/abcguildfes-2026-final>

## A. EGFスワップ

<https://atcoder.jp/contests/guildfes-2026-final/tasks/guildfes_2026_final_a>

2026/1/18 自力 AC

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    string S;
    cin >> N >> S;

    swap(S[N - 2], S[N - 1]);
    cout << S << endl;
}
```

## B. EGF置換

<https://atcoder.jp/contests/guildfes-2026-final/tasks/guildfes_2026_final_b>

2026/1/18 自力 AC

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    string S;
    cin >> N >> S;
    rep(i, N) {
        if (S[i] == 'F')
            S[i] = 'G';
        else if (S[i] == 'G')
            S[i] = 'F';
    }
    cout << S << endl;
}
```

## C. EGFカウント

<https://atcoder.jp/contests/guildfes-2026-final/tasks/guildfes_2026_final_c>

2026/1/18 自力 AC

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    string S;

    cin >> N >> S;

    ll ans = 0;
    rep(i, N) rep2(j, i + 1, N) rep2(k, j + 1, N) {
        if (S[i] == 'E' && S[j] == 'G' && S[k] == 'F') ans++;
    }
    cout << ans << endl;
}
```

## D. EGFイニシャル

<https://atcoder.jp/contests/guildfes-2026-final/tasks/guildfes_2026_final_d>

2026/1/18 自力 AC

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    sort(rall(S), [](string a, string b) -> bool {
        return a.size() < b.size();
    });

    string ans = "";
    rep(i, N) {
        ans.push_back('A' + (S[i][0] - 'a'));
    }
    cout << ans << endl;
}
```

## E. EGFクエリ

<https://atcoder.jp/contests/guildfes-2026-final/tasks/guildfes_2026_final_e>

2026/1/18 自力 AC

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    deque<char> deq;
    for (char c : S) deq.push_back(c);

    rep(i, Q) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            x--;
            swap(deq[x], deq[x + 1]);
        } else {
            rep(j, x) deq.pop_front();
        }
    }

    string ans = "";
    for (char c : deq) ans.push_back(c);
    cout << ans << endl;
}
```

## F. EGFパス

<https://atcoder.jp/contests/guildfes-2026-final/tasks/guildfes_2026_final_f>

2026/1/18 自力 AC

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    vvll dist(H, vll(W, INF));
    dist[0][0] = 0;

    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};
    // i,j, dist
    using P = tuple<ll, ll, ll>;
    queue<P> que;
    que.push({0, 0, 0});
    while (que.size()) {
        auto [i, j, cost] = que.front();
        que.pop();

        if (dist[i][j] < cost) continue;

        char now = grid[i][j];
        rep(d, 4) {
            ll ni = i + di[d], nj = j + dj[d];
            if (clamp(ni, 0ll, H - 1) != ni || clamp(nj, 0ll, W - 1) != nj) continue;
            if (grid[ni][nj] == now) continue;
            if (dist[ni][nj] <= cost + 1) continue;
            dist[ni][nj] = cost + 1;
            que.push({ni, nj, cost + 1});
        }
    }

    ll ans = dist[H - 1][W - 1];
    if (ans == INF) ans = -1;
    cout << ans << endl;
}
```

## G. EGFグリッド

<https://atcoder.jp/contests/guildfes-2026-final/tasks/guildfes_2026_final_g>

2026/1/18 自力 AC したがバーチャルコンテスト中には解けなかった。

領域を下図のように3つの領域に分ける。

![grid pic](images/atcoder/guildfes_2026_final/guildfes_2026_final_g.png )

青の領域に含まれる `E` の数、緑の領域に含まれる `F` の数、赤の領域に含まれる `G` の数をそれぞれ前計算しておき、各 $(i, j)$ についてそれらの積を足し合わせればよい。

```cpp
template <typename T>
struct Cumsum2d {
    vector<vector<T>> data;

    Cumsum2d(vector<vector<T>> v) {
        assert(v.size() != 0);
        assert(v[0].size() != 0);
        int h = v.size();
        int w = v[0].size();

        data = vector<vector<T>>(h + 1, vector<T>(w + 1));

        rep(i, h) rep(j, w) {
            data[i + 1][j + 1] += data[i][j + 1] + data[i + 1][j] - data[i][j] + v[i][j];
        }
    }

    T sum(int si, int sj, int fi, int fj) {
        T ret = data[fi][fj];
        ret -= data[si][fj];
        ret -= data[fi][sj];
        ret += data[si][sj];
        return ret;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    vvll E(H, vll(W)), F(H, vll(W)), G(H, vll(W));
    rep(i, H) rep(j, W) {
        if (grid[i][j] == 'E') E[i][j] = 1;
        if (grid[i][j] == 'F') F[i][j] = 1;
        if (grid[i][j] == 'G') G[i][j] = 1;
    }

    Cumsum2d ce(E), cf(F), cg(G);

    ll ans = 0;
    rep2(i, 1, H - 1) rep2(j, 1, W - 1) {
        ans += ce.sum(0, 0, i, j) * cg.sum(i + 1, j, H, j + 1) * cf.sum(i, j + 1, i + 1, W);
    }
    cout << ans << endl;
}
```
