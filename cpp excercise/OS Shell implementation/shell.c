//
// Created by student on 02/08/2020.
//
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

pid_t run_command(int count, char **arglist)
{
    pid_t child_pid = fork();
    if (child_pid == -1) {
        fprintf(stderr, "\nFailed forking Child\n");
        exit(1);
    }
    if (child_pid == 0) {
        if (execvp(arglist[0], arglist) < 0) {
            fprintf(stderr, "\nCould not exec command\n");
            exit(1);
        }
    }
    return child_pid;
}


int exec_with_wait(int count, char **arglist) {
    int stat_loc;

    pid_t ch = run_command(count, arglist);
    if (ch > 0)
    {
        waitpid(ch, &stat_loc, 0);
    }
    return 0;
}

int exec_without_wait(int count, char **arglist)
{
    arglist[count - 1] = NULL;
    run_command(count, arglist);
    return 0;
}

int execute(int count, char **arglist)
{
    if (!strcmp(arglist[count - 1], "&")) {
        return exec_without_wait(count, arglist);
    }
    else
        return exec_with_wait(count, arglist);
}

void create_command()
{
    char** arglist = NULL;
    char* line = NULL;
    size_t size;
    int count = 0;

    if (getline(&line, &size, stdin) == -1) {
        free(line);
        return;
    }

    arglist = (char**) malloc(sizeof(char*));
    if (arglist == NULL) {
        printf("malloc failed\n");
        exit(1);
    }
    arglist[0] = strtok(line, " \t\n");

    while (arglist[count] != NULL) {
        ++count;
        arglist = (char**) realloc(arglist, sizeof(char*) * (count + 1));
        if (arglist == NULL) {
            printf("realloc failed\n");
            exit(1);
        }
        arglist[count] = strtok(NULL, " \t\n");
    }

    if (count != 0) {
        if (strcmp(arglist[0], "exit") == 0)
            exit(0);
        execute(count, arglist);
    }
    free(line);
    free(arglist);

}

int main()
{
    while(1)
    {
        printf("myShell >>> ");
        create_command();
    }
}

