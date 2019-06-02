/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_fix_black_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:38:25 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/14 19:40:46 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_btree_rb.h"

static void			red_node_last(t_rb_node **root, t_rb_node *father, \
						t_rb_node *brother)
{
	brother->color = father->color;
	father->color = RB_BLACK;
	if (brother == father->right)
	{
		brother->right->color = RB_BLACK;
		rb_rotation_left(root, father);
	}
	else
	{
		brother->left->color = RB_BLACK;
		rb_rotation_right(root, father);
	}
}

static void			red_node_hiding(t_rb_node **root, t_rb_node *father, \
						t_rb_node *brother)
{
	if (father->color == RB_RED && brother->color == RB_BLACK \
			&& (!(brother->left) || brother->left->color == RB_BLACK) \
			&& (!(brother->right) || brother->right->color == RB_BLACK))
	{
		brother->color = RB_RED;
		father->color = RB_BLACK;
		return ;
	}
	if (brother->color == RB_RED)
	{
		if (brother == father->right && brother->left->color == RB_RED)
		{
			brother->color = RB_RED;
			brother->left->color = RB_BLACK;
			rb_rotation_right(root, brother);
		}
		else if (brother == father->left && brother->right->color == RB_RED)
		{
			brother->color = RB_RED;
			brother->right->color = RB_BLACK;
			rb_rotation_left(root, brother);
		}
	}
	red_node_last(root, father, brother);
}

void				rb_fix_black_node(t_rb_node **root, t_rb_node *old_node)
{
	t_rb_node	*father;
	t_rb_node	*brother;

	if (!(father = old_node->parent))
		return ;
	if ((brother = rb_brother(old_node)) && brother->color == RB_RED)
	{
		father->color = RB_RED;
		brother->color = RB_BLACK;
		if (brother == father->left)
			rb_rotation_right(root, father);
		else
			rb_rotation_left(root, father);
		brother = rb_brother(old_node);
	}
	if (!(father->color == RB_BLACK && brother->color == RB_BLACK \
				&& (!(brother->left) || brother->left->color == RB_BLACK) \
				&& (!(brother->right) || brother->right->color == RB_BLACK)))
	{
		red_node_hiding(root, father, brother);
		return ;
	}
	brother->color = RB_RED;
	rb_fix_black_node(root, father);
}
