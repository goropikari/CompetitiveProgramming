FROM julia:1.7

WORKDIR /app
COPY Project.toml /app/Project.toml

RUN julia -e 'using Pkg; Pkg.activate("."); Pkg.instantiate(); using NodeJS; run(`$(npm_cmd()) install highlight.js`)'
