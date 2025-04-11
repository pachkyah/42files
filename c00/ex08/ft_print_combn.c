#include <unistd.h>

void	print_comb_helper(int n, int start, int depth, char *digits)
{
	if (depth == n)
	{
		write(1, digits, n);
		write(1, ", ", 2);
		return;
	}
	for (int i = start; i <= 9; i++)
	{
		digits[depth] = '0' + i;
		print_comb_helper(n, i + 1, depth + 1, digits);
	}
}

void	ft_print_comb(int n)
{
	char	digits[10];

	// Initialize digits array
	print_comb_helper(n, 0, 0, digits);
}

int	main(void)
{
	ft_print_comb(3); // Example: n = 3 for combinations of 3 distinct digits
	return 0;
}
