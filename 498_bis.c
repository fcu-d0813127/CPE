// 2022/03/21/15:54 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=f444
// Reference: https://hackmd.io/@Inversionpeter/H1cyKHTqv
#include <stdio.h>

int main() {
  int x;
  int array[10001];
  while (scanf("%d", &x) != EOF) {
    int length = 0;
    while (1) {
      scanf("%d%*c", &array[length]);
      length++;
      char c;
      scanf("%c", &c);
      if (c != '\n') {
        ungetc(c, stdin);
      } else {
        break;
      }
    }
    int sum = 0;
    int mul = 1;
    int n = 1;
    for (int i = length - 2; i >= 0; i--) {
      sum += array[i] * mul * n;
      n++;
      mul *= x;
    }
    printf("%d\n", sum);
  }
}