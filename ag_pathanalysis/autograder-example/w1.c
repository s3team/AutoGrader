#include <stdio.h>
#include <stdlib.h>

int max3();

int main(int argc, char *argv[]) {
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int c = atoi(argv[3]);
  int res = max3(a, b, c);
  printf("%d\n",  res);
}

int max3(int a, int b, int c) {
  if (a>b && a>c)
    return a;
  else if (b>a && b>c)
    return b;
  else
    return c;
}
