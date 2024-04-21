
#include <unistd.h>//fork, execve, dup2, pipe, close
#include <stdlib.h>//malloc, free
#include <string.h>//strcmp


int err(char *str)//print error message
{
    while (*str)
        write(2, str++, 1);
    return 1;
}

int cd(char **argv, int i)//change directory function
{
    if (i != 2)//check if the number of arguments is correct
        return err("error: cd: bad arguments\n");//print error message
    else if (chdir(argv[1]) == -1)//try to change directory to the path in argv[1] using chdir function and check if it's successful
        return err("error: cd: cannot change directory to "), err(argv[1]), err("\n");//print error message if it's not successful
    return 0;
}

int exec(char **argv, char **envp, int i)//execute command function with pipe or not exemple: ls | wc -l
{
    int fd[2];//file descriptor created for pipe function , size 2 because it's a pipe with 2 ends read and write
    int status;//status of the child process
    int has_pipe = argv[i] && !strcmp(argv[i], "|");//check if the command has a pipe

    if (!has_pipe && !strcmp(*argv, "cd"))//check if the command is cd
        return cd(argv, i);//execute cd function

    if (has_pipe && pipe(fd) == -1)//check if the command has a pipe and create the pipe
        return err("error: fatal\n");//print error message

    int pid = fork();//create a child process
    if (!pid)//check if it's the child process
    {
        argv[i] = 0;//set the pipe or the end of the command to 0 exemple: ls | wc -l => ls 0 wc -l
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))//check if the command has a pipe and redirect the output of the first command to the input of the second command
            return err("error: fatal\n");//print error message
        if (!strcmp(*argv, "cd"))//check if the command is cd
            return cd(argv, i);//execute cd function
        execve(*argv, argv, envp);//execute the command
        return err("error: cannot execute "), err(*argv), err("\n");//print error message if the command is not executed
    }

    waitpid(pid, &status, 0);//wait for the child process to finish
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))//check if the command has a pipe and redirect the output of the first command to the input of the second command
        return err("error: fatal\n");//print error message
    return WIFEXITED(status) && WEXITSTATUS(status);//return the status of the child process
}

int main(int argc, char **argv, char **envp)//main function
{
    int    i = 0;//index
    int    status = 0;//status of the child process

    if (argc > 1)//check if there are arguments
    {
        while (argv[i] && argv[++i])//loop through the arguments
        {
            argv += i;//move the pointer to the next argument
            i = 0;//reset the index
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))//loop through the arguments
                i++;//increment the index
            if (i)//check if the index is not 0
                status = exec(argv, envp, i);//execute the command
        }
    }
    return status;//return the status of the child process
}
