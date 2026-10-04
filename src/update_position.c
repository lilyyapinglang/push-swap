/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:50:43 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 19:44:01 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_pos_stack_a(t_node *stack_a)
{
	int	i;
	int	cost_to_top;
	int	stack_a_len;

	i = 0;
	stack_a_len = get_stack_len(stack_a);
	while (stack_a)
	{
		cost_to_top = get_cost_to_top(i, stack_a_len);
		stack_a->position = i;
		stack_a->cost_to_top = cost_to_top;
		stack_a = stack_a->next;
		i++;
	}
}

void	update_pos_stack_b(t_node *stack_a_head, t_node *stack_b)
{
	int	i;
	int	stack_b_len;
	int	cost_to_top;
	int	cost_to_reinsert;

	i = 0;
	stack_b_len = get_stack_len(stack_b);
	while (stack_b)
	{
		cost_to_top = get_cost_to_top(i, stack_b_len);
		cost_to_reinsert = calcualte_reinsert_cost_to_a(stack_a_head, stack_b);
		stack_b->position = i;
		stack_b->cost_to_top = cost_to_top;
		stack_b->cost_to_reinsert = cost_to_reinsert;
		stack_b->total_cost = calculate_total_cost(cost_to_top,
				cost_to_reinsert);
		stack_b->target_position_in_a = position_to_insert_to_a(stack_a_head,
				stack_b);
		stack_b = stack_b->next;
		i++;
	}
}

void	update_position(t_node *stack_a, t_node *stack_b)
{
	t_node	*stack_a_head;

	stack_a_head = stack_a;
	update_pos_stack_a(stack_a);
	update_pos_stack_b(stack_a_head, stack_b);
}
