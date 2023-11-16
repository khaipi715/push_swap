/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:38:57 by rchallie          #+#    #+#             */
/*   Updated: 2023/11/16 11:42:32 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *t;

	if (*alst)
	{
		printf("yes\n");
		t = ft_lstlast(*alst);
		t->next = new;
		t->next->next = NULL;
	}
	else
	{
		printf("no\n");
		*alst = new;
		new->next = NULL;
	}
}
