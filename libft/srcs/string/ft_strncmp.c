/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:04:24 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/22 18:34:52 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	j = ft_strlen(s1);
	i = ft_strlen(s2);
	j = j < i ? j : i;
	i = 0;
	j = n < j ? n : j;
	if (n == 0)
		return (0);
	while (j <= i && ((unsigned long int)(str1 + i) & \
			(sizeof(unsigned long int) - 1)) != 0 && \
			((unsigned long int)(str2 + i) & \
			(sizeof(unsigned long int) - 1)) != 0)
	{
		if (str1[i] != str2[i] || (!str1[i] || !str2[i]))
			return (str1[i] - str2[i]);
		++i;
	}
	return (ft_memcmp((void *)(str1 + i), (void *)(str2 + i), j - i));
}
