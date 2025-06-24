/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:30:57 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/15 15:30:57 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
/*
    This function divides int a by b
    and stores the result in a;
    stores the remainder of the division in the b;
    special case for 0;
	temporary ints to avoid work with overwritten values
*/
{
	int	tmpa;
	int	tmpb;

	tmpa = *a;
	tmpb = *b;
	if (b != 0)
	{
		*a = tmpa / tmpb;
		*b = tmpa % tmpb;
	}
	else
	{
		*a = 0;
		*b = 0;
	}
}

/*
int main()
{
    int a = 10;
    int b = 3;

    ft_ultimate_div_mod(&a, &b);

    printf("Div: %d, Mod: %d\n", a, b);
    return 0;
}
*/
