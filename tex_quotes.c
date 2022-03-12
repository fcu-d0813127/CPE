// 2022/03/12/12:28 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=c007
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

char *GetLine() {
  size_t size = 50;
  size_t line_length = 0;
  char c;
  char *line = malloc(size * sizeof(char));
  while (scanf("%c", &c) != EOF) {
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

void Convert(char *line) {
  int is_first_quote = TRUE;
  for (int i = 0; i < strlen(line); i++) {
    if (line[i] == '"' && is_first_quote == TRUE) {
      printf("``");
      is_first_quote = FALSE;
    } else if (line[i] == '"' && is_first_quote == FALSE) {
      printf("''");
      is_first_quote = TRUE;
    } else {
      printf("%c", line[i]);
    }
  }
}

int main() {
  char *line = GetLine();
  Convert(line);
  return 0;
}