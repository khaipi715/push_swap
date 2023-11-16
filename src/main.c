/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:31:15 by lnaulak           #+#    #+#             */
/*   Updated: 2023/11/16 12:15:58 by mehdimirzai      ###   ########.fr       */
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

	printf("stack_A:\t stack_B:\n");
	while (tmp_a)
	{
		// printf("%d\n", *(int *)tmp_a->content);
		printf("%d\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}
}

int	main(int ac, char **av)
{

	t_list	*a = NULL;
	int	i = 0;
	if (ac == 2)
	{
		// t_list new;
		char	**split;

		
		// a = malloc(sizeof(t_list));
		split = ft_split(av[1], ' ');
		a = ft_lstnew(ft_atoi(split[0]));
		a->next = NULL;
		// a = ft_lstnew();
		t_list *new;
		// int *val;
		while (split[++i])
		{
			// new = ft_lstnew((void*)(intptr_t)ft_atoi(split[i]));
			new = ft_lstnew(ft_atoi(split[i]));
			ft_lstadd_back(&a, new);
		}
		printlist(a);
	}
	else
		return (1);
	return (0);
}