/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:53:00 by mqaos             #+#    #+#             */
/*   Updated: 2022/11/21 19:48:03 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffmax[2147483647];
	char		*buff;

	buff = NULL;
	while (buffmax[0] || read(fd, buffmax, BUFFER_SIZE) > 0)
	{
		buff = ft_join(buff, buffmax);
		if (removeline(buffmax))
			break ;
		if (read(fd, buffmax, 0) < 0)
			return (free(buff), NULL);
	}
	return (buff);
}
