index = 0;
for (int i = 1; i <= m; i++) {
  int c = 1, p, h, k;
  cin >> p >> h >> k;
  while (k > c) {
	k -= c;
	list[++index].w = c * p;
	list[index].v = c * h;
    c <<= 1;
  }
  list[++index].w = k * p;
  list[index].v = k * h;
}
