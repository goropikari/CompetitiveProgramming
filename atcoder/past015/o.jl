# https://atcoder.jp/contests/past15-open/tasks/past202306_o
# 2025年04月15日 08時40分25秒
using Primes

function f()
    n,a,b = parse.(Int, split(readline()))
    cnt = 0
    for i in 1:n
        if isprime(a*(i-1) + b)
            cnt += 1
        end
    end
    return cnt
end
println(f())
