/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:46:14 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/20 13:44:51 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
//utils//
size_t	ft_strlen_gnl(const char *str);
char	*ft_strdup_gnl(const char *s);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_line_join(char *s1, const char *s2);

#endif