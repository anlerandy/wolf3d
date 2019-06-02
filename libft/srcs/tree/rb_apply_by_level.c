/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_apply_by_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:52:27 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/08 21:53:46 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"

static int	rb_apply_recurs(t_rb_node *node, int curr_level, \
				int (*levels)[2], void (*applyf)(void *item, \
					int current_level, int is_first_elem))
{
	int		res;

	if (!node)
		return (0);
	if ((*levels)[1] == curr_level)
	{
		(*applyf)(node->data, curr_level, curr_level > (*levels)[0]);
		(*levels)[0] += curr_level > (*levels)[0];
		return (1);
	}
	res = rb_apply_recurs(node->left, curr_level + 1, levels, applyf);
	res += rb_apply_recurs(node->right, curr_level + 1, levels, applyf);
	return (res);
}

void		rb_apply_by_level(t_rb_node *root, \
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		levels[2];

	if (!root)
		return ;
	levels[0] = -1;
	levels[1] = 0;
	while (rb_apply_recurs(root, 0, &levels, applyf))
		levels[1] += 1;
}
