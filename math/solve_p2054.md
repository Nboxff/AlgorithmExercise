思考一次洗牌后，原先在$x$位置的牌，会在什么位置，记为$f(x)$

- 当 $x \le \frac{N}{2}$, $f(x) = 2x$
- 当 $\frac{N}{2} \lt x \le N$, $f(x) = (x - \frac{N}{2}) 2 - 1 = 2x - N - 1= 2x - (N + 1)$

统一两条式子：$f(x) = 2x \mod (N + 1)$, 记$P = N + 1$

所以$m$次洗牌后， $x \cdot 2^m \equiv L (\mod P)$

所以$m$次洗牌后， $x \equiv L \cdot inv(2^m) (\mod P)$
