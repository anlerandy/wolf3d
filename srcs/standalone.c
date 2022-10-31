/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standalone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 08:33:54 by alerandy          #+#    #+#             */
/*   Updated: 2021/04/30 03:01:19 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		standalone(char *env, t_data *data)
{
	int		a;

	a = ft_strlen(env);
	while (env[a - 1] != '/' && a >= 0)
		env[--a] = '\0';
	if (env[--a] == '/' && env[a - 1] == '.' && env[a - 2] == '/')
	{
		env[a--] = '\0';
		env[a--] = '\0';
	}
	ft_putendl(env);
	data->env = ft_strdup(env);
}
