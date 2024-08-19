/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_binary_stack_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:00:40 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 09:41:51 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

int	find_index(int num, t_N_list *lst, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (lst[i].number == num)
		{
			return (lst[i].index);
		}
		i++;
	}
	return (-1);
}

int	maximum_binary_size(int *temp, int n)
{
	int	i;
	int	count;
	int	max;

	max = temp[0];
	count = 0;
	i = 0;
	while (i < n)
	{
		if (temp[i] > max)
			max = temp[i];
		i++;
	}
	while (max > 0)
	{
		max = max / 2;
		count++;
	}
	return (count);
}

char	*reverse_string(const char *str)
{
	int		length;
	char	*result;
	int		i;

	i = 0;
	length = ft_strlen(str);
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	while (i < length)
	{
		result[i] = str[length - i - 1];
		i++;
	}
	result[length] = '\0';
	return (result);
}
