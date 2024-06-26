/*
** EPITECH PROJECT, 2024
** BSQ
** File description:
** utils
*/

#include <malloc.h>

void free_array(void *to_free)
{
    void **array = (void **)to_free;

    if (array == NULL) {
        return;
    }
    for (size_t j = 0; array[j] != NULL; j++) {
        free(array[j]);
    }
    free(array);
}

void free_array_size_n(void *to_free, const size_t n)
{
    void **array = (void **)to_free;

    if (to_free == NULL) {
        return;
    }
    for (size_t j = 0; j < n; j++) {
        if (array[j] == NULL) {
            break;
        }
        free(array[j]);
    }
    free(array);
}
