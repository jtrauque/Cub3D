/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:48:56 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/18 14:09:49 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_print_fd(long n, int fd)
{
	int		div;
	int		i;
	char	c;

	div = 1;
	i = 0;
	while (n / div >= 10)
		div *= 10;
	while (div != 0)
	{
		c = n / div + '0';
		ft_putchar_fd(c, fd);
		n = n % div;
		div = div / 10;
		i++;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	long nb;

	nb = (long)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		ft_print_fd(-nb, fd);
	}
	else
		ft_print_fd(nb, fd);
}
