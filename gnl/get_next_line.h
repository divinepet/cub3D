/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaronda <elaronda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 03:05:16 by elaronda          #+#    #+#             */
/*   Updated: 2021/01/27 22:43:49 by elaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char *str);
char	*ft_strdup(const char *str);

#endif
