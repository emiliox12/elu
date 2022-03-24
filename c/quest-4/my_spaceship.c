#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct
{
  int x;
  int y;
  int dir;
} space_ship_pos;
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int modFn(int n, int m)
{
  return ((n % m) + m) % m;
}

char *my_spaceship(char *route)
{
  char *directions[] = {"up", "right", "down", "left"};
  space_ship_pos spaceShip = {0, 0, 0};
  for (int i = 0; i < strlen(route); i++)
  {
    char input = route[i];
    if (input == 'A')
    {
      if (spaceShip.dir == 0)
      {
        spaceShip.y--;
      }
      else if (spaceShip.dir == 1)
      {
        spaceShip.x++;
      }
      else if (spaceShip.dir == 2)
      {
        spaceShip.y++;
      }
      else if (spaceShip.dir == 3)
      {
        spaceShip.x--;
      }
    }
    else
    {
      if (input == 'R')
      {
        spaceShip.dir = modFn(++spaceShip.dir, 4);
      }
      else if (input == 'L')
      {
        spaceShip.dir = modFn(--spaceShip.dir, 4);
      }
    }
  }
  /* printf("{x: %d, y: %d, direction: '%s'}\n", spaceShip.x, spaceShip.y, directions[spaceShip.dir]); */
  char *buffer = malloc(50);
  snprintf(buffer, 50, "{x: %d, y: %d, direction: '%s'}\n", spaceShip.x, spaceShip.y, directions[spaceShip.dir]);
  return buffer;
}

int main()
{
  char *res = my_spaceship("RAALALL");
  printf("%s", res);
  return 0;
}