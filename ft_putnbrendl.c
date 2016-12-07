#include "fillit.h"

void	ft_putnbrendl(int i)
{
	ft_putnbr(i);
	write(1, "\n", 1);
}
