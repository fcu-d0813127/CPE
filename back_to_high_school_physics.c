// 2022/03/17/15:42 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=d226
// Reference: https://zerojudge.tw/ShowThread?postid=21145&reply=0
#include <stdio.h>

int main() {
  int v, t;
  while (scanf("%d %d", &v, &t) != EOF) {
    printf("%d\n", 2 * v * t);
  }
  return 0;
}