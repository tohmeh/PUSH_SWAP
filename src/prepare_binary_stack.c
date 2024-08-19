/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_binary_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:42:37 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 09:42:46 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

void	bubble_sort(int arr[], int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

t_N_list	*map_the_elements(int *temp, int n)
{
	t_N_list	*new;
	int			i;

	i = 0;
	new = malloc(sizeof(t_N_list) * n);
	while (i < n)
	{
		new[i].number = temp[i];
		new[i].index = i + 1;
		i++;
	}
	return (new);
}

void	switch_to_natural_arr(int *temp, int n, t_N_list*lst)
{
	int	i;

	i = 0;
	while (i < n)
	{
		temp[i] = find_index(temp[i], lst, n);
		i++;
	}
}

char	*to_binary(int value, int *temp, int size)
{
	int		len;
	char	*result;
	char	*result2;
	int		i;

	i = 0;
	len = maximum_binary_size(temp, size);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = '0';
		i++;
	}
	result[i] = '\0';
	i = 0;
	while (value > 0)
	{
		result[i++] = (value % 2) + '0';
		value = value / 2;
	}
	result2 = reverse_string(result);
	free(result);
	return (result2);
}

t_stack	*to_binary_stk(int *temp, int size)
{
	int		i;
	t_stack	*binary_t_stack;
	char	*binary_str;

	i = size - 1;
	binary_t_stack = NULL;
	while (i >= 0)
	{
		binary_str = to_binary(temp[i], temp, size);
		if (binary_str)
		{
			push(&binary_t_stack, binary_str);
			free(binary_str);
		}
		i--;
	}
	return (binary_t_stack);
}
