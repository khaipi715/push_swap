/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:02:48 by utente            #+#    #+#             */
/*   Updated: 2023/12/12 13:38:43 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_current_position(t_list *stack)
{
	int	i;
	int	centerline;

	i = 0;
	centerline = ft_lstsize(stack) / 2;
	while (stack)
	{
		i++;
		stack->current_position = i;
		if (stack->current_position <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
	}
}

void	set_target_node(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->content > b->content
				&& current_a->content < best_match_index)
			{
				best_match_index = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

t_list	*return_cheapest(t_list *stack)
{
	t_list	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (cheapest->push_price > stack->push_price)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	init_nodes(t_list *a, t_list *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
}
