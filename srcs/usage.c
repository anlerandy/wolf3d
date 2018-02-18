/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 00:13:20 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/17 17:19:26 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	usage(int c)
{
	c == 1 ? ft_putendl("Erreur d'allocation mémoire.") : c;
	c == 2 ? ft_putendl("Initialisation MLX échoué.") : c;
	c == 3 ? ft_putendl("Texture invalide. Échec de chargement texture.") : c;
	c == 42 ? ft_putendl("WolfEngine a correctement fermé.") : c;
	exit(0);
}

int		wolf_exit(void)
{
	usage(42);
	return (0);
}
