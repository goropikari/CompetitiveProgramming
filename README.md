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


neovim の設定
```
" 競技プログラミング用の設定
" :Make で今開いているファイルをコンパイルする
command! Make call Make()
function! Make()
    make test2 ARGS=%:r
endfunction
```
