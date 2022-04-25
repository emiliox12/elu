#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

void putNumber(int num)
{
  if (num < 0)
  {
    putchar('-');
    num = abs(num);
  }
  if (num / 10)
  {
    putNumber(num / 10);
  }
  putchar((num % 10) + '0');
}

void putOctal(int decimal)
{
  int octalNumber[100], i = 1;
  int quotient = decimal;
  while (quotient != 0)
  {
    octalNumber[i++] = quotient % 8;
    quotient = quotient / 8;
  }
  for (int j = i - 1; j > 0; j--)
    putchar(octalNumber[j] + '0');
}

void putHex(int decimal)
{
  int octalNumber[100], i = 1;
  int quotient = decimal;
  while (quotient != 0)
  {
    octalNumber[i++] = "0123456789abcdef"[quotient % 16];
    quotient = quotient / 16;
  }
  for (int j = i - 1; j > 0; j--)
    putchar(octalNumber[j]);
}

void putPointer(void *pointer)
{
  int i;
  uintptr_t p = (uintptr_t)pointer;
  putchar('0');
  putchar('x');
  for (i = (sizeof(p) << 3) - 4; i >= 0; i -= 4)
  {
    putHex((p >> i) & 0xf);
  }
}

void putPointer2(void *pointer)
{
  putchar('0');
  putchar('x');
  /* putHex((long long)&pointer); */
  int octalNumber[100], i = 1;
  int quotient = (long long)pointer;
  while (quotient != 0)
  {
    octalNumber[i++] = "0123456789abcdef"[quotient % 16];
    quotient = quotient / 16;
  }
  for (int j = i - 1; j > 0; j--)
    putchar(octalNumber[j]);
}

void putString(char *str)
{
  for (size_t i = 0; str[i]; i++)
    putchar(str[i]);
}

int my_printf(char *format, ...)
{
  va_list ap;

  va_start(ap, format);
  for (size_t i = 0; format[i]; i++)
  {
    if (format[i] == '%')
    {
      switch (format[i + 1])
      {
      case 's': /* string */
        putString(va_arg(ap, char *));
        break;
      case 'd': /* int */
        putNumber(va_arg(ap, int));
        break;
      case 'u': /* unsigned */
        putNumber(va_arg(ap, int));
        break;
      case 'o': /* octal */
        putOctal(va_arg(ap, int));
        break;
      case 'x': /* hex */
        putHex(va_arg(ap, int));
        break;
      case 'p': /* Pointer */
        putPointer(va_arg(ap, void *));
        break;
      case 'c': /* char */
        putchar(va_arg(ap, int));
        break;
      }
      i++;
    }
    else
    {
      putchar(format[i]);
    }
  }
  va_end(ap);
  return 0;
}
