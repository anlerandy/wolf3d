/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:14:54 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/02 19:13:02 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int		single_checker(unsigned char *s1, unsigned char *s2)
{
	if (*s1 != *s2)
		return (*s1 - *s2);
	if (s1[1] != s2[1])
		return (s1[1] - s2[1]);
	if (s1[2] != s2[2])
		return (s1[2] - s2[2]);
	if (s1[3] != s2[3])
		return (s1[3] - s2[3]);
	if (s1[4] != s2[4])
		return (s1[4] - s2[4]);
	if (s1[5] != s2[5])
		return (s1[5] - s2[5]);
	if (s1[6] != s2[6])
		return (s1[6] - s2[6]);
	if (s1[7] != s2[7])
		return (s1[7] - s2[7]);
	return (0);
}

static inline int		eight_checker(unsigned long int **s1, \
							unsigned long int **s2, size_t len)
{
	int					cmp;
	unsigned long int	src;
	unsigned long int	dst;

	while (--len)
	{
		src = *(*s1++);
		dst = *(*s2++);
		if (src != dst)
			if ((cmp = single_checker((unsigned char*)&src, \
				(unsigned char *)&dst)))
				return (cmp);
	}
	return (0);
}

static inline int		get_cmp(unsigned long int **s1, \
							unsigned long int **s2, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;

	str1 = (unsigned char*)*s1;
	str2 = (unsigned char*)*s2;
	while (--n && *str1 == *str2)
	{
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long int	*ptr1;
	unsigned long int	*ptr2;
	size_t				len;
	int					cmp;

	len = n / 8 + 1;
	n -= (len - 1) * 8;
	ptr1 = (unsigned long int*)s1;
	ptr2 = (unsigned long int*)s2;
	if ((cmp = eight_checker(&ptr1, &ptr2, len)))
		return (cmp);
	return (get_cmp(&ptr1, &ptr2, n));
}
