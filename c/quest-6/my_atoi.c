#include <stdbool.h>

bool isDigit(char code)
{
  return code >= 48 && code <= 57;
}

int my_atoi(char *number)
{
  int res = 0;
  bool isNegative = number[0] == '-';
  for (int i = isNegative; number[i]; i++)
  {
    if (!isDigit(number[i]))
    {
      break;
    }
    res = res * 10 + (number[i] - '0');
  }
  return isNegative ? res * -1 : res;
}

int main(int argc, char const *argv[])
{
  printf("%d\n", atoi("52yt"));
  printf("%d\n", my_atoi("1561sc"));
  return 0;
}