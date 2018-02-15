/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 00:19:34 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/15 04:03:52 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	debug(int debug, char *str)
{
	if (ft_strcmp(str + ft_strlen(str) - 2, ": ") == 0)
		debug ? ft_putstr(str) : debug;
	else
		debug ? ft_putendl(str) : debug;
}
