// 2022/03/20/14:15 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=e578
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char c;
  char table[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
  while (scanf("%c", &c) != EOF) {
    if (c == ' ' || c == '\n') {
      printf("%c", c);
    } else {
      for (int i = 2; i < strlen(table); i++) {
        if (c == table[i]) {
          printf("%c", table[i - 2]);
        }
      }
    }
  }
  return 0;
}