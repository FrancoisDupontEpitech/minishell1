/*
** EPITECH PROJECT, 2021
** display_help.c
** File description:
** display_help
*/

#include "lib.h"

static const char *help_message =                                       \
    "The interpreter is expected to display a prompt"                   \
    "( $> for example ) and then wait for you to write a command"       \
    "line, which must be validated by a newline.\n"                     \
    "The prompt must be displayed again only after"                     \
    "the command execution.\n"                                          \
    "Only basic command lines are expected to executed; no pipes, "     \
    "redirections or any other advanced features."                      \
    "The executables should be those found in the path, "               \
    "as indicated in the PATH variable.\n"                              \
    "If the executable cannot be found, "                               \
    "you must display an error message and display the prompt again.\n" \
    "Errors must be dealt with and must display "                       \
    "the appropriate message on the error output."                      \
    "You must correctly handle the PATH and the environment "           \
    "(by copying and restoring the initial env).\n"                     \
    "You must implement the following builtins: "                       \
    "cd, setenv, unsetenv, env, exit.\n"                                \
    "Your env builtin hasn’t to take any argument.\n"                   \
    "Your unsetenv builtin hasn’t to support the “*” wildcard.\n";

void display_help(void)
{
    my_putstr(help_message);
}
