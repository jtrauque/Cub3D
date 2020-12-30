/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:19:38 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/20 17:36:22 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char		*ft_strchr(const char *s, int c);
int			get_next_line(int fd, char **line);
 char	*ft_strnjoin(char *s1, char *s2, int n);

#endif
