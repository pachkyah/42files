/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:07:21 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/20 20:35:52 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int check_visibility(int arr[4], int from_end, int expected)
/*
	This founctin counts visible buildings and return if it matches the expected value
	from_end: 0 => increasing rows or columns left to right or top to bottom
			  1 => decreasing -//- right to left or bottom to top
	output is 1 if expected clue is satisfyied
*/
{
    int visible = 0;
    int max_height = 0;
    
    if (from_end) {
        for (int i = 3; i >= 0; i--)
        {
            if (max_height < arr[i])
            {
                max_height = arr[i];
                visible++;
            }
        }
    } else {
        for (int i = 0; i < 4; i++)
        {
            if (max_height < arr[i])
            {
                max_height = arr[i];
                visible++;
            }
        }
    }
    
    return (visible == expected);
}

// These map to your original functions
int left_to_right(int *row, int left) {
    return check_visibility(row, 0, left);
}

int right_to_left(int *row, int right) {
    return check_visibility(row, 1, right);
}

int top_to_bottom(int *col, int top) {
    return check_visibility(col, 0, top);
}

int bottom_to_top(int *col, int bottom) {
    return check_visibility(col, 1, bottom);
}