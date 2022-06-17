/*
** EPITECH PROJECT, 2022
** execute_program.c
** File description:
** execute_program
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "lib.h"
#include "exit.h"
#include "src.h"
#include "my_printf/my_printf.h"

static int do_execve(char **args, char *command, char *exec_path)
{
    char *exec_path_with_slash = NULL;

    if (my_strcat(&exec_path_with_slash, exec_path, "/") == EXIT_MALLOC)
        exit(EXIT_MALLOC);
    if (my_strcat(&command, exec_path_with_slash, args[0]) == EXIT_MALLOC)
        exit(EXIT_MALLOC);
    free(exec_path_with_slash);
    if (execve(command, args, NULL) == -1)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int check_program_execution_error(int len, int i, char *program_name)
{
    if (len == i) {
        my_putstr_error("minishell1: ");
        my_putstr_error(program_name);
        my_putstr_error(": command not found...\n");
    }
    return EXIT_SUCCESS;
}

static void execute_program_next(char **args, node_t **list_env)
{
    char *command = NULL;
    char **exec_paths = NULL;
    node_t *path = find_node(*list_env, "PATH");
    int i = 0;
    int len = 0;

    str_to_2d_array(path->value, &exec_paths, ':');
    len = my_str_array_len(exec_paths);
    while (exec_paths[i] != NULL) {
        if (do_execve(args, command, exec_paths[i]) == EXIT_SUCCESS)
            break;
        i++;
    }
    free_str_2d_array(exec_paths);
    free(path);
    if (check_program_execution_error(len, i, args[0]) == EXIT_ERROR)
        exit(EXIT_ERROR);
    exit(EXIT_SUCCESS);
}

void execute_my_program(char **args, char **env)
{
    char *command = my_revstr(my_strdup(args[0]));
    int len = my_strlen(command);

    command[len] = '\0';
    command[len - 1] = '\0';
    command[len - 2] = '\0';
    my_revstr(command);
    if (execve(command, args, env) == -1)
    free(command);
}

int execute_program(char **args, node_t **list_env, char **env)
{
    pid_t pid = 0;
    pid_t wpid = 0;
    int status = 0;

    pid = fork();
    if (pid == -1) {
        my_putstr_error("Error: fork\n");
        return EXIT_ERROR;
    } else if (pid == 0) {
        if (args[0][0] == '.' && args[0][1] == '/')
            execute_my_program(args, env);
        execute_program_next(args, list_env);
    } else {
        while ((wpid = wait(&status)) > 0);
        if (WCOREDUMP(status)) {
            my_putstr_error("Segmentation fault (core dumped)\n");
            return (status);
        }
    }
    return EXIT_SUCCESS;
}
