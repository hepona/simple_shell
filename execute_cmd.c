#include "shell.h"

/**
 * execute_cmd -> execute a command entered by user
 * @cmd: commande entered
*/

void execute_cmd(char **argv)
{
	char *cmd = NULL;
	int pid = fork();

    if (pid ==  0){
       
        if (argv != NULL) {
            cmd = argv[0];
            if (execve(cmd, argv, NULL) == -1){
                perror("Error");
            }
        }
    }
    else if (pid == -1)
    {
        perror("Error");
        exit (1);
    }
    else
        wait(NULL);
    
    


    //     cmd = argv[0];
    // // return (pid == -1)? -1 : 0;
    // if (pid == -1)
    //     return -1;
    // if (pid == 0 && execve("cmd", argv, NULL))
    // {   
    //     if (exe == -1)
    //       perror("Error : execve");
    // }
    // else
    //   wait(NULL);




}