/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:56:28 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 10:52:33 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

int	pa(t_stack **A, t_stack **B)
{
	if (is_empty(*B))
		return (0);
	push(A, (*B)->str);
	pop(B);
	ft_printf("pa\n");
	return (1);
}

int	pb(t_stack **A, t_stack **B)
{
	if (is_empty(*A))
		return (0);
	push(B, (*A)->str);
	pop(A);
	ft_printf("pb\n");
	return (1);
}

int	ra(t_stack **A)
{
	t_stack	*first;
	t_stack	*current;

	if (*A == NULL || (*A)->next == NULL)
		return (0);
	first = *A;
	current = *A;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = first;
	*A = first->next;
	first->next = NULL;
	ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **B)
{
	t_stack	*first;
	t_stack	*current;

	if (*B == NULL || (*B)->next == NULL)
		return (0);
	first = *B;
	current = *B;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = first;
	(*B) = first->next;
	first->next = NULL;
	ft_printf("rb\n");
	return (1);
}

int	rr(t_stack **A, t_stack **B)
{
	if (!ra(A) || !rb(B))
		return (0);
	ft_printf("rr\n");
	return (1);
}
