+++
title = "Tips"
date = "2021-12-12"
tags = ["algorithm", "cpp"]
+++

# Performance

## multiset vs vector

multiset は遅いので二部探索のように使うときは注意する.
insert, find, erase の計算量は $\log(N)$ ($N$ は要素数)であるが, 定数項が効いているのかなかなかに遅い.


```cpp
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,k,n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
// using P = pair<ll,ll>;

const ll INF = (ll)1e18;
// const int INF = (int)1e9+7;
template<typename T>
void chmin(T &a, T b) { a = min(a, b); }
template<typename T>
void chmax(T &a, T b) { a = max(a, b); }

void solve() {
    int ns[] = {100, 1000, 10000, 100000, 1000000, 10000000};
    cout << "multiset" << endl;
    cout << "size\telapsed time (sec)" << endl;
    for (int n : ns) {
        multiset<int> ms;
        clock_t start = clock();
        rep(i,n) ms.insert(i);
        clock_t end = clock();
        cout << n << "\t" << (double)(end - start) / CLOCKS_PER_SEC << endl;
    }

    cout << endl;
    cout << "vector" << endl;
    cout << "size\telapsed time (sec)" << endl;
    for (int n : ns) {
        vector<int> v(n);
        clock_t start = clock();
        rep(i,n) v[i] = i;
        sort(all(v));
        clock_t end = clock();
        cout << n << "\t" << (double)(end - start) / CLOCKS_PER_SEC << endl;
    }
}

int main() {
    solve();
    return 0;
}
```

```
multiset
size    elapsed time (sec)
100     9e-06
1000    6.4e-05
10000   0.000915
100000  0.011328
1000000 0.144224
10000000        2.5446

vector
size    elapsed time (sec)
100     5e-06
1000    1e-05
10000   7.5e-05
100000  0.000858
1000000 0.010139
10000000        0.130072
```

![multiset_vs_vector](/images/tips/multiset_vs_vector.png)
