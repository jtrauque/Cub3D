/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:42:48 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/16 12:59:16 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	n;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '-') ? -sign : sign;
		i++;
	}
	if (str[i] < '0' && str[i] > '9')
		return (0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] < '0' && str[i] > '9')
			break ;
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
