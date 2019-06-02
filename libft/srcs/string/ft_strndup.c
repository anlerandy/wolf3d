/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:19:59 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/21 16:39:18 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ptr;

	if (ft_strlen(s1) < n)
		n = ft_strlen(s1);
	if (!(ptr = (char*)ft_memalloc(sizeof(char) * n + 1)))
		return (ptr);
	ft_memcpy(ptr, s1, n);
	return (ptr);
}
