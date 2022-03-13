// 2022/03/13/14:42 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=c044
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TableList {
  char alphabet;
  int count;
} TableList;

char *GetLine() {
  size_t size = 50;
  size_t line_length = 0;
  char c;
  char *line = malloc(size * sizeof(char));
  while (1) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    line[line_length] = c;
    line_length++;
    if (line_length == size) {
      size += 50;
      line = realloc(line, size * sizeof(char));
    }
  }
  line[line_length] = '\0';
  line_length++;
  return realloc(line, line_length * sizeof(char));
}

TableList *init() {
  TableList *list = malloc(26 * sizeof(TableList));
  for (int i = 0, c = 'A'; i < 26; i++, c++) {
    list[i].alphabet = c;
    list[i].count = 0;
  }
  return list;
}

int main() {
  int n;
  char big_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char small_table[] = "abcdefghijklmnopqrstuvwxyz";
  TableList *list = init();
  scanf("%d%*c", &n);
  for (int i = 0; i < n; i++) {
    char *line = GetLine();
    for (int j = 0; j < strlen(line); j++) {
      if (line[j] < 'A' || line[j] > 'Z' &&
          line[j] < 'a' || line[j] > 'z') {
        continue;
      }
      int index;
      for (int k = 0; k < 26; k++) {
        if (big_table[k] == line[j] || small_table[k] == line[j]) {
          index = k;
        }
      }
      list[index].count++;
    }
  }
  for (int i = 25; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (list[j].count < list[j + 1].count ||
          list[j].count == list[j + 1].count &&
          list[j].alphabet > list[j + 1].alphabet) {
        TableList tmp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = tmp;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    if (list[i].count == 0) {
      break;
    }
    printf("%c %d\n", list[i].alphabet, list[i].count);
  }
  return 0;
}