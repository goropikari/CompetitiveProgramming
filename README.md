# Competitive Programming

```sh
make up exec

nvim
MasonToolsInstall
```

## AtCoder の認証方式が変わって oj でログインできないときの対処法

- web で AtCoder にログインする
- inspect して `REVEL_SESSION` の値を持ってくる
- `cookie.jar` を編集する

`~/.local/share/online-judge-tools/cookie.jar`

```text
#LWP-Cookies-2.0
Set-Cookie3: REVEL_FLASH=""; path="/"; domain="atcoder.jp"; path_spec; secure; discard; HttpOnly=None; version=0
Set-Cookie3: REVEL_SESSION="<atcoder session>"; path="/"; domain="atcoder.jp"; path_spec; secure; expires="2025-09-25 17:34:35Z"; HttpOnly=None; version=0
```

```sh
chmod 600 ~/.local/share/online-judge-tools/cookie.jar
```
