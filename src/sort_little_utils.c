/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:03:37 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 09:57:17 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

int	binary_to_int(const char *binary)
{
	int	value;

	value = 0;
	while (*binary)
	{
		value = (value << 1) + (*binary++ - '0');
	}
	return (value);
}

int	*t_stack_to_int_array(t_stack *head, int size)
{
	int		*intarray;
	t_stack	*current;
	int		index;

	intarray = (int *)malloc(size * sizeof(int));
	if (!intarray)
		return (NULL);
	current = head;
	index = 0;
	while (current && index < size)
	{
		intarray[index++] = binary_to_int(current->str);
		current = current->next;
	}
	return (intarray);
}

void	reverse_switch_index1(int *temp)
{
	int	a;

	a = temp[4];
	temp[4] = temp[0];
	temp[0] = temp[1];
	temp[1] = temp[2];
	temp[2] = temp[3];
	temp[3] = a;
}

int	find_min_index(int *arr, int size)
{
	int	minindex;
	int	i;

	i = 0;
	minindex = 0;
	while (i < size)
	{
		if (arr[i] < arr[minindex])
			minindex = i;
		i++;
	}
	return (minindex);
}

int	size_of_t_stack(t_stack *A)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = A;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
