/*
** EPITECH PROJECT, 2024
** BSQ
** File description:
** search_biggest_square
*/

#include <stddef.h>
#include <unistd.h>

#include "struct.h"

static int see_x_axis(bsq_t *bsq, const size_t y, const size_t i,
    const size_t size)
{
    size_t count = 0;

    for (size_t a = i; bsq->parsed_file_content[y][a] != '\0'; a++) {
        if (bsq->parsed_file_content[y][a] == 'o') {
            return -1;
        }
        if (count == size) {
            return 0;
        }
        count++;
    }
    return -1;
}

static size_t see_inside_square(bsq_t *bsq, const size_t j, const size_t i)
{
    size_t size = 0;
    size_t count = 0;

    for (size_t y = j; bsq->parsed_file_content[y] != NULL; y++) {
        if (see_x_axis(bsq, y, i, size) == -1) {
            break;
        }
        if (count == size) {
            size++;
            count = 0;
            y = j;
        }
        count++;
    }
    return size;
}

static int compare_x_axis(bsq_t *bsq, const size_t y, const size_t i,
    const size_t size)
{
    for (size_t x = i; x < size + i; x++) {
        if (bsq->parsed_file_content[y][x] == 'o') {
            return -1;
        }
    }
    return 0;
}

static int is_square(bsq_t *bsq, const size_t j, const size_t i,
    const size_t size)
{
    for (size_t y = j; y < size + j; y++) {
        if (compare_x_axis(bsq, y, i, size) == -1) {
            return -1;
        }
    }
    return 0;
}

static void see_map(bsq_t *bsq, const size_t j, const size_t i)
{
    size_t size = 0;

    if (bsq->parsed_file_content[j][i] == 'o') {
        return;
    }
    size = see_inside_square(bsq, j, i);
    if (is_square(bsq, j, i, size) == 0 && size > bsq->biggest_square) {
        bsq->biggest_square = size;
        bsq->start_x = i;
        bsq->start_y = j;
    }
}

void search_biggest_square(bsq_t *bsq)
{
    for (size_t j = 0; bsq->parsed_file_content[j] != NULL; j++) {
        for (size_t i = 0; bsq->parsed_file_content[j][i] != '\0'; i++) {
            see_map(bsq, j, i);
        }
    }
    for (size_t y = bsq->start_y; y < bsq->biggest_square + bsq->start_y;
    y++) {
        for (size_t x = bsq->start_x; x < bsq->biggest_square + bsq->start_x;
        x++) {
            bsq->parsed_file_content[y][x] = 'x';
        }
    }
    for (size_t y = 0; bsq->parsed_file_content[y] != NULL; y++) {
        for (size_t x = 0; bsq->parsed_file_content[y][x] != '\0'; x++) {
            write(STDOUT_FILENO, &bsq->parsed_file_content[y][x], 1);
        }
        write(STDOUT_FILENO, "\n", 1);
    }
}
