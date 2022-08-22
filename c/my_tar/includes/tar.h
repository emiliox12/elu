#define MAX_NAME_LENGTH 100
#define MAX_SIZE_LENGTH 12
#define BLOCK_SIZE 512

struct args_t
{
  bool c;
  bool r;
  bool t;
  bool u;
  bool x;
  bool f;
};

enum fileType
{
  FileType,
  FolderType,
};

typedef struct s_largs
{
  char *argName;
  enum fileType type;
  struct s_largs *next;
} largs_t;

typedef struct s_data
{
  char *archiveName;
  largs_t *args;
  struct args_t options;
} data_t;

typedef struct archive_header
{
  char *name;
  int size;
  long int time;
};