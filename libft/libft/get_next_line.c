/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:25:20 by alcornea          #+#    #+#             */
/*   Updated: 2017/04/20 12:25:22 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_memory(char *tmp, char *buff)
{
	char	*temp;

	if (!(temp = ft_strjoin(tmp, buff)))
		return (NULL);
	free(tmp);
	tmp = NULL;
	return (temp);
}

static int	check_endline(char *tmp)
{
	int endl;

	endl = 0;
	while (tmp[endl])
	{
		if (tmp[endl] == '\n')
			return (endl);
		endl++;
	}
	return (endl);
}

static int	get_line(const int fd, char *tmp[fd], char **line)
{
	int		till_end;
	char	*temp;

	till_end = check_endline(tmp[fd]);
	*line = ft_strsub(tmp[fd], 0, till_end);
	if (!(temp = (char *)malloc(sizeof(temp) * (ft_strlen(tmp[fd]) + 1))))
		return (-1);
	ft_strcpy(temp, &tmp[fd][till_end + 1]);
	ft_strclr(tmp[fd]);
	tmp[fd] = ft_strcpy(tmp[fd], temp);
	free(temp);
	return (1);
}

static int	get_buff(const int fd, char *tmp[fd])
{
	char	buff[BUFF_SIZE + 1];
	int		buf_n;

	while (!(ft_strchr(tmp[fd], '\n')) &&
		(buf_n = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[buf_n] = '\0';
		tmp[fd] = free_memory(tmp[fd], buff);
	}
	return (buf_n);
}

int			get_next_line(const int fd, char **line)
{
	static char	*tmp[MAX_FD];

	if (fd < 0 || fd == 1 || fd == 2 || fd > MAX_FD || !line || BUFF_SIZE < 0)
		return (-1);
	if (!tmp[fd] && (!(tmp[fd] = ft_strnew(2))))
		return (-1);
	if (get_buff(fd, &(*tmp)) < 0)
		return (-1);
	if (tmp[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (get_line(fd, tmp, line) < 0)
		return (-1);
	return (1);
}
