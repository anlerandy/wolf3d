/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:44:24 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/12 21:33:20 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"

t_rb_node			**rb_rot_node(t_rb_node **root, t_rb_node *node)
{
	t_rb_node	**rot_node;
	t_rb_node	*father;

	rot_node = root;
	father = node->parent;
	if (father)
	{
		if (node == father->left)
			rot_node = &(father->left);
		else
			rot_node = &(father->right);
	}
	return (rot_node);
}

void				rb_rotation_left(t_rb_node **root, t_rb_node *node)
{
	t_rb_node	**old_node;
	t_rb_node	*node_a;
	t_rb_node	*node_b;

	old_node = rb_rot_node(root, node);
	node_a = *old_node;
	if (!node_a || !(node_a->right))
		return ;
	node_b = node_a->right;
	node_b->parent = node_a->parent;
	node_a->right = node_b->left;
	node_b->left = node_a;
	node_a->parent = node_b;
	if (node_a->right)
		node_a->right->parent = node_a;
	*old_node = node_b;
}

void				rb_rotation_right(t_rb_node **root, t_rb_node *node)
{
	t_rb_node	**old_node;
	t_rb_node	*node_a;
	t_rb_node	*node_b;

	old_node = rb_rot_node(root, node);
	node_a = *old_node;
	if (!node_a || !(node_a->left))
		return ;
	node_b = node_a->left;
	node_b->parent = node_a->parent;
	node_a->left = node_b->right;
	node_b->right = node_a;
	node_a->parent = node_b;
	if (node_a->left)
		node_a->left->parent = node_a;
	*old_node = node_b;
}
