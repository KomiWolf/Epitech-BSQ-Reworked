/*
** EPITECH PROJECT, 2024
** BSQ
** File description:
** parse_arguments
*/

#include <fcntl.h>
#include <unistd.h>
#include <malloc.h>
#include <stdbool.h>

#include "function.h"
#include "constants.h"

static bool is_map(const char *line, const size_t file_index, bsq_t *bsq)
{
    int i = 0;

    if (file_index < 1 || file_index > bsq->line_nb) {
        return false;
    }
    for (; line[i] != '\0'; i++) {
        if (line[i] != 'o' && line[i] != '.') {
            return false;
        }
    }
    bsq->parsed_file_content[file_index - 1] = malloc(sizeof(char) * (i + 1));
    for (int x = 0; x < i; x++) {
        bsq->parsed_file_content[file_index - 1][x] = line[x];
    }
    bsq->parsed_file_content[file_index - 1][i] = '\0';
    bsq->parsed_file_content[file_index] = NULL;
    return true;
}

static bool is_number_string(const char *line, const size_t file_index,
    bsq_t *bsq)
{
    if (file_index > 0) {
        return false;
    }
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] < '0' || line[i] > '9') {
            return false;
        }
        bsq->line_nb += line[i] - 48;
        bsq->line_nb *= 10;
    }
    bsq->parsed_file_content = malloc(sizeof(char *) * (bsq->line_nb + 1));
    return true;
}

static int check_line(const char *line, const size_t file_index, bsq_t *bsq)
{
    if (is_number_string(line, file_index, bsq) == true) {
        return 0;
    }
    if (is_map(line, file_index, bsq) == true) {
        return 0;
    }
    free_array_size_n(bsq->parsed_file_content, file_index);
    return -1;
}

static int fill_line(const char *buffer, const int i, bsq_t *bsq)
{
    static char line[MAX_BUFFER_SIZE];
    static int pos = 0;
    static size_t file_index = 0;

    if (buffer[i] == '\n' || buffer[i] == '\0') {
        line[pos] = '\0';
        pos = 0;
        if (check_line(line, file_index, bsq) == -1) {
            return -1;
        }
        file_index++;
    } else {
        line[pos] = buffer[i];
        pos++;
        if (pos >= MAX_BUFFER_SIZE - 1) {
            return -1;
        }
    }
    return 0;
}

static int fill_loop(const char *buffer, ssize_t bytes, bsq_t *bsq)
{
    for (int i = 0; i < bytes; i++) {
        if (fill_line(buffer, i, bsq) == -1) {
            return -1;
        }
    }
    return 0;
}

static int read_file(int fd, bsq_t *bsq)
{
    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytes = 1;

    while (bytes > 0) {
        bytes = read(fd, buffer, sizeof(buffer));
        if (fill_loop(buffer, bytes, bsq) == -1) {
            return (-1);
        }
    }
    if (read(fd, buffer, sizeof(buffer)) == -1) {
        return -1;
    }
}

static int check_file(char *file, bsq_t *bsq)
{
    int fd = 0;

    fd = open(file, O_RDONLY);
    if (fd == -1) {
        return -1;
    }
    if (read_file(fd, bsq) == -1) {
        return -1;
    }
    return close(fd);
}

int parse_arguments(int ac, char **av, bsq_t *bsq)
{
    if (ac != 2) {
        return -1;
    }
    return check_file(av[1], bsq);
}
