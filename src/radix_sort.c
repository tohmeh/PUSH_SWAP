/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:18:10 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 10:52:33 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

void	radixsort_binary(t_stack **inputt_stack, int maxBits)
{
	t_stack	*a;
	t_stack	*b;
	int		bit;
	int		size;
	int		i;

	a = *inputt_stack;
	b = NULL;
	bit = maxBits;
	while (--bit >= 0)
	{
		size = size_of_t_stack(a);
		i = -1;
		while (++i < size)
		{
			if (a->str[bit] == '1')
				ra(&a);
			else
				pb(&a, &b);
		}
		while (!is_empty(b))
			pa(&a, &b);
	}
	*inputt_stack = a;
	destroyt_stack(&b);
}
