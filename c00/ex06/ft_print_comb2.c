#include <unistd.h>

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			write(1, &"0123456789"[num1 / 10], 1); // First digit of num1
			write(1, &"0123456789"[num1 % 10], 1); // Second digit of num1
			write(1, " ", 1); // Space between the numbers
			write(1, &"0123456789"[num2 / 10], 1); // First digit of num2
			write(1, &"0123456789"[num2 % 10], 1); // Second digit of num2

			if (!(num1 == 98 && num2 == 99)) // Don't print comma after the last combination
				write(1, ", ", 2);

			num2++;
		}
		num1++;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
