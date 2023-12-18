/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:48:06 by lnaulak           #+#    #+#             */
/*   Updated: 2023/12/14 13:48:40 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_error(char **args, int i, t_list *new)
{
	long	j;

	j = 0;
	if (args[i][j] == '-')
		j++;
	while (args[i][j])
	{
		if (args[i][j] < '0' || args[i][j] > '9')
		{
			new->is_error = true;
			break ;
		}
		else
			new->is_error = false;
		j++;
		if (j > 11)
			new->is_error = true;
	}
	if (args[i][0] == '-' && j == 1)
		new->is_error = true;
	j = ft_atoi(args[i]);
	if (j < -2147483648 || j > 2147483647)
		new->is_error = true;
}

int	dupcheck(t_list *stack)
{
	t_list	*current;
	t_list	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->content == checker->content)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	error_check(t_list *stack)
{
	t_list	*current;

	current = stack;
	if (dupcheck(stack) == 1)
		return (1);
	if (stack == NULL)
		return (1);
	while (current)
	{
		if (current->is_error == true)
			return (1);
		current = current->next;
	}
	return (0);
}
