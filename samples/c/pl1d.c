//複数引数用のテストが配布プログラムになかったので作った

#include <stdio.h>

int n, temp;

void fact(int n, int m) {
  int k, l;
  k = 0;
  l = 2;
  if (n <= 1) {
    temp = 1;
  } else {
    fact(n - 1, m + k + l);
    temp = temp * n;
  }
  return;
}

void test() {
  int k;
  k = 0;
  k = k + 1;
  return;
}

int main() {
  scanf("%d\n", &n);
  fact(n, 1);
  test();
  printf("%d\n", temp);
  return 0;
}