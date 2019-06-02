/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_apply_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:56:38 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/08 21:57:18 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"

void	rb_apply_prefix(t_rb_node *root, void (*node_funct)(void *))
{
	if (!root)
		return ;
	node_funct(root->data);
	if (root->left)
		rb_apply_prefix(root->left, node_funct);
	if (!(root->right))
		return ;
	rb_apply_prefix(root->right, node_funct);
}
