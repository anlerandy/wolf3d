/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 00:13:20 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/05 13:52:12 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	usage(int c)
{
	c == 1 ? ft_putendl("Erreur d'allocation mémoire.") : c;
	c == 2 ? ft_putendl("Initialisation MLX échoué.") : c;
	c == 3 ? ft_putendl("Texture invalide. Échec de chargement texture.") : c;
	c == 4 ? ft_putendl("Map invalide. La map n'est pas compatible.") : c;
	c == 5 ? ft_putendl("Map invalide. Aucune entitee PLAYER_START.") : c;
	c == 6 ? ft_putendl("Map introuvable.") : c;
	c == 7 ? ft_putendl("Erreur durant le Raycasting.") : c;
	c == 8 ? ft_putendl("Map invalide. Étape(s) manquante ou mal déclaré.") : c;
	c == 42 ? ft_putendl("WolfEngine s'est correctement fermé.") : c;
	c != 42 ? ft_putstr("WolfEngine s'est fermé. ERREUR") : c;
	c != 42 ? ft_putendl(ft_itoa(c)) : c;
	exit(0);
}

int		wolf_exit(void)
{
	usage(42);
	return (0);
}
