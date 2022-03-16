// 2022/03/16/19:55 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=e606
// Reference: https://yuihuang.com/zj-e606/
// qsort reference: https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/460267/
#include <stdio.h>
#include <stdlib.h>

int IntCompare(const void *a, const void *b) {
  return *((int*)a) > *((int*)b);
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int *array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
      scanf("%d", &array[i]);
    }
    qsort(array, n, sizeof(int), IntCompare);
    int mid1 = array[(n - 1) / 2];
    int mid2 = array[n / 2];
    int min_count = 0;
    for (int i = 0; i < n; i++) {
      if (array[i] == mid1 || array[i] == mid2) {
        min_count++;
      }
    }
    printf("%d %d %d\n", mid1, min_count, mid2 - mid1 + 1);
  }
  return 0;
}