/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:55:44 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 10:33:48 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

void	sort_three(t_stack **A, int *arr)
{
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
		sa(A);
	else if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		sa(A);
		rra(A);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
		ra(A);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
	{
		sa(A);
		ra(A);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
		rra(A);
}

void	sort_four(t_stack **A, t_stack **B, int *arr)
{
	int	minindex;
	int	i;
	int	*newarr;

	i = 0;
	minindex = find_min_index(arr, 4);
	while (i < minindex)
	{
		ra(A);
		i++;
	}
	pb(A, B);
	newarr = t_stack_to_int_array(*A, 3);
	sort_three(A, newarr);
	free(newarr);
	pa(A, B);
}

void	sort_five(t_stack **A, t_stack **B, int *arr)
{
	int	minindex;
	int	i;
	int	*newarray;

	i = 0;
	minindex = find_min_index(arr, 5);
	while (i < minindex)
	{
		ra(A);
		i++;
	}
	pb(A, B);
	newarray = t_stack_to_int_array(*A, 4);
	sort_four(A, B, newarray);
	free(newarray);
	pa(A, B);
}

void	optimize_small_sort(t_stack **A, t_stack **B, int *arr)
{
	int	size;

	size = size_of_t_stack(*A);
	if (size == 1)
		return ;
	if (size == 2)
	{
		if (arr[0] > arr[1])
			sa(A);
	}
	else if (size == 3)
	{
		sort_three(A, arr);
	}
	else if (size == 4)
	{
		sort_four(A, B, arr);
	}
	else if (size == 5)
	{
		sort_five(A, B, arr);
	}
}
