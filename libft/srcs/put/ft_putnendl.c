/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:28:51 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/22 18:34:09 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnendl_fd(const char *s, int len, int fd)
{
	if (!s)
		return ;
	ft_putnstr_fd(s, len, fd);
	ft_putchar_fd('\n', 1);
}

void	ft_putnendl(const char *s, int len)
{
	ft_putnendl_fd(s, len, 1);
}
