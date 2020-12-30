/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:19:07 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/20 17:29:59 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1048

char	*ft_strndup(const char *s1, int n)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!(s2 = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

 char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strndup(s2, n));
	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + n;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j] && i < len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int		ft_patch(char **line, char **save, char **tmp)
{
	char *next;

	next = ft_strchr(*save, '\n');
	*next = '\0';
	if (!(*line = ft_strnjoin(*line, *save, next - *save)))
		return (-1);
	if (!(next = ft_strndup(next + 1, ft_strlen(next + 1))))
		return (-1);
	free(*tmp);
	*tmp = next;
	return (1);
}

int		ft_line(int fd, char *buffer, char **line)
{
	static char *tmp = NULL;
	int			len;

	if (tmp && ft_strchr(tmp, '\n'))
		return (ft_patch(line, &tmp, &tmp));
	*line = tmp;
	tmp = NULL;
	while ((len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[len] = '\0';
		if (ft_strchr(buffer, '\n'))
			return (ft_patch(line, &buffer, &tmp));
		*line = ft_strnjoin(*line, buffer, BUFFER_SIZE);
	}
	if (len == -1)
		return (-1);
	if ((*line))
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];

	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	*line = NULL;
	return (ft_line(fd, buffer, line));
}
