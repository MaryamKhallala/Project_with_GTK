
#define MAX_CHAR 6

typedef struct pr_list_float
{
    float number;
    struct pr_list_float *next;
} prListFloat;

typedef struct command
{
    char string[MAX_CHAR];
    struct command *next;
} prCommand;

typedef struct pr_operation
{
    char op; // +, -, *, /, <, >, T, t
    prListFloat *list;
} prOperation;
