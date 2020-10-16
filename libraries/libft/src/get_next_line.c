/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kris <kris@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 18:44:16 by kris          #+#    #+#                 */
/*   Updated: 2020/10/05 10:45:04 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	Frees s1.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (newstr == NULL)
		return (NULL);
	ft_memcpy(newstr, s1, len_s1 + 1);
	ft_memcpy(&newstr[len_s1], s2, len_s2 + 1);
	free((void *)s1);
	return (newstr);
}

/*
**	Reads into a temporary fixed length array.
**	String joins the existing buffer and the temporary buffer.
**	Returns 0 if 0 bytes were read or return value of read call < BUFFER_SIZE.
**	Returns -1 if malloc on new buffer failed or read returned -1.
**	Else returns a positive integer; the return value of read.
*/

int		read_and_append_buffer(int fd, char **buffer)
{
	int		ret;
	char	temp[BUFFER_SIZE + 1];

	ft_memset(temp, 0, BUFFER_SIZE + 1);
	ret = read(fd, temp, BUFFER_SIZE);
	*buffer = ft_strjoin(*buffer, temp);
	if (buffer == NULL)
		return (-1);
	if (ret < BUFFER_SIZE)
		return (0);
	return (ret);
}

/*
**  Copies the content of the buffer before '\0' or '\n' to string.
**  Copies the content of the buffer after          '\n' to buffer_list.
**  In case the EOF is copied to the string returns 0.
**  Else returns 1.
*/

int		buffer_to_line(int eof, char *buffer, char **buffer_list, char **line)
{
	int i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	*line = ft_memmalloc(i + 1);
	if (line == NULL)
		return (-1);
	ft_memcpy(*line, buffer, i);
	if (ft_strchr(buffer, '\n'))
		*buffer_list = ft_strdup(&buffer[i + 1]);
	else if (!eof)
	{
		*buffer_list = NULL;
		return (0);
	}
	return (1);
}

/*
**  Calling function get_next_linein a loop will allow you to read
**  the text available on a file descriptor one line at a time until the EOF.
**  Lines are written to double pointer line, exluding newline char.
**  The line is freed by the user.
**
**  Return value:
**  1 : A line has been read.
**  0 : EOF has been reached.
**  -1: An error happened.
*/

int		get_next_line(int fd, char **line)
{
	static char	*buffer_list[1024];
	char		*buf;
	int			ret;

	ret = 1;
	buf = ft_memmalloc(BUFFER_SIZE + 1);
	if (fd < 0 || fd > 1024 || !line || read(fd, buf, 0) < 0 || buf == NULL ||
		BUFFER_SIZE > 10000000)
	{
		free(buf);
		return (-1);
	}
	buffer_list[fd] ? ft_memcpy(buf, buffer_list[fd],
		ft_strlen(buffer_list[fd])) : 0;
	buffer_list[fd] ? free(buffer_list[fd]) : 0;
	while (ret > 0 && !ft_strchr(buf, '\n'))
		ret = read_and_append_buffer(fd, &buf);
	if (ret == -1)
		return (-1);
	ret = buffer_to_line(ret, buf, &buffer_list[fd], line);
	if (buf)
		free(buf);
	if (ret == 0 || ret == -1)
		return (ret);
	return (1);
}
