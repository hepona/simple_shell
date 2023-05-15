#include "shell.h"
/* int ac, char **argv*/

/**
 * main -> simple shell
 * Return: 0 if success, -1 otherwise
*/
int main(int ac, char **argv){

  // int lcom;
  char *cmd = NULL, *cmd_cp = NULL;
  size_t bufsize = 0;
  ssize_t cmdread;
  char *token,  **arg;
  int i, c_tok = 0;
  

 (void)ac;//(void)arg;
  while (1)
  { 
    _putstr("($) > ");
    cmdread = getline(&cmd, &bufsize, stdin); /*return num of char without null terminator*/

      if (strcmp(cmd, "exit\n") == 0 || cmdread == EOF)
      { 
              _putstr("\nExiting shell...\n");
              break;
      }
  
      cmd_cp = malloc(sizeof(char*)  * cmdread + 1);
      if (cmd_cp == NULL)
      {
        perror("Error: malloc");
        return (-1);
      }
      strcpy(cmd_cp, cmd);

      token = strtok(cmd, " \n");
      while (token != NULL)
      {
        c_tok++;
        token = strtok(NULL, " \n");
      } c_tok++; 
     

      arg = malloc(sizeof(char*) * c_tok);
      token = strtok(cmd_cp, " \n");

      for ( i = 0; token != NULL; i++)
      {     
            arg[i] = malloc(sizeof(char) * strlen(token) );
            strcpy(arg[i], token);

            token = strtok(NULL, " \n");
      }arg[i] = NULL;
      
    execute_cmd(arg);










    
   

  free(cmd_cp);
  free(arg);

  }
  free(cmd);
 
  return 0;

}