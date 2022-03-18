// 2022/03/18/15:58 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=a741
// Reference: https://yuihuang.com/zj-a741/
#include <stdio.h>
#include <stdlib.h>

char bangla_numbers[4][6] = {"kuti", "lakh", "hajar", "shata"};
int split_numbers[4] = {10000000, 100000, 1000, 100};

void Solve(long long int num) {
  if (num >= split_numbers[0]) {
    Solve(num / split_numbers[0]);
    printf(" %s", bangla_numbers[0]);
    num %= split_numbers[0];
  }
  for (int i = 0; i < 4; i++) {
    if (num / split_numbers[i] > 0) {
      printf(" %lld %s", num / split_numbers[i], bangla_numbers[i]);
      num %= split_numbers[i];
    }
  }
  if (num > 0) {
    printf(" %lld", num);
  }
}

int main() {
  long long int line;
  int count = 1;
  while (scanf("%lld", &line) != EOF) {
    printf("   %d.", count);
    count++;
    if (line == 0) {
      printf(" 0\n");
    } else {
      Solve(line);
      printf("\n");
    }
  }
  return 0;
}