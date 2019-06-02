/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_clear_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:36:23 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/12 20:29:03 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree_rb.h"

static void		recurs_clear_tree(t_rb_node *node, void (*freef)(void *))
{
	t_rb_node	*next_node;

	if (!node)
		return ;
	if (!(node->left) && !(node->right))
	{
		next_node = node->parent;
		freef(node->data);
		free(node);
	}
	else if ((next_node = node->left))
		node->left = NULL;
	else
	{
		next_node = node->right;
		node->right = NULL;
	}
	recurs_clear_tree(next_node, freef);
}

void			rb_clear_tree(t_rb_node **root, void (*freef)(void *))
{
	if (!root || !(*root))
		return ;
	recurs_clear_tree(*root, freef);
	*root = NULL;
}
