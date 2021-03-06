/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:02:13 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/16 09:04:55 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 32
# define FALSE 0
# define TRUE 1

typedef struct	s_read
{
	char		buffed[BUFF_SIZE];
	char		*buffer;
	int			ret;
}				t_read;

typedef struct	s_stock
{
	char		*str;
	int			done;
	int			index;
	int			len;
	int			fd;
}				t_stock;

int				get_next_line(const int fd, char **line);

#endif
