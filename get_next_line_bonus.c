/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:58:25 by mqaos             #+#    #+#             */
/*   Updated: 2022/11/22 18:11:33 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffmax[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*buff;

	if (fd < 0 || fd > FOPEN_MAX)
		return (0);
	buff = 0;
	while (buffmax[fd][0] || read(fd, buffmax[fd], BUFFER_SIZE) > 0)
	{
		buff = ft_join(buff, buffmax[fd]);
		if (removeline(buffmax[fd]))
			break ;
		if (read(fd, buffmax[fd], 0) < 0)
			return (free(buff), NULL);
	}
	return (buff);
}
