/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_some.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:50:31 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 10:52:33 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../LIBFT/include/LIBFT.h"

void	destroy_2d_char_array(char **array, int rows)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (i < rows)
	{
		if (array[i] != NULL)
			free(array[i]);
		i++;
	}
	free(array);
}

void	destroyt_stack(t_stack **s)
{
	while (!is_empty(*s))
		pop(s);
}
