/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:03:31 by lnaulak           #+#    #+#             */
/*   Updated: 2023/12/14 15:35:44 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_list **stack, char s)
{
	t_list	*temp;

	temp = *stack;
	if (!stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (s == 'b')
		write(1, "sb\n", 4);
	else
		write(1, "sa\n", 4);
}

void	rotate(t_list **stack, char s)
{
	t_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	(temp)->next = NULL;
	ft_lstadd_back(stack, temp);
	if (s == 'b')
		write(1, "rb\n", 4);
	else
		write(1, "ra\n", 4);
}

void	rev_rotate(t_list **stack, char s)
{
	t_list	*temp;
	long	i;

	temp = *stack;
	*stack = (ft_lstlast(*stack));
	i = ((long)(*stack)->content);
	(*stack)->next = temp;
	while ((long)(*stack)->next->content != i)
		stack = &(*stack)->next;
	(*stack)->next = NULL;
	if (s == 'b')
		write(1, "rrb\n", 5);
	else
		write(1, "rra\n", 5);
}

void	push(t_list **from, t_list **to, char s)
{
	t_list	*new;

	if ((*from) == NULL)
		return ;
	new = *from;
	*from = (*from)->next;
	if (!to)
	{
		*to = new;
		(*to)->next = NULL;
	}
	else
	{
		new->next = *to;
		*to = new;
	}
	if (s == 'b')
		write(1, "pb\n", 4);
	else
		write(1, "pa\n", 4);
}
