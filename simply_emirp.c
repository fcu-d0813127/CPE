// 2022/03/21/11:34 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=d387
#include <stdio.h>

int Reverse(int n) {
  int reverse_n = 0;
  while (n != 0) {
    int a = n % 10;
    reverse_n = reverse_n * 10 + a;
    n /= 10;
  }
  return reverse_n;
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int reverse_n = Reverse(n);
    int prime_flag = 0;
    int emirp_flag = 0;
    for (int i = 2; i <= n / 2; i++) {
      if (n % i == 0) {
        prime_flag = 1;
        break;
      }
    }
    if (n != reverse_n) {
      for (int i = 2; i <= reverse_n / 2; i++) {
        if (reverse_n % i == 0) {
          emirp_flag = 1;
          break;
        }
      }
    } else {
      emirp_flag = 1;
    }
    printf("%d is ", n);
    if (emirp_flag == 0 && prime_flag == 0) {
      printf("emirp.");
    } else if (prime_flag == 0) {
      printf("prime.");
    } else {
      printf("not prime.");
    }
    printf("\n");
  }
  return 0;
}