int main() {
  int a = 3, b = 5;
  const int t = a;  // Temporarily storing the value of `a`.

  a = b;  // Giving `a` the value of `b`.
  b = t;  // Storing the old value of `a` into `b`, which we earlier stored in `t`.

  return 0;
}
