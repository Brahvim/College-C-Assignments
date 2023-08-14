int main() {
  int a = 3, b = 5;
  const int t = a;  // Temporarily storing the value of `a`.

  a = b;  // Giving `a` the value of `b`.
  b = t;  // Storing the old value of `a` into `b`, which we earlier stored in `t`.

  printf("Yo! `a` is now `%d`, and `b` is now `%d`!\n", a, b);

  return 0;
}
