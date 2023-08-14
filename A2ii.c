int main(int argc, char const *argv[]) {
  int a = 3, b = 5;

  a += b;
  b = a - b;
  a -= b;

  return 0;
}
