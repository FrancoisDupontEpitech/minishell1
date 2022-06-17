/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int my_strlen(char const *str);
int is_alpha_numeric(char const *str, int *c);
int find_str_last_alphanumeric(char const *str);
int parse_string(char const *str, int *count, int *words_nb, int i);

int count_words(char const *str)
{
    int words_nb = 0;
    int count = 0;
    int i = 0;
    int str_end = find_str_last_alphanumeric(str);

    while (is_alpha_numeric(str, &i) == 0)
        i++;
    while (i < str_end) {
        count = 0;
        i = parse_string(str, &count, &words_nb, i);
        i++;
    }
    return (words_nb + 1);
}

int get_word_len(char const *str, int *c)
{
    int word_len = 0;

    while (is_alpha_numeric(str, c) == 0 && str[*c] != '\0')
        (*c)++;
    while (is_alpha_numeric(str, c) == 1 && str[*c] != '\0') {
        word_len++;
        (*c)++;
    }
    return (word_len);
}

char **my_str_to_word_array(char const *str)
{
    int words_nb = count_words(str);
    int word_len = 0;
    int c = 0;
    int x = 0;
    char **arr = malloc(sizeof(char *) * (words_nb + 1));

    for (int i = 0; i < words_nb; i++, x = 0, word_len = 0, c++) {
        word_len = get_word_len(str, &c);
        arr[i] = malloc(sizeof(char) * (word_len) + 1);
        while (x < word_len) {
            arr[i][x] = str[c - word_len + x];
            x++;
        }
        arr[i][x] = '\0';
    }
    arr[words_nb + 1] = 0;
    return (arr);
}
