/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:16:57 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 10:52:40 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

int	push(t_stack **s, const char *value)
{
	t_stack	*newt_stack;

	newt_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!newt_stack)
		return (0);
	newt_stack->str = malloc(ft_strlen(value) + 1);
	newt_stack->next = NULL;
	if (!newt_stack->str)
	{
		free(newt_stack);
		return (0);
	}
	ft_strlcpy(newt_stack->str, value, ft_strlen(value) + 1);
	if (*s == NULL)
	{
		*s = newt_stack;
		return (1);
	}
	newt_stack->next = *s;
	*s = newt_stack;
	return (1);
}

int	pop(t_stack **s)
{
	t_stack	*temp;

	if (*s == NULL)
		return (0);
	temp = *s;
	*s = (*s)->next;
	free(temp->str);
	free(temp);
	return (1);
}

char	*peek(t_stack *s)
{
	if (s == NULL)
		return (NULL);
	return (s->str);
}

int	is_empty(t_stack *s)
{
	return (s == NULL);
}
