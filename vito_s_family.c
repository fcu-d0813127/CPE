// 2022/03/13/21:05 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=a737
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int r;
    scanf("%d", &r);
    int *s = malloc(r * sizeof(int));
    for (int j = 0; j < r; j++) {
      scanf("%d", &s[j]);
    }
    for (int j = r - 1; j > 0; j--) {
      for (int k = 0; k < j; k++) {
        if (s[k] > s[k + 1]) {
          int tmp = s[k];
          s[k] = s[k + 1];
          s[k + 1] = tmp;
        }
      }
    }
    // Hint: Add multiple absolute values,
    // the smallest value appears at the median of the sorted sequence.
    int mid;
    if (r % 2 == 0) {
      mid = (s[r / 2 - 1] + s[r / 2]) / 2;
    } else {
      mid = s[r / 2];
    }
    int total_length = 0;
    for (int j = 0; j < r; j++) {
      total_length += abs(mid - s[j]);
    }
    printf("%d\n", total_length);
  }
  return 0;
}