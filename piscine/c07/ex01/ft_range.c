/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:38:12 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/23 20:49:31 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max) {
    if (min >= max)
        return NULL;

    int size = max - min;
    int *arr = malloc(sizeof(int) * size);
    if (!arr)
        return NULL;

    for (int i = 0; i < size; i++) {
        arr[i] = min + i;
    }

    return arr;
}

int main(void) {
    int min = 5;
    int max = 10;
    int *range = ft_range(min, max);

    if (range) {
        for (int i = 0; i < max - min; i++) {
            printf("%d ", range[i]);
        }
        printf("\n");
        free(range);
    } else {
        printf("NULL\n");
    }

    return 0;
}
