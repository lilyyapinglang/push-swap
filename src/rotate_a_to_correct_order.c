/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_to_correct_order.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:50:04 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 19:46:42 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find_index0_node(t_node *node)
{
	while (node)
	{
		if (node->index == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	apply_cost_to_rotate_a_to_top(t_node **stack_a,
		int cost_to_rotate_a_to_top)
{
	while (cost_to_rotate_a_to_top)
	{
		if (cost_to_rotate_a_to_top > 0)
		{
			ra(stack_a, 1);
			cost_to_rotate_a_to_top--;
		}
		else
		{
			rra(stack_a, 1);
			cost_to_rotate_a_to_top++;
		}
	}
}

void	rotate_a_to_correct_order(t_node **stack_a)
{
	t_node	*node;
	int		cost_to_rotate_a_to_top;

	if (!stack_a || !*stack_a)
		return ;
	node = find_index0_node(*stack_a);
	if (!node)
		return ;
	cost_to_rotate_a_to_top = node->cost_to_top;
	apply_cost_to_rotate_a_to_top(stack_a, cost_to_rotate_a_to_top);
	update_position(*stack_a, NULL);
}
