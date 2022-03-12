// 2022/03/12/20:05 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=a134
#include <stdio.h>
#include <stdlib.h>

typedef struct Fibonacci {
  int length;
  int *array;
} Fibonacci;

Fibonacci CreateFibonacci(int num) {
  int size = 10;
  int length = 2;
  int *array = malloc(size * sizeof(int));
  array[0] = 0;
  array[1] = 1;
  while (1) {
    array[length] = array[length - 1] + array[length - 2];
    if (array[length] > num) {
      break;
    }
    length++;
    if (length == size) {
      size += 10;
      array = realloc(array, size * sizeof(int));
    }
  }
  Fibonacci fib;
  fib.array = realloc(array, length * sizeof(int));
  fib.length = length;
  return fib;
}

Fibonacci FindFibonaccimalBase(Fibonacci fib, int num) {
  Fibonacci fib_bit;
  fib_bit.length = fib.length - 2;  // 0, 1 are excluded.
  fib_bit.array = malloc(fib_bit.length * sizeof(int));
  int bit_count = 0;
  int sum = 0;
  int i = fib.length - 1;
  while (1) {
    sum = fib.array[i];
    fib_bit.array[bit_count] = 1;
    bit_count++;
    // j > 1, 0, 1 are excluded.
    for (int j = i - 1; j > 1; j--, bit_count++) {
      if (sum + fib.array[j] <= num && fib_bit.array[bit_count - 1] != 1) {
        sum += fib.array[j];
        fib_bit.array[bit_count] = 1;
      } else {
        fib_bit.array[bit_count] = 0;
      }
    }
    if (sum == num) {
      break;
    } else {
      bit_count = fib.length - i;
      i--;
    }
  }
  return fib_bit;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    Fibonacci fib = CreateFibonacci(num);
    Fibonacci fib_bit = FindFibonaccimalBase(fib, num);
    printf("%d = ", num);
    for (int j = 0; j < fib_bit.length; j++) {
      printf("%d", fib_bit.array[j]);
    }
    printf(" (fib)\n");
  }
  return 0;
}