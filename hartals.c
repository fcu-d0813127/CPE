// 2022/03/14/19:21 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=e579
#include <stdio.h>
#include <stdlib.h>

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n;
    scanf("%d", &n);
    int p;
    scanf("%d", &p);
    int *h = malloc(p * sizeof(int));
    for (int j = 0; j < p; j++) {
      scanf("%d", &h[j]);
    }
    int *hartal_flag = calloc(n + 1, sizeof(int));
    for (int j = 0; j < p; j++) {
      for (int k = h[j]; k <= n; k += h[j]) {
        hartal_flag[k] = 1;
      }
    }
    int hartal_count = 0;
    for (int j = 0; j <= n; j++) {
      if (j % 7 == 0 || j % 7 == 6) {
        continue;
      }
      if (hartal_flag[j] == 1) {
        hartal_count++;
      }
    }
    printf("%d\n", hartal_count);
  }
  return 0;
}