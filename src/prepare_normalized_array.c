/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_normalized_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:56:24 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 09:42:05 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

int	*init_array(int size)
{
	int	*array;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	return (array);
}

int	*convert_to_int_array(char **str, int *result, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!only_numbers_check(str[i]) || !is_within_int_bounds(str[i]))
			return (NULL);
		result[i] = ft_atoi(str[i]);
		i++;
	}
	return (result);
}

int	*to_normal_array(char **str, int size)
{
	int			*result;
	int			*temp;
	t_N_list	*number_map;

	result = init_array(size);
	temp = init_array(size);
	if (!(result) || !(temp))
		return (NULL);
	if (!convert_to_int_array(str, result, size))
		return (free(result), free(temp), NULL);
	copy_array(result, temp, size);
	bubble_sort(temp, size);
	number_map = map_the_elements(temp, size);
	if (!number_map)
		return (free(result), free(temp), NULL);
	switch_to_natural_arr(result, size, number_map);
	return (free(number_map), free(temp), result);
}
