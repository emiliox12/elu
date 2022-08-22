#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCT_ERRORS
#define STRUCT_ERRORS
typedef enum s_errors
{
  OK = 0,
  NO_MORE_RESOURCES_AVAILABLE_ON_THE_COMPUTER = 1,
  THIS_NODE_ALREADY_EXISTS = 2,
  THIS_BLOCK_ALREADY_EXISTS = 3,
  NODE_DOESN_T_EXIST = 4,
  BLOCK_DOESN_T_EXIST = 5,
  COMMAND_NOT_FOUND = 6,
} errors;
#endif

#ifndef LAUNCH_ERR
#define LAUNCH_ERR
int launch_error(errors error);
#endif
