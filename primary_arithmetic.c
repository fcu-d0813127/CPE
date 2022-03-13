// 2022/03/13/16:40 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=c014
#include <stdio.h>
#include <stdlib.h>

int NumToArray(int num1, int num2, int **array1, int **array2) {
  int i = 0;
  while (num1 > 0 || num2 > 0) {
    if (num1 > 0) {
      (*array1)[i] = num1 % 10;
      num1 /= 10;
    } else {
      (*array1)[i] = 0;
    }
    if (num2 > 0) {
      (*array2)[i] = num2 % 10;
      num2 /= 10;
    } else {
      (*array2)[i] = 0;
    }
    i++;
  }
  return i;
}

int main() {
  while (1) {
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    if (num1 == 0 && num2 == 0) {
      break;
    }
    int *array1 = malloc(11 * sizeof(int));
    int *array2 = malloc(11 * sizeof(int));
    int max_length = NumToArray(num1, num2, &array1, &array2);
    int carry = 0;
    int carry_count = 0;
    for (int i = 0; i < max_length; i++) {
      if (array1[i] + array2[i] + carry >= 10) {
        carry_count++;
        carry = 1;
      } else {
        carry = 0;
      }
    }
    if (carry_count < 2) {
      printf("%s carry operation.\n", carry_count ? "1" : "No");
    } else {
      printf("%d carry operations.\n", carry_count);
    }
  }
  return 0;
}