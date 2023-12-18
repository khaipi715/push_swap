/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:31:15 by lnaulak           #+#    #+#             */
/*   Updated: 2023/12/18 11:22:02 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	printlist(t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		printf("position(%d): %ld\n", ++i, stack_a->content);
		stack_a = stack_a->next;
	}
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*(stack) = (NULL);
}

void	engine(t_list **stack_a, t_list **stack_b)
{
	t_list	*newnode;

	while ((*stack_b))
	{
		init_nodes(*stack_a, *stack_b);
		move_nodes(stack_a, stack_b);
	}
	set_current_position(*stack_a);
	newnode = min_node(*stack_a);
	if (newnode->above_median)
		while ((*stack_a)->content != newnode->content)
			rotate(stack_a, 'a');
	else
		while ((*stack_a)->content != newnode->content)
			rev_rotate(stack_a, 'a');
}

void	initstack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		find_error(args, i, new);
		ft_lstadd_back(stack, new);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		return (-1);
	stack_a = NULL;
	stack_b = NULL;
	initstack(&stack_a, ac, av);
	if (error_check(stack_a) == 1)
	{
		free_stack(&stack_a);
		write (1, "Error\n", 7);
		return (1);
	}
	if (order(stack_a) == true)
	{
		free_stack(&stack_a);
		return (0);
	}
	sort(&stack_a, &stack_b);
	engine(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
