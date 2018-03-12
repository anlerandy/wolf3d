/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standalone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 08:33:54 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/12 09:04:11 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		standalone(char *env, t_data *data)
{
	int		i;
	int		a;

	i = 0;
	a = ft_strlen(env);
	while (env[a - 1] != '/' && a >= 0)
		env[--a] = '\0';
	data->env = ft_strdup(env);
}
