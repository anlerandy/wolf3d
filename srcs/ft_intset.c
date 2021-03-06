/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:36:38 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/26 18:13:54 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char		*ft_intset(char *tab, int i, int size)
{
	int	x;

	x = 0;
	while (x < size)
		((int*)tab)[x++] = i;
	return (tab);
}

char		*ft_intadd(char *tab, int i, int size)
{
	int	x;

	x = 0;
	while (x < size)
		((int*)tab)[x++] = i & 0xFF000000;
	return (tab);
}
