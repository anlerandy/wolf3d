/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:35:47 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/10 19:25:47 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	single_checker(const char **s, const char **str)
{
	if ((*str)[0] == 0)
		return (*str - *s);
	if ((*str)[1] == 0)
		return (*str - *s + 1);
	if ((*str)[2] == 0)
		return (*str - *s + 2);
	if ((*str)[3] == 0)
		return (*str - *s + 3);
	if ((*str)[4] == 0)
		return (*str - *s + 4);
	if ((*str)[5] == 0)
		return (*str - *s + 5);
	if ((*str)[6] == 0)
		return (*str - *s + 6);
	if ((*str)[7] == 0)
		return (*str - *s + 7);
	return (0);
}

static inline size_t	per_eight_checker(const char **s, const char **str)
{
	unsigned long int	himagic;
	unsigned long int	lomagic;
	unsigned long int	*tmp;
	unsigned long int	cast;
	size_t				len;

	himagic = 0x80808080L;
	lomagic = 0x01010101L;
	himagic = ((himagic << 16) << 16) | himagic;
	lomagic = ((lomagic << 16) << 16) | lomagic;
	tmp = (unsigned long int *)*str;
	while (1)
	{
		cast = *tmp++;
		if (((cast - lomagic) & ~lomagic & himagic) != 0)
		{
			*str = (const char *)(tmp - 1);
			if ((len = single_checker(s, str)) != 0)
				return (len);
		}
	}
}

size_t					ft_strlen(const char *s)
{
	const char	*str;
	size_t		i;

	str = s;
	i = 0;
	if (!*s)
		return (0);
	while (((unsigned long int)(str + i) & (sizeof(unsigned long) - 1)) != 0)
		if (str[i++] == '\0')
			return (i - 1);
	str += i;
	return (per_eight_checker(&s, &str));
}
