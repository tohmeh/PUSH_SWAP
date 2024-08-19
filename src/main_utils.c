/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:02:40 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 09:49:50 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

void	printarray(int arr[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");
}

void	copy_array(int *source, int *destination, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
}

void	printt_stack(t_stack *s)
{
	t_stack	*current;

	current = s;
	while (current != NULL)
	{
		ft_printf("%s\n", current->str);
		current = current->next;
	}
}

int	count_words(const char *str, const char *delimiters)
{
	int	i;
	int	count;
	int	inword;

	inword = 0;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (inword == 0 && ft_strchr(delimiters, str[i]) == NULL)
		{
			inword = 1;
			count++;
		}
		else if (ft_strchr(delimiters, str[i]) != NULL)
			inword = 0;
		i++;
	}
	return (count);
}
