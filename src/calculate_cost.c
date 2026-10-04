/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:50:12 by ylang             #+#    #+#             */
/*   Updated: 2025/10/09 19:35:02 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_gap_pos_in_a(t_node *stack_a_head, int target_index)
{
	t_node	*current;
	t_node	*next;
	int		pos;

	current = stack_a_head;
	pos = 0;
	while (current)
	{
		if (current->next)
			next = current->next;
		else
			next = stack_a_head;
		if ((current->index < target_index && target_index < next->index)
			|| (current->index > next->index && (target_index > current->index
					|| target_index < next->index)))
		{
			if (next == stack_a_head)
				return (0);
			return (pos + 1);
		}
		current = current->next;
		pos++;
	}
	return (-1);
}

int	position_to_insert_to_a(t_node *stack_a_head, t_node *node_to_reinsert)
{
	int	pos;

	if (!stack_a_head || !node_to_reinsert)
		return (0);
	pos = find_gap_pos_in_a(stack_a_head, node_to_reinsert->index);
	if (pos != -1)
		return (pos);
	return (0);
}

int	calcualte_reinsert_cost_to_a(t_node *stack_a, t_node *node_in_b)
{
	int	target_position_in_a;
	int	len;

	target_position_in_a = position_to_insert_to_a(stack_a, node_in_b);
	len = get_stack_len(stack_a);
	if (target_position_in_a <= len / 2)
		return (target_position_in_a);
	return (target_position_in_a - len);
}

int	calculate_total_cost(int cost_to_top, int cost_to_reinsert)
{
	int	a;
	int	b;

	a = abs(cost_to_top);
	b = abs(cost_to_reinsert);
	if ((cost_to_top >= 0 && cost_to_reinsert >= 0) || (cost_to_top < 0
			&& cost_to_reinsert < 0))
	{
		if (a > b)
			return (a);
		return (b);
	}
	else
		return (a + b);
}
