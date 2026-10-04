/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinsert_b_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:50:18 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 19:53:04 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*get_min_cost_node_from_b(t_node *head)
{
	t_node	*min_cost_node;

	min_cost_node = NULL;
	while (head)
	{
		if (head->index > 2)
		{
			if (!min_cost_node || head->total_cost < min_cost_node->total_cost)
				min_cost_node = head;
		}
		head = head->next;
	}
	return (min_cost_node);
}

void	reinsert_b_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*min_cost_node;

	while (*stack_b)
	{
		update_position(*stack_a, *stack_b);
		min_cost_node = get_min_cost_node_from_b(*stack_b);
		rotate_both_stacks_to_prepare(stack_a, stack_b, min_cost_node);
		pa(stack_a, stack_b);
		update_position(*stack_a, *stack_b);
	}
}
