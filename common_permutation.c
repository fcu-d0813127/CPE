// 2022/03/21/13:15 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=e507
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CharCompare(const void *a, const void *b) {
  return *((char*)a) > *((char*)b);
}

int main() {
  char str1[1001], str2[1001];
  while (scanf("%1001s%*c%1001s%*c", str1, str2) != EOF) {
    char same[1001];
    int same_length = 0;
    for (int i = 0; i < strlen(str1); i++) {
      for (int j = 0; j < strlen(str2); j++) {
        if (str1[i] == str2[j]) {
          str2[j] = ' ';
          same[same_length] = str1[i];
          same_length++;
          break;
        }
      }
    }
    qsort(same, same_length, sizeof(same[0]), CharCompare);
    for (int i = 0; i < same_length; i++) {
      printf("%c", same[i]);
    }
    printf("\n");
  }
  return 0;
}