```bash
# https://gohugo.io/installation/linux/
CGO_ENABLED=1 go install -tags extended github.com/gohugoio/hugo@latest

npm install markdownlint-cli2 --global
cargo install cbfmt
sudo apt install -y clang-format

.devcontainer/start.sh
hugo server --bind 0.0.0.0 --port 1313
```

<http://localhost:1313/CompetitiveProgramming>
