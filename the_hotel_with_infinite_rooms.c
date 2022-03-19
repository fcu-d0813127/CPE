// 2022/03/19/12:49 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=e555
#include <stdio.h>

int main() {
  int s;
  long long int d;
  while (scanf("%d %lld", &s, &d) != EOF) {
    long long int sum = s;
    while (sum < d) {
      s++;
      sum += s;
    }
    printf("%d\n", s);
  }
  return 0;
}