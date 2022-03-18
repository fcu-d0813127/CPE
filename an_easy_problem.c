// 2022/03/18/14:25 complete
// CPE question url: https://vjudge.net/problem/UVA-10093
// Reference: https://yuihuang.com/uva-10093/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *GetLine() {
  size_t size = 10;
  size_t line_length = 0;
  char c;
  char *line = malloc(size * sizeof(char));
  while (scanf("%c", &c) != EOF) {
    if (c == '\n') {
      break;
    }
    line[line_length] = c;
    line_length++;
    if (line_length == size) {
      size += 10;
      line = realloc(line, size * sizeof(char));
    }
  }
  if (line_length == 0) {
    return NULL;
  }
  line[line_length] = '\0';
  line_length++;
  return realloc(line, line_length * sizeof(char));
}

int main() {
  while (1) {
    char *line = GetLine();
    if (line == NULL) {
      break;
    }
    int sum = 0;
    int mx = 1;
    for (int i = 0; i < strlen(line); i++) {
      int tmp;
      if (line[i] >= '0' && line[i] <= '9') {
        tmp = line[i] - '0';
      } else if (line[i] >= 'A' && line[i] <= 'Z') {
        tmp = line[i] - 'A' + 10;
      } else if (line[i] >= 'a' && line[i] <= 'z') {
        tmp = line[i] - 'a' + 36;
      } else {
        continue;
      }
      if (mx < tmp) {
        mx = tmp;
      }
      sum += tmp;
    }
    int i;
    for (i = mx; i < 62; i++) {
      if (sum % i == 0) {
        printf("%d\n", i + 1);
        break;
      }
    }
    if (i == 62) {
      printf("such number is impossible!\n");
    }
  }
  return 0;
}