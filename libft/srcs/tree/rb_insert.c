/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:51:11 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/12 20:28:07 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_btree_rb.h"

static t_rb_node	*rb_insert_data(t_rb_node **root, t_rb_node *parent, \
						void *item, int (*cmp_funct)(void *, void *))
{
	t_rb_node	*node;
	t_rb_node	**next_node;

	node = *root;
	if (!node)
	{
		if (!(node = (t_rb_node *)malloc(sizeof(t_rb_node))))
			return (NULL);
		node->parent = parent;
		node->right = NULL;
		node->left = NULL;
		node->data = item;
		node->color = RB_RED;
		*root = node;
		return (node);
	}
	if (cmp_funct(node->data, item) > 0)
		next_node = &(node->left);
	else
		next_node = &(node->right);
	return (rb_insert_data(next_node, node, item, cmp_funct));
}

static t_rb_node	*rotate_gr_parent(t_rb_node **root, t_rb_node *node)
{
	t_rb_node	*father;
	t_rb_node	*gr_father;

	father = node->parent;
	gr_father = rb_grand_father(node);
	if (node == father->left)
		rb_rotation_right(root, gr_father);
	else
		rb_rotation_left(root, gr_father);
	father->color = RB_BLACK;
	gr_father->color = RB_RED;
	return (rb_get_root(father));
}

static t_rb_node	*rotate_parent(t_rb_node **root, t_rb_node *node)
{
	t_rb_node	*father;
	t_rb_node	*grd_father;

	father = node->parent;
	grd_father = rb_grand_father(node);
	if (grd_father->left && node == grd_father->left->right)
	{
		rb_rotation_left(root, father);
		node = node->left;
	}
	else if (grd_father->right && node == grd_father->right->left)
	{
		rb_rotation_right(root, father);
		node = node->right;
	}
	return (rotate_gr_parent(root, node));
}

static t_rb_node	*fix_tree(t_rb_node **root, t_rb_node *node)
{
	t_rb_node	*father;
	t_rb_node	*uncle;
	t_rb_node	*grand_father;

	if (!(father = node->parent))
	{
		node->color = RB_BLACK;
		return (*root);
	}
	if (father->color == RB_BLACK)
		return (*root);
	if (!(grand_father = rb_grand_father(node)))
	{
		father->color = RB_BLACK;
		return (*root);
	}
	if ((uncle = rb_uncle(node)) && uncle->color == RB_RED)
	{
		father->color = RB_BLACK;
		uncle->color = RB_BLACK;
		grand_father->color = RB_RED;
		return (fix_tree(root, grand_father));
	}
	else
		return (rotate_parent(root, node));
}

void				rb_insert(t_rb_node **root, void *data, \
						int (*cmpf)(void *, void *))
{
	t_rb_node	*new_n;

	if (!root)
		return ;
	if (!(new_n = rb_insert_data(root, NULL, data, cmpf)))
	{
		printf("Malloc Error !");
		exit(1);
	}
	*root = fix_tree(root, new_n);
}
