/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_level_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:51:31 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/08 21:52:08 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"

int		rb_level_count(t_rb_node *root)
{
	int		left_size;
	int		right_size;

	if (!root)
		return (0);
	left_size = rb_level_count(root->left);
	right_size = rb_level_count(root->right);
	if (left_size > right_size)
		return (1 + left_size);
	return (1 + right_size);
}
