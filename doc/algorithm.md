+++
title = "Algorithm"
hascode = true
date = Date(2021, 12, 12)
+++
@def tags = ["algorithm"]

# Algorithm

\toc

## int <-> string

```cpp
to_string(int) -> string
to_string(ll) -> string
stoi(string) -> int
stoll(string) -> ll
```


## priority queue

昇順
```cpp
#include <iostream>
#include <queue>

int main()
{
  // intを要素に持つ優先順位付きキュー。
  // 降順に処理する
  std::priority_queue<int> que;

  // データを追加する
  que.push(3);
  que.push(1);
  que.push(4);

  // 処理順に出力する
  while (!que.empty()) {
    std::cout << que.top() << std::endl;
    que.pop();
  }
}
```

```
4
3
1
```

降順に出力
```cpp
#include <iostream>
#include <queue>

int main()
{
  // intを要素に持つ優先順位付きキュー。
  // 降順に処理する
  std::priority_queue<int, vector<int>, greater<int>> que;

  // データを追加する
  que.push(3);
  que.push(1);
  que.push(4);

  // 降順順に出力する
  while (!que.empty()) {
    std::cout << que.top() << std::endl;
    que.pop();
  }
}
```

```
1
3
4
```


## sort

自作 struct に関して sort する。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Hoge {
    int x, y;
};

bool compare(Hoge a, Hoge b) { return a.y > b.y; }

int main(int argc, char* argv[])
{
    vector<Hoge> v = { {0, 1}, {1, 9} };

    sort(v.begin(), v.end(), compare);

    for (Hoge item : v) {
        cout << item.x << " " << item.y << endl;
    }
    return 0;
}
```

```
1 9
0 1
```
## gcd, lcm

$\mathrm{gcd}(a, b) = \mathrm{gcd}(b, a \% b)$.

$\displaystyle \mathrm{lcm}(a,b) = \frac{a \times b}{\mathrm{gcd}(a,b)}$


Suppose $d = \mathrm{gcd}(a,b)$. This means $a = k_1 d$ and $b = k_2 d$ for some integers $k_1, k_2 \in \Z$.

$a = qb + r$ $(0 \leq r < b)$, for some integer $q$.

Then $a\% b = r = a - qb = d(k_1 - qk_2)$.


```cpp
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a*b) / gcd(a,b);
}
```

## cumsum

```cpp
template<typename T>
vector<T> cumsum(vector<T> v) {
    int n = v.size();
    rep2(i,1,n) v[i] += v[i-1];
    return v;
}
```
