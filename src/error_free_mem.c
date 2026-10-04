/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:49:14 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 19:37:20 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_num(int *num)
{
	free(num);
}

void	exit_with_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_and_exit_error(int *numbers, char **strs, int should_free_strs,
		int *tmp)
{
	if (tmp)
		free(tmp);
	if (should_free_strs)
		free_split(strs);
	free(numbers);
	exit_with_error();
}
