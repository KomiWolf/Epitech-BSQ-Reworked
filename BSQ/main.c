/*
** EPITECH PROJECT, 2024
** BSQ
** File description:
** main
*/

#include <stddef.h>

#include "function.h"
#include "constants.h"

int main(int ac, char **av)
{
    bsq_t bsq = { NULL, 0, 0, 0, 0 };

    if (parse_arguments(ac, av, &bsq) == -1) {
        return ERROR;
    }
    search_biggest_square(&bsq);
    free_array(bsq.parsed_file_content);
    return 0;
}
