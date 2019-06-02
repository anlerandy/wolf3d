/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_apply_infix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:50:52 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/08 21:51:02 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"

void	rb_apply_infix(t_rb_node *root, void (*node_funct)(void *))
{
	if (!root)
		return ;
	if (root->left)
		rb_apply_infix(root->left, node_funct);
	node_funct(root->data);
	if (!(root->right))
		return ;
	rb_apply_infix(root->right, node_funct);
}
