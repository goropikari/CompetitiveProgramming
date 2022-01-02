# Competitive Programming

ローカルでのサイト立ち上げ方法

```bash
cd doc
docker-compose build
docker-compose up
# http://localhost:8000 にアクセス
```

検索用の index をつくるには
```julia
using Franklin
lunr()
```
として index ファイルを作る.
