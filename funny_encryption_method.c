// 2022/03/13/15:44 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=e545
#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
  int length;
  int *array;
} Array;

Array DecConvertBinary(int num) {
  int size = 10;
  int length = 0;
  int *bin_array = malloc(size * sizeof(int));
  while (num != 0) {
    bin_array[length] = num % 2;
    length++;
    if (length == size) {
      size += 10;
      bin_array = realloc(bin_array, size * sizeof(int));
    }
    num /= 2;
  }
  Array array;
  array.array = realloc(bin_array, length * sizeof(int));
  array.length = length;
  return array;
}

int **HexConvertBinary(int num) {
  int hex[10][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 1},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 1, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 1, 1, 1},
    {1, 0, 0, 0},
    {1, 0, 0, 1}
  };
  int **array = malloc(4 * sizeof(int*));
  for (int i = 0; i < 4; i++) {
    array[i] = calloc(4, sizeof(int));
  }
  for (int i = 0; num != 0; i++, num /= 10) {
    int index = num % 10;
    for (int j = 0; j < 4; j++) {
      array[i][j] = hex[index][j];
    }
  }
  return array;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n;
    scanf("%d", &n);
    Array dec_array = DecConvertBinary(n);
    int **hex_array = HexConvertBinary(n);
    int b1 = 0;
    int b2 = 0;
    for (int j = 0; j < dec_array.length; j++) {
      if (dec_array.array[j] == 1) {
        b1++;
      }
    }
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (hex_array[j][k] == 1) {
          b2++;
        }
      }
    }
    printf("%d %d\n", b1, b2);
  }
  return 0;
}