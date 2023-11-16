/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:31:15 by lnaulak           #+#    #+#             */
/*   Updated: 2023/11/16 12:45:53 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void pushToB(t_list **stack_a, t_list **stack_b)
{
    t_list *poppedNode = *stack_a;
    *stack_a = poppedNode->next;

    // Push the popped node to stack_b
    poppedNode->next = *stack_b;
    *stack_b = poppedNode;
}

// void printlist(t_list *stack_a, t_list *stack_b)
// {
// 	t_list *tmp_a = stack_a;
// 	t_list *tmp_b = stack_b;
// 	printf("stack_A:\t stack_B:\n");
// 	while (tmp_a || tmp_b)
// 	{
// 		if (tmp_b)
// 		{
// 			printf("\t\t*%d\n", *(int *)tmp_b->content);
// 			tmp_b = tmp_b->next;
// 		}
// 		printf("*%d\n", *(int *)tmp_a->content);
// 		tmp_a = tmp_a->next;
// 	}
// }


void printlist(t_list *stack_a)
{
	t_list *tmp_a = stack_a;

	// printf("stack_A:\t stack_B:\n");
	while (tmp_a)
	{
		printf("*%p\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*list;
	t_list	*newnode;
	char	**split;
	int		i;
	// int		val;

	list = NULL;
	split = ft_split(av[1], ' ');
	if (ac == 2)
	{
		i = 0;
		while (split[++i])
		{
			newnode = ft_lstnew((int *)(intptr_t)ft_atoi(split[i]));
			ft_lstadd_back(&list, newnode);
		}
		printlist(list);
	}
	else
		return (1);
	return (0);
}