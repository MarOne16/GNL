/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:00:02 by mqaos             #+#    #+#             */
/*   Updated: 2022/11/21 21:15:52 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		u;
	char	*s3;

	i = -1;
	u = -1;
	s3 = malloc(ft_strlenn(s1) + ft_strlenn(s2) + 1);
	if (!s3)
		return (0);
	while (s1 && s1[++i])
		s3[++u] = s1[i];
	i = -1;
	while (s2[++i] && s2)
	{
		s3[++u] = s2[i];
		if (s3[u] == '\n')
			break ;
	}
	s3[++u] = '\0';
	free(s1);
	return (s3);
}

int	removeline(char *str)
{
	int	i;
	int	u;
	int	x;

	i = 0;
	u = -1;
	x = 0;
	while (str[i])
	{
		if (x)
			str[++u] = str[i];
		if (str[i] == '\n')
			x = 1;
		str[i] = '\0';
		i++;
	}
	return (x);
}
