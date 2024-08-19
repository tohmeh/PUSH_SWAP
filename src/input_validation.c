/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:51:20 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 10:49:42 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

int	sorted_check(int *temp, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (temp[i] > temp[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	only_numbers_check(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	w_ut(const char *str, int is_neg, const char *int_min, const char *int_max)
{
	const char	*compare_str;
	int			i;

	i = 0;
	if (is_neg)
	{
		compare_str = int_min;
	}
	else
		compare_str = int_max;
	while (i < 10)
	{
		if (str[i] < compare_str[i])
			return (1);
		else if (str[i] > compare_str[i])
			return (0);
		i++;
	}
	if (is_neg && ft_strncmp(str, int_min, 11) == 0)
		return (1);
	return (1);
}

int	is_within_int_bounds(const char *str)
{
	const char	*int_max_str;
	const char	*int_min_str;
	int			is_negative;
	int			len;

	is_negative = 0;
	int_max_str = "2147483647";
	int_min_str = "2147483648";
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		is_negative = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	len = ft_strlen(str);
	if (len > 10)
		return (0);
	else if (len < 10)
		return (1);
	return (w_ut(str, is_negative, int_min_str, int_max_str));
}
