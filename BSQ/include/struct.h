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
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    int biggest_square;
} bsq_t;

#endif
