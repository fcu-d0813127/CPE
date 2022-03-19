// 2022/03/19/15:04 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=d306
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *GetLine() {
  size_t size = 10;
  size_t length = 0;
  char *line = malloc(size * sizeof(char));
  while (1) {
    int c;
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    line[length] = c;
    length++;
    if (length == size) {
      size += 10;
      line = realloc(line, size * sizeof(char));
    }
  }
  line[length] = '\0';
  length++;
  return realloc(line, length * sizeof(char));
}

char *Reverse(char *string) {
  int length = strlen(string) + 1;
  char *str = malloc(length * sizeof(char));
  int i = 0;
  for (int j = length - 2; j >= 0; i++, j--) {
    str[j] = string[i];
  }
  str[i] = '\0';
  return str;
}

int BinaryToDecimal(char *string) {
  char *str = Reverse(string);
  int sum = 0;
  int base = 1;
  for (int i = 0; i < strlen(str); i++) {
    int num = base * (str[i] - '0');
    sum += num;
    base = base << 1;
  }
  return sum;
}

// 輾轉相除法
int EuclideanAlgorithm(int a, int b) {
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

// 找出最大公因數
void Solve(int num1, int num2, int *count) {
  int a = EuclideanAlgorithm(num1, num2);
  printf("Pair #%d: ", *count);
  if (a == 1) {
    printf("Love is not all you need!\n");
  } else {
    printf("All you need is love!\n");
  }
  (*count)++;
}

int main() {
  int n;
  int count = 1;
  while (scanf("%d%*c", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      char *s1 = GetLine();
      char *s2 = GetLine();
      int num1 = BinaryToDecimal(s1);
      int num2 = BinaryToDecimal(s2);
      Solve(num1, num2, &count);
    }
  }
  return 0;
}