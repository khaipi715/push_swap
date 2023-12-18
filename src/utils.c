/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:03:31 by lnaulak           #+#    #+#             */
/*   Updated: 2023/12/14 14:51:36 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_list **stack)
{
	if ((*stack)->next == NULL)
		return ;
	if (find_max(*stack) == 1)
		rotate(stack, 'a');
	else if (find_max(*stack) == 2)
		rev_rotate(stack, 'a');
	if ((*stack)->content > (*stack)->next->content)
		swap(stack, 'a');
}

void	sort_five(t_list **stack, t_list **stack2)
{
	while ((*stack2))
	{
		if ((*stack)->next->content > (*stack2)->content)
		{
			if ((*stack)->content > (*stack2)->content)
				push(stack2, stack, 'a');
			else
			{
				push(stack2, stack, 'a');
				swap(stack, 'a');
			}
		}
		else if ((*stack)->next->content < (*stack2)->content)
			toomanylinesinafunction(stack, stack2);
		else
			*stack2 = (*stack2)->next;
	}
}

void	toomanylinesinafunction(t_list **stack, t_list **stack2)
{
	if ((*stack2)->content > ft_lstlast(*stack)->content)
	{
		push(stack2, stack, 'a');
		rotate(stack, 'a');
	}
	else
	{
		rev_rotate(stack, 'a');
		push(stack2, stack, 'a');
		rotate(stack, 'a');
		rotate(stack, 'a');
	}
}

bool	order(t_list *stack)
{
	bool	i;

	while (stack->next)
	{
		if (stack->content < stack->next->content)
			i = true;
		if (stack->content > stack->next->content)
		{
			i = false;
			break ;
		}
		stack = stack->next;
	}
	return (i);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		i;

	i = ft_lstsize(*stack_a);
	if (i == 5)
	{
		push(stack_a, stack_b, 'b');
		push(stack_a, stack_b, 'b');
		sort_three(stack_a);
		sort_five(stack_a, stack_b);
	}
	else
	{
		while (i-- > 3)
			push(stack_a, stack_b, 'b');
		sort_three(stack_a);
	}
}
