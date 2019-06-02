/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_search_infix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:58:25 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/30 10:20:17 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_btree_rb.h"

void	*rb_search_infix(t_rb_node *root, void *data_ref, \
			int (*cmp_funct)(void *, void *))
{
	t_rb_node		*left_res;

	if (!root)
		return (NULL);
	if (!cmp_funct(root->data, data_ref))
		return (root->data);
	left_res = rb_search_infix(root->left, data_ref, cmp_funct);
	if (left_res)
		return (left_res);
	return (rb_search_infix(root->right, data_ref, cmp_funct));
}
