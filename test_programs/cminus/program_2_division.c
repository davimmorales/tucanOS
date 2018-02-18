#include "stdio.h"

int main(int argc, char const *argv[]) {
  int a;
  int b;
  int c;
  c = 0;
  scanf("%d", &a);
  scanf("%d", &b);
  while (b<a+1) {
    a = a - b;
    c = c + 1;
  }
  printf("%d\n", c);
  return 0;
}
