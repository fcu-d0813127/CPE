// 2022/03/20/16:18 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=d492
// Reference: https://ithelp.ithome.com.tw/articles/10273289
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char wood[1000001][31];
int wood_length = 0;

int CharCompare(const void *a, const void *b) {
  return strcmp((char*)a, (char*)b);
}

void InitWood() {
  for (int i = 0; i < 1000001; i++) {
    wood[i][0] = '\0';
  }
  wood_length = 0;
}

void Input() {
  for (int i = 0; ; i++, wood_length++) {
    gets(wood[i]);
    if (wood[i][0] == '\0') {
      break;
    }
  }
}

void Print() {
  int flag = 0;
  int count = 0;
  for (int i = 0; i < wood_length; ) {
    if (flag == 0) {
      printf("%s ", wood[i]);
      flag = 1;
      count++;
    } else {
      if (i + 1 != wood_length && strcmp(wood[i], wood[i + 1]) == 0) {
        count++;
      } else {
        printf("%.4lf\n", (double)count / wood_length * 100);
        flag = 0;
        count = 0;
      }
      i++;
    }
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d%*c%*c", &n);
  for (int i = 0; i < n; i++) {
    InitWood();
    Input();
    qsort(wood, wood_length, sizeof(wood[0]), CharCompare);
    Print();
  }
  return 0;
}