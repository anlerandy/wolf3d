/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rb.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:30:40 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/27 18:47:28 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_RB_H
# define FT_BTREE_RB_H

typedef enum	e_rb_color
{
	RB_BLACK,
	RB_RED
}				t_rb_color;

typedef struct	s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*left;
	struct s_rb_node	*right;
	void				*data;
	t_rb_color			color;
}				t_rb_node;

t_rb_node		*rb_grand_father(t_rb_node *node);
t_rb_node		*rb_brother(t_rb_node *node);
t_rb_node		*rb_uncle(t_rb_node *node);
t_rb_node		*rb_get_root(t_rb_node *node);
t_rb_node		**rb_rot_node(t_rb_node **root, t_rb_node *node);
void			rb_rotation_left(t_rb_node **root, t_rb_node *node);
void			rb_rotation_right(t_rb_node **root, t_rb_node *node);
void			rb_insert(t_rb_node **root, void *data, \
					int (*cmpf)(void *, void *));
void			rb_remove(t_rb_node **root, void *data, \
					int (*cmpf)(void *, void *), void (*freef)(void *));
void			rb_fix_black_node(t_rb_node **root, t_rb_node *old_node);
void			rb_clear_tree(t_rb_node **root, void (*freef)(void *));

void			rb_apply_by_level(t_rb_node *root, void (*applyf)(void *item, \
						int current_level, int is_first_elem));
void			rb_apply_infix(t_rb_node *root, void (*node_funct)(void *));
void			rb_apply_prefix(t_rb_node *root, void (*node_funct)(void *));
void			rb_apply_suffix(t_rb_node *root, void (*node_funct)(void *));
int				rb_level_count(t_rb_node *root);
void			*rb_search_infix(t_rb_node *root, void *data_ref, \
					int (*cmp_funct)(void *, void *));

int				rb_validate_tree(t_rb_node *root);
#endif
