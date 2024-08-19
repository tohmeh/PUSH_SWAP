/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:25:01 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 09:36:39 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

int	rra(t_stack **A)
{
	t_stack	*beforelast;
	t_stack	*last;

	if (*A == NULL || (*A)->next == NULL)
		return (0);
	beforelast = *A;
	while ((beforelast->next)->next != NULL)
		beforelast = beforelast->next;
	last = beforelast->next;
	beforelast->next = NULL;
	last->next = *A;
	*A = last;
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **B)
{
	t_stack	*beforelast;
	t_stack	*last;

	if (*B == NULL || (*B)->next == NULL)
		return (0);
	beforelast = *B;
	while ((beforelast->next)->next != NULL)
		beforelast = beforelast->next;
	last = beforelast->next;
	beforelast->next = NULL;
	last->next = *B;
	*B = last;
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack **A, t_stack **B)
{
	if (!rra(A) || !rrb(B))
		return (0);
	ft_printf("rrr\n");
	return (1);
}

int	sa(t_stack **A)
{
	t_stack	*first;
	t_stack	*second;

	first = *A;
	second = (*A)->next;
	if (*A == NULL || (*A)->next == NULL)
		return (0);
	first->next = second->next;
	second->next = first;
	*A = second;
	ft_printf("sa\n");
	return (1);
}

int	sb(t_stack **B)
{
	t_stack	*first;
	t_stack	*second;

	if (*B == NULL || (*B)->next == NULL)
		return (0);
	first = *B;
	second = (*B)->next;
	first->next = second->next;
	second->next = first;
	*B = second;
	ft_printf("sb\n");
	return (1);
}
