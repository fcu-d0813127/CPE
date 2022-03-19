// 2022/03/19/13:59 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=e566
#include <stdio.h>
#include <stdlib.h>

void Solve(long int n, long int m) {
  size_t size = 10;
  size_t length = 0;
  int *array = malloc(size * sizeof(int));
  while (1) {
    if (n == 1 || length != 0 && array[length - 1] <= n / m || n % m != 0) {
      break;
    }
    array[length] = n;
    length++;
    if (length == size) {
      size += 10;
      array = realloc(array, size * sizeof(int));
    }
    n /= m;
  }
  if (n == 1) {
    array[length] = 1;
    length++;
    for (int i = 0; i < length; i++) {
      printf("%d", array[i]);
      if (i == length - 1) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  } else {
    printf("Boring!\n");
  }
}

int main() {
  long int m, n;
  while (scanf("%ld %ld", &n, &m) != EOF) {
    if (m == 0) {
      printf("Boring!\n");
    } else if (m == 1) {
      printf("1\n");
    } else {
      Solve(n, m);
    }
  }
  return 0;
}