/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:00:32 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 09:36:39 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

int	handle_input(char **argv, int *n, char ***input, const char *delimiters)
{
	if (*n == 1)
	{
		if (count_words(argv[1], delimiters) >= 1)
		{
			*n = count_words(argv[1], delimiters);
			*input = ft_split(argv[1], delimiters);
			if (*input == NULL || is_within_int_bounds((*input)[0]) == 0)
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
		else
			return (0);
	}
	else
	{
		*input = &argv[1];
	}
	if (*n == 0)
		return (0);
	return (1);
}

int	validate_array(int argc, int *temp, int number_of_elements, char **input)
{
	if (temp == NULL || duplicate_check(temp, number_of_elements) == 0)
	{
		write(2, "Error\n", 6);
		if (argc == 2)
			destroy_2d_char_array(input, number_of_elements);
		free(temp);
		return (0);
	}
	if (sorted_check(temp, number_of_elements) == 0)
	{
		if (argc == 2)
			destroy_2d_char_array(input, number_of_elements);
		free(temp);
		return (0);
	}
	return (1);
}

void	sort(t_stack **b_t_stack, int *t, int n)
{
	t_stack	*b;

	if (n <= 5)
	{
		b = NULL;
		optimize_small_sort(b_t_stack, &b, t);
		destroyt_stack(b_t_stack);
		free(t);
	}
	else
	{
		radixsort_binary(b_t_stack, maximum_binary_size(t, n));
		destroyt_stack(b_t_stack);
		free(t);
	}
}

int	main(int argc, char **argv)
{
	int			*temp;
	int			number_of_elements;
	t_stack		*binary_t_stack;
	char		**input;
	const char	*delimiters = " \t\n\v\f\r";

	number_of_elements = argc - 1;
	input = NULL;
	if (!handle_input(argv, &number_of_elements, &input, delimiters))
		return (0);
	temp = to_normal_array(input, number_of_elements);
	if (!validate_array(argc, temp, number_of_elements, input))
		return (0);
	binary_t_stack = to_binary_stk(temp, number_of_elements);
	sort(&binary_t_stack, temp, number_of_elements);
	if (argc == 2)
	{
		destroy_2d_char_array(input, number_of_elements);
	}
	return (0);
}
