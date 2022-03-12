// 2022/03/12/13:53 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=e561
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int l;
    scanf("%d", &l);
    int *train_array = malloc(l * sizeof(int));
    for (int j = 0; j < l; j++) {
      scanf("%d", &train_array[j]);
    }
    int change_count = 0;
    for (int j = l - 1; j > 0; j--) {
      for (int k = 0; k < j; k++) {
        if (train_array[k] > train_array[k + 1]) {
          int tmp = train_array[k];
          train_array[k] = train_array[k + 1];
          train_array[k + 1] = tmp;
          change_count++;
        }
      }
    }
    printf("Optimal train swapping takes %d swaps.\n", change_count);
  }
  return 0;
}