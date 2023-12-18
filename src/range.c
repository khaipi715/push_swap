/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:57:10 by lnaulak           #+#    #+#             */
/*   Updated: 2023/12/12 13:39:59 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_max(t_list *stack)
{
	int	temp_content;
	int	i;
	int	j;

	i = 0;
	temp_content = stack->content;
	while (stack)
	{
		i++;
		if (stack->content >= temp_content)
		{
			j = i;
			temp_content = stack->content;
		}
		stack = stack->next;
	}
	return (j);
}

int	find_min(t_list *stack)
{
	int	temp_content;
	int	i;
	int	j;

	i = 0;
	temp_content = stack->content;
	while (stack)
	{
		if (stack->content <= temp_content)
		{
			j = i;
			temp_content = stack->content;
		}
		i++;
		stack = stack->next;
	}
	return (j);
}

t_list	*max_node(t_list *stack)
{
	int	i;
	int	j;

	j = find_max(stack);
	i = 0;
	while (i++ < j)
		stack = stack->next;
	return (stack);
}

t_list	*min_node(t_list *stack)
{
	int	i;
	int	j;

	if (stack == NULL)
		return (NULL);
	j = find_min(stack);
	i = 0;
	while (i < j)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}
