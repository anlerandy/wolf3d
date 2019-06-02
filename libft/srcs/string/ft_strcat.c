/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:34:41 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/08 19:32:27 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	y;

	i = ft_strlen(s1);
	y = ft_strlen(s2);
	ft_memcpy(s1 + i, s2, y);
	s1[i + y] = '\0';
	return (s1);
}
