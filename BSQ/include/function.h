/*
** EPITECH PROJECT, 2024
** BSQ
** File description:
** function
*/

#ifndef FUNCTION_H_
    #define FUNCTION_H_

    #include <sys/types.h>

    #include "struct.h"

//!! PARSING !!

int parse_arguments(int ac, char **av, bsq_t *bsq);

//!! SEARCH !!

void search_biggest_square(bsq_t *bsq);

//!! FREE !!

void free_array(void *to_free);
void free_array_size_n(void *to_free, const size_t n);

#endif
