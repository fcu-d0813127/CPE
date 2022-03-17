// 2022/03/17/13:02 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=c012
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Array {
  int ascii;
  int count;
} Array;

int IntCompare(const void *a, const void *b) {
  if (((*(Array*)a).count) > ((*(Array*)b).count)) {
    return 1;
  } else if (((*(Array*)a).count) == ((*(Array*)b).count) &&
             ((*(Array*)a).ascii) < ((*(Array*)b).ascii)) {
    return 1;
  }
  return 0;
}

int main() {
  char line[1001];
  while (gets(line) != NULL) {
    Array *list = calloc(1001, sizeof(Array));
    int length = 0;
    for (int i = 0; i < strlen(line); i++) {
      int flag = 0;
      for (int j = 0; j < length; j++) {
        if (line[i] == list[j].ascii) {
          list[j].count++;
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        list[length].ascii = line[i];
        list[length].count++;
        length++;
      }
    }
    qsort(list, length, sizeof(Array), IntCompare);
    for (int i = 0; i < length; i++) {
      printf("%d %d\n", list[i].ascii, list[i].count);
    }
  }
  return 0;
}