// 2022/03/13/19:57complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=d097
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int *count = calloc(n - 1, sizeof(int));
    int previous_num;
    int flag = 0;
    for (int i = 0; i < n; i++) {
      int num;
      scanf("%d", &num);
      if (i != 0 && flag == 0) {
        int diff = abs(num - previous_num);
        if (diff >= n) {
          flag = 1;
        } else {
          count[diff - 1]++;
        }
      }
      previous_num = num;
    }
    for (int i = 0; i < n - 1; i++) {
      if (count[i] == 0) {
        flag = 1;
      }
    }
    if (flag == 1) {
      printf("Not jolly\n");
    } else {
      printf("Jolly\n");
    }
  }
  return 0;
}