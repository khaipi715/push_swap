/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:26:55 by lnaulak           #+#    #+#             */
/*   Updated: 2023/12/12 14:02:37 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	finish_rotation(t_list **stack, t_list *top_node, char stack_name)
{
	while ((*stack)->content != top_node->content)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rotate(stack, 'a');
			else
				rev_rotate(stack, 'a');
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rotate(stack, 'b');
			else
				rev_rotate(stack, 'b');
		}
	}
}

void	move_nodes(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	push(b, a, 'b');
}

void	rotate_both(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap->target_node && *b != cheap)
	{
		rotate(a, 'a');
		rotate(b, 'b');
		write(1, "rr\n", 4);
	}
	set_current_position(*a);
	set_current_position(*b);
}

void	reverse_rotate_both(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap->target_node && *b != cheap)
	{
		rev_rotate(a, 'a');
		rev_rotate(b, 'b');
		write(1, "rrr\n", 5);
	}
	set_current_position(*a);
	set_current_position(*b);
}
