/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:31:15 by lnaulak           #+#    #+#             */
/*   Updated: 2023/11/16 11:42:07 by lnaulak          ###   ########.fr       */
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
		printf("*%d\n", *(int *)tmp_a->content);
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
		int val = ft_atoi(split[0]);
		a = ft_lstnew(&val);
		a->next = NULL;
		// a = ft_lstnew();
		t_list *new;
		while (split[++i])
		{
			int val = ft_atoi(split[i]);
			printf("val %d\n", val);
			new = ft_lstnew(&val);
			int *value_new = (int *)new->content;
			printf("s = %p\n", new->content);
			printf("value_new %d\n", *value_new);
			ft_lstadd_back(&a, new);
			// new = NULL;
			// i++;
		}
		printf("\n");
		// printlist(a, new);
		printlist(a);
	}
	else
		return (1);
	return (0);
}