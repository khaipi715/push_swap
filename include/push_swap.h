/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:24:40 by lnaulak           #+#    #+#             */
/*   Updated: 2023/12/14 14:50:06 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include <stdlib.h>
# include <limits.h>
# include "unistd.h"
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_list
{
	long			content;
	int				push_price;
	int				current_position;
	bool			above_median;
	bool			is_error;
	struct s_list	*next;
	struct s_list	*target_node;
}					t_list;
void				printlist(t_list *stack_a);

//error_check:
void				find_error(char **args, int i, t_list *new);
int					error_check(t_list *stack);
int					dupcheck(t_list *stack);

//commands:
void				swap(t_list **stack, char s);
void				rotate(t_list **stack, char s);
void				rev_rotate(t_list **stack, char s);
void				push(t_list **from, t_list **to, char s);

//utils:
void				sort_three(t_list **stack);
void				sort_five(t_list **stack, t_list **stack2);
void				toomanylinesinafunction(t_list **stack, t_list **stack2);
void				sort(t_list **stack, t_list **stack2);
bool				order(t_list *stack);

//range:
int					find_max(t_list *stack);
int					find_min(t_list *stack);
t_list				*max_node(t_list *stack);
t_list				*min_node(t_list *stack);

//init_nodes:
void				set_target_node(t_list *a, t_list *b);
void				set_current_position(t_list *stack);
void				set_price(t_list *a, t_list *b);
t_list				*return_cheapest(t_list *stack);
void				init_nodes(t_list *a, t_list *b);

//rotate:
void				move_nodes(t_list **a, t_list **b);
void				finish_rotation(t_list **stack, t_list *top_node,
						char stack_name);
void				rotate_both(t_list **a, t_list **b, t_list *cheap);
void				reverse_rotate_both(t_list **a, t_list **b, t_list *cheap);

//libft:
long				ft_atoi(const char *str);
int					ft_isspace(char str);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);

#endif
