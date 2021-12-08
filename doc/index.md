+++
title = "ABC 230"
hascode = true
date = Date(2021, 12, 4)
+++
@def title = "Competitive Programming"
@def tags = ["syntax", "code"]

# Tips

\tableofcontents <!-- you can use \toc as well -->


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


