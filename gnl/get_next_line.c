#include "get_next_line.h"

static int	errors_check(char **remainder, int *ret, char **line)
{
	if (!*remainder && !*ret)
	{
		*line = ft_strdup("");
		return (2);
	}
	if (*ret < 0)
	{
		if (*remainder != NULL)
		{
			free(*remainder);
			*remainder = NULL;
		}
		return (1);
	}
	return (0);
}

static int	last_string(char **remainder, char **line)
{
	if (ft_strchr(*remainder, '\0'))
	{
		*line = ft_strdup(*remainder);
		if (!*line)
			return (-1);
		free(*remainder);
		*remainder = NULL;
	}
	return (0);
}

static int	push_to_remainder(int ret, char **remainder, char **line)
{
	char	*p;
	char	*tmp;

	if (errors_check(&*remainder, &ret, &*line) == 2)
		return (0);
	else if (errors_check(&*remainder, &ret, &*line))
		return (-1);
	if ((p = ft_strchr(*remainder, '\n')))
	{
		*p = '\0';
		*line = ft_strdup(*remainder);
		tmp = ft_strdup(++p);
		if (!*line || !tmp)
			return (-1);
		free(*remainder);
		*remainder = tmp;
		return (1);
	}
	return (last_string(&*remainder, &*line));
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	char		*buf;
	char		*tmp;
	static char	*remainder;

	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
		!(buf = (char*)malloc(BUFFER_SIZE + 1)) || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		if (remainder)
		{
			tmp = ft_strjoin(remainder, buf);
			free(remainder);
			remainder = tmp;
		}
		else
			remainder = ft_strdup(buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	buf = NULL;
	return (push_to_remainder(ret, &remainder, &*line));
}
