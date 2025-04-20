/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_clues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:56:51 by mwojewod          #+#    #+#             */
/*   Updated: 2025/04/20 22:22:56 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	solvable(int side1, int side2)
/*
    checks if the opposite sides have an existing solution
*/
{
	if (side1 == 1 && side2 == 1)
		return (0);
	else if (side1 == 2 && side2 == 4)
		return (0);
	else if (side1 == 3 && (side2 == 3 || side2 == 4))
		return (0);
	else if (side1 == 4 && side2 != 1)
		return (0);
	return (1);
}

int	valid_clues(int *clues)
/*
    checks all the sides with their opposite sides
	first while loop: top x bottom
	second while loop: left x right
*/
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!solvable(clues[i], clues[i + 4]))
			return (0);
		i++;
	}
	i = 8;
	while (i < 12)
	{
		if (!solvable(clues[i], clues[i + 4]))
			return (0);
		i++;
	}
	return (1);
}
