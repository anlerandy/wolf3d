/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:26:49 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/06 16:42:06 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	long	a;
	int		sign;
	int		i;

	a = 10;
	i = 1;
	nb = (long)n;
	sign = n < 0 ? 1 : 0;
	n < 0 ? nb = -nb : nb;
	while (nb > a - 1 && i++)
		a *= 10;
	a /= 10;
	if (!(str = ft_memalloc(sizeof(char) * (i + sign) + 1)))
		return (str);
	i = 0;
	sign ? str[i++] = '-' : i;
	while (a >= 1)
	{
		str[i++] = nb / a + '0';
		nb %= a;
		a /= 10;
	}
	return (str);
}
