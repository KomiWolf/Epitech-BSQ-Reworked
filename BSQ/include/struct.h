/*
** EPITECH PROJECT, 2024
** BSQ
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct bsq_s {
    char **parsed_file_content;
    size_t line_nb;
    size_t start_x;
    size_t start_y;
    size_t biggest_square;
} bsq_t;

#endif
