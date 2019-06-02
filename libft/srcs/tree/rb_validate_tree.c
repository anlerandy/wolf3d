/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_validate_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:57:15 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/14 20:13:41 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"

static int	validate_subtree(t_rb_node *node)
{
	int		left_count;
	int		right_count;

	if (!node)
		return (1);
	left_count = validate_subtree(node->left);
	right_count = validate_subtree(node->right);
	if (left_count == -1 || right_count == -1 || left_count != right_count)
		return (-1);
	return (left_count + (node->color == RB_BLACK ? 1 : 0));
}

/*
** Return 0 if the tree given does not respect the rules of a rb_tree.
** Return 1 otherwise;
*/

int			rb_validate_tree(t_rb_node *root)
{
	int		left_count;
	int		right_count;

	if (!root)
		return (1);
	if (root->color != RB_BLACK)
		return (0);
	left_count = validate_subtree(root->left);
	right_count = validate_subtree(root->right);
	if (left_count == -1 || right_count == -1)
		return (0);
	return (left_count == right_count);
}
