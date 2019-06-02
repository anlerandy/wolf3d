/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_parenting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:06:43 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/08 19:31:39 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_btree_rb.h"

t_rb_node	*rb_grand_father(t_rb_node *node)
{
	t_rb_node	*father;

	father = node->parent;
	if (!father)
		return (NULL);
	return (father->parent);
}

t_rb_node	*rb_brother(t_rb_node *node)
{
	t_rb_node	*father;

	father = node->parent;
	if (!father)
		return (NULL);
	if (node == father->left)
		return (father->right);
	return (father->left);
}

t_rb_node	*rb_uncle(t_rb_node *node)
{
	t_rb_node	*father;
	t_rb_node	*grand_father;

	father = node->parent;
	grand_father = rb_grand_father(node);
	if (!grand_father)
		return (NULL);
	return (rb_brother(father));
}

t_rb_node	*rb_get_root(t_rb_node *node)
{
	while (node && node->parent)
		node = node->parent;
	return (node);
}
