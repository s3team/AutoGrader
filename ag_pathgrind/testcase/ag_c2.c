#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define ERROR(x) do { perror(x); exit(-1); } while (0);


static FILE *fp;

int main(int argc, char *argv[]) {
    //FILE *fp;
    int max, a, b, c;
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(-1);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        ERROR("fopen");
    }
    fscanf(fp, "%d", &a);
    fscanf(fp, "%d", &b);
    fscanf(fp, "%d", &c);
   
    max = max3(a, b, c);
    printf("%d\n", max);
    return 0;
}

int max3(int a, int b, int c) {
  if (a>=b && a>=c)
    return a;
  else if (b>=a && b>=c)
    return b;
  else
    return c;
}

