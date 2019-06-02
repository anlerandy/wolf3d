/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:16:38 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/10 19:30:30 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_memfill(unsigned long *dstp, unsigned long *srcp, \
		size_t len)
{
	unsigned long	*source;
	unsigned long	*destination;

	while (--len > 0)
	{
		destination = (unsigned long*)*dstp;
		source = (unsigned long*)*srcp;
		destination[0] = source[0];
		destination[1] = source[1];
		destination[2] = source[2];
		destination[3] = source[3];
		destination[4] = source[4];
		destination[5] = source[5];
		destination[6] = source[6];
		destination[7] = source[7];
		*dstp += 8 * OP_SIZE;
		*srcp += 8 * OP_SIZE;
	}
}

static inline void	ft_memfillrest(unsigned long *dstp, unsigned long *srcp, \
		size_t len)
{
	while (--len > 0)
	{
		*((unsigned long *)*dstp) = *((unsigned long *)*srcp);
		*dstp += OP_SIZE;
		*srcp += OP_SIZE;
	}
}

void				*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned long	dstp;
	unsigned long	srcp;

	dstp = (unsigned long)dst;
	srcp = (unsigned long)src;
	if (len >= 8)
	{
		while (dstp % OP_SIZE != 0 && len--)
			*((unsigned char *)dstp++) = *((unsigned char *)srcp++);
		ft_memfill(&dstp, &srcp, len / (OP_SIZE * 8) + 1);
		len %= OP_SIZE * 8;
		ft_memfillrest(&dstp, &srcp, len / OP_SIZE + 1);
		len %= OP_SIZE;
	}
	while (len-- > 0)
		*((unsigned char *)dstp++) = *((unsigned char *)srcp++);
	return (dst);
}
