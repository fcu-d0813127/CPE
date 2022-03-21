// 2022/03/21/12:19 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=e512
// Reference: https://yuihuang.com/zj-e512/
#include <stdio.h>

int main() {
  double array[8];
  while (scanf("%lf", &array[0]) != EOF) {
    for (int i = 1; i < 8; i++) {
      scanf("%lf", &array[i]);
    }
    double x[3], y[3];
    if (array[0] == array[4] && array[1] == array[5]) {
      x[0] = array[2];
      y[0] = array[3];
      x[1] = array[0];
      y[1] = array[1];
      x[2] = array[6];
      y[2] = array[7];
    } else if (array[0] == array[6] && array[1] == array[7]) {
      x[0] = array[2];
      y[0] = array[3];
      x[1] = array[0];
      y[1] = array[1];
      x[2] = array[4];
      y[2] = array[5];
    } else if (array[2] == array[4] && array[3] == array[5]) {
      x[0] = array[0];
      y[0] = array[1];
      x[1] = array[2];
      y[1] = array[3];
      x[2] = array[6];
      y[2] = array[7];
    } else if (array[2] == array[6] && array[3] == array[7]) {
      x[0] = array[0];
      y[0] = array[1];
      x[1] = array[2];
      y[1] = array[3];
      x[2] = array[4];
      y[2] = array[5];
    }
    printf("%.3lf %.3lf\n", x[2] + x[0] - x[1], y[2] + y[0] - y[1]);
  }
  return 0;
}