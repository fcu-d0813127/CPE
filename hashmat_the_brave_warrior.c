// 2022/03/15/08:53 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=a012
#include <stdio.h>

int main() {
  unsigned long long int num1, num2;
  while (scanf("%llu %llu", &num1, &num2) != EOF) {
    printf("%llu\n", num1 > num2 ? num1 - num2 : num2 - num1);
  }
  return 0;
}