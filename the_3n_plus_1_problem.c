// 2022/03/11/10:34 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=c039
#include <stdio.h>

void SimpleSort(int *num1, int *num2) {
  if (*num1 > *num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
  }
}

int CalculateCycleLength(int num) {
  int cycle_length = 0;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    cycle_length++;  // not include 1
  }
  cycle_length++;
  return cycle_length;
}

int main() {
  while (1) {
    int num1;
    int num2;
    int origin_num1;
    int origin_num2;
    int max_cycle_length = 0;
    int status = scanf("%d %d", &num1, &num2);
    if (status == EOF) {
      break;
    }
    origin_num1 = num1;
    origin_num2 = num2;
    SimpleSort(&num1, &num2);
    for (int i = num1; i <= num2; i++) {
      int cycle_length = CalculateCycleLength(i);
      if (cycle_length > max_cycle_length) {
        max_cycle_length = cycle_length;
      }
    }
    printf("%d %d %d\n", origin_num1, origin_num2, max_cycle_length);
  }
  return 0;
}