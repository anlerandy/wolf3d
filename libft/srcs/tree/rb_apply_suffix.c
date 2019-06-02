/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_apply_suffix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:55:46 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/08 21:56:26 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"

void	rb_apply_suffix(t_rb_node *root, void (*node_funct)(void *))
{
	if (!root)
		return ;
	if (root->left)
		rb_apply_suffix(root->left, node_funct);
	if (root->right)
		rb_apply_suffix(root->right, node_funct);
	node_funct(root->data);
}
