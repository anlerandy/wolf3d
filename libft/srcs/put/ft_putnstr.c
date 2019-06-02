/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:27:42 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/08 22:34:34 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(char const *s, int len, int fd)
{
	if (!s)
		return ;
	write(fd, s, len);
}

void	ft_putnstr(char const *s, int len)
{
	ft_putnstr_fd(s, len, 1);
}
