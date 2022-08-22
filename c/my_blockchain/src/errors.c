#include <errors.h>

int launch_error(errors error)
{
  switch (error)
  {
  case NO_MORE_RESOURCES_AVAILABLE_ON_THE_COMPUTER:
    printf("No more resources available on the computer\n");
    break;
  case THIS_NODE_ALREADY_EXISTS:
    printf("This node already exists\n");
    break;
  case THIS_BLOCK_ALREADY_EXISTS:
    printf("This block already exists\n");
    break;
  case NODE_DOESN_T_EXIST:
    printf("Node doesn't exist\n");
    break;
  case BLOCK_DOESN_T_EXIST:
    printf("Block doesn't exist\n");
    break;
  case COMMAND_NOT_FOUND:
    printf("Command not found\n");
    break;
  default:
    printf("Uncontrolled error");
    break;
  }
  return error;
}
