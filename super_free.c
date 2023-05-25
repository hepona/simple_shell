#include "shell.h"

/**
 * super_free -> free varibale only if =/= null
 * @var: variable
 */
void super_free(char *var)
{
if (var != NULL)
{
free(var);
var = NULL;
}
}
