// 2022/03/12/13:21 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=c045
#include <stdio.h>
#include <string.h>

int main() {
  char input[101][101];
  int line_count = 0;
  while (gets(input[line_count]) != NULL) {
    line_count++;
  }
  int max_length = 0;
  for (int i = 0; i < line_count; i++) {
    if (strlen(input[i]) > max_length) {
      max_length = strlen(input[i]);
    }
  }
  for (int i = 0; i < line_count; i++) {
    if (strlen(input[i]) < max_length) {
      int j;
      for (j = strlen(input[i]); j < max_length; j++) {
        input[i][j] = ' ';
      }
      input[i][j] = '\0';
    }
  }
  for (int i = 0; i < max_length; i++) {
    for (int j = line_count - 1; j >= 0; j--) {
      printf("%c", input[j][i]);
    }
    printf("\n");
  }
  return 0;
}