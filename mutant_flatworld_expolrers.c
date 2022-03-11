// 2022/03/11/16:59 complete
// CPE question url: https://zerojudge.tw/ShowProblem?problemid=c082
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef enum Direction {
  E, S, W, N
} Direction;

typedef struct Robot {
  int x, y;
  int lost_falg;
  Direction direction;
} Robot;

typedef struct Map {
  int x, y;
  int **scent_array;
} Map;

void CreateMapArray(Map *map) {
  int x = map->x + 1;
  int y = map->y + 1;
  int **map_array = (int**)malloc(x * sizeof(int*));
  for (int i = 0; i < x; i++) {
    map_array[i] = (int*)calloc(y, sizeof(int));
  }
  map->scent_array = map_array;
}

int IsScent(Map map, Robot robot) {
  if (map.scent_array[robot.x][robot.y] == TRUE) {
    return TRUE;
  }
  return FALSE;
}

void RobotRun(Map *map, Robot *robot, char *instruction) {
  int i = 0;
  int direction_add[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
  while (instruction[i] != '\0') {
    char command = instruction[i];
    i++;
    if (command == 'F') {
      if (robot->x + direction_add[robot->direction][0] >= 0 && 
          robot->x + direction_add[robot->direction][0] <= map->x &&
          robot->y + direction_add[robot->direction][1] >= 0 &&
          robot->y + direction_add[robot->direction][1] <= map->y) {
        robot->x += direction_add[robot->direction][0];
        robot->y += direction_add[robot->direction][1];
      } else {
        if (IsScent(*map, *robot) == FALSE) {
          map->scent_array[robot->x][robot->y] = TRUE;
          robot->lost_falg = TRUE;
        }
      }
    } else if (command == 'L') {
      if (robot->direction == E) {
        robot->direction = N;
      } else {
        robot->direction--;
      }
    } else if (command == 'R') {
      if (robot->direction == N) {
        robot->direction = E;
      } else {
        robot->direction++;
      }
    }
    if (robot->lost_falg == TRUE) {
      break;
    }
  }
}

int main() {
  char direction[4] = {'E', 'S', 'W', 'N'};
  Map map;
  scanf("%d %d", &map.x, &map.y);
  CreateMapArray(&map);
  while (1) {
    Robot robot;
    char char_direction;
    char instruction[100];
    robot.lost_falg = FALSE;
    if (scanf("%d %d %c%*c", &robot.x, &robot.y, &char_direction) == EOF) {
      break;
    }
    for (int i = 0; i < 4; i++) {
      if (char_direction == direction[i]) {
        robot.direction = i;
      }
    }
    gets(instruction);
    RobotRun(&map, &robot, instruction);
    for (int i = 0; i < 4; i++) {
      if (robot.direction == i) {
        char_direction = direction[i];
      }
    }
    printf("%d %d %c", robot.x, robot.y, char_direction);
    if (robot.lost_falg == TRUE) {
      printf(" LOST\n");
    } else {
      printf("\n");
    }
  }
  return 0;
}