/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:58:12 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 19:37:40 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_len(t_node *begin)
{
	int	i;

	i = 0;
	while (begin)
	{
		i++;
		begin = begin->next;
	}
	return (i);
}

int	get_index(int value, int *sorted, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (i);
}

int	get_cost_to_top(int position, int current_size)
{
	if (position <= current_size / 2)
		return (position);
	return (position - current_size);
}

void	init_node(t_node **node, int *numbers, int i)
{
	t_node	*new_node;

	new_node = *node;
	new_node->data = numbers[i];
	new_node->position = i;
	new_node->cost_to_reinsert = 0;
	new_node->total_cost = 0;
	new_node->target_position_in_a = 0;
	new_node->next = NULL;
}

t_node	*create_stack(int *numbers, int *sorted, int size)
{
	int		i;
	t_node	*head;
	t_node	*prev;
	t_node	*new_node;

	head = NULL;
	prev = NULL;
	i = 0;
	while (i < size)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (NULL);
		init_node(&new_node, numbers, i);
		new_node->index = get_index(numbers[i], sorted, size);
		new_node->cost_to_top = get_cost_to_top(new_node->position, size);
		new_node->prev = prev;
		if (prev)
			prev->next = new_node;
		else
			head = new_node;
		prev = new_node;
		i++;
	}
	return (head);
}
