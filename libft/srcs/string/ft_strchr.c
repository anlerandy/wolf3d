/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:17:52 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/08 21:24:30 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*s2;

	i = 0;
	s2 = (char*)s;
	ch = (char)c;
	if (ch == '\0')
		return (s2 + ft_strlen(s2));
	while (s2[i] && ch != s2[i])
		i++;
	if (!s2[i])
		return (NULL);
	return (s2 + i);
}
