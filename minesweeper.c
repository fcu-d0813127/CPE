// 2022/03/19/13:35 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=e605
// Reference: https://yuihuang.com/zj-e605/
#include <stdio.h>
#include <stdlib.h>

char **CreateMap(int n, int m) {
  char **map = malloc(n * sizeof(char*));
  for (int i = 0; i < n; i++) {
    map[i] = malloc(m * sizeof(char));
  }
  return map;
}

char **InputMap(int n, int m) {
  char **map = CreateMap(n, m);
  for (int i = 0; i < n; i++) {
    getchar();
    for (int j = 0; j < m; j++) {
      scanf("%c", &map[i][j]);
    }
  }
  return map;
}

char **AnswerMap(int n, int m) {
  char **field = CreateMap(n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      field[i][j] = '0';
    }
  }
  return field;
}

void PrintAnswerMap(int n, int m, int *count, char **field) {
  printf("Field #%d:\n", *count);
  (*count)++;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%c", field[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
  int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
  int count = 1;

  while (1) {
    int m, n;
    scanf("%d %d", &n, &m);
    if (m == 0 && n == 0) {
      break;
    }
    char **map = InputMap(n, m);
    char **field = AnswerMap(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map[i][j] == '*') {
          field[i][j] = '*';
        } else {
          for (int k = 0; k < 8; k++) {
            int y = j + dx[k];
            int x = i + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && map[x][y] == '*') {
              field[i][j]++;
            }
          }
        }
      }
    }
    PrintAnswerMap(n, m, &count, field);
  }
  return 0;
}