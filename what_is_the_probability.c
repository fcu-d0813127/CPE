// 2022/03/15/09:22 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=e510
// Reference: https://awesq123.pixnet.net/blog/post/103273280-uva10056---what-is-the-probability-%28cpe%E4%B8%80%E9%A1%86%E6%98%9F%E9%81%B8%E9%9B%86%29
#include <stdio.h>
#include <math.h>
#define ACCURACY 100000  /* Definable, this value needs to be large enough. */

int main() {
  int s;
  scanf("%d", &s);
  for (int i = 0; i < s; i++) {
    int n, l;
    double p;
    scanf("%d %lf %d", &n, &p, &l);
    double q = 1 - p;
    double first_term = pow(q, l - 1) * p;
    double common_ratio = pow(q, n);
    if (common_ratio == 1) {
      printf("0.0000\n");
      continue;
    }
    printf("%.4lf\n", first_term * (1 - pow(common_ratio, ACCURACY)) / (1 - common_ratio));
  }
  return 0;
}