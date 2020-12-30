/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:45:04 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/18 14:09:12 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_c(long n)
{
	int count;
	int div;

	count = 1;
	div = 1;
	while (n / div >= 10)
	{
		div *= 10;
		count++;
	}
	return (count);
}

static char	*ft_print(char *str, long n)
{
	long	div;
	int		i;

	div = 1;
	i = 0;
	while (n / div >= 10)
		div *= 10;
	while (div != 0)
	{
		str[i] = n / div + '0';
		n = n % div;
		div = div / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * (ft_count_c(-nb) + 2))))
			return (NULL);
		str[0] = '-';
		ft_print(str + 1, -nb);
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * (ft_count_c(nb) + 1))))
			return (NULL);
		ft_print(str, nb);
	}
	return (str);
}
