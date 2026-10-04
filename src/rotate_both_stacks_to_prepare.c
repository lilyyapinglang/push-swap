/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:50:25 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 17:01:14 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both_stacks(int *cost_to_b_top, int *cost_to_a_top,
		t_node **stack_a, t_node **stack_b)
{
	if (*cost_to_b_top < 0 && *cost_to_a_top < 0)
	{
		while (*cost_to_b_top && *cost_to_a_top)
		{
			rrr(stack_a, stack_b);
			update_position(*stack_a, *stack_b);
			(*cost_to_b_top)++;
			(*cost_to_a_top)++;
		}
	}
	else if (*cost_to_b_top > 0 && *cost_to_a_top > 0)
	{
		while (*cost_to_b_top && *cost_to_a_top)
		{
			rr(stack_a, stack_b);
			update_position(*stack_a, *stack_b);
			(*cost_to_b_top)--;
			(*cost_to_a_top)--;
		}
	}
}

static void	rotate_b_until_top(int *cost_to_b_top, t_node **stack_a,
		t_node **stack_b)
{
	while (*cost_to_b_top)
	{
		if (*cost_to_b_top > 0)
		{
			rb(stack_b, 1);
			(*cost_to_b_top)--;
		}
		else
		{
			rrb(stack_b, 1);
			(*cost_to_b_top)++;
		}
		update_position(*stack_a, *stack_b);
	}
}

static void	rotate_a_until_top(int *cost_to_a_top, t_node **stack_a,
		t_node **stack_b)
{
	while (*cost_to_a_top)
	{
		if (*cost_to_a_top > 0)
		{
			ra(stack_a, 1);
			(*cost_to_a_top)--;
		}
		else
		{
			rra(stack_a, 1);
			(*cost_to_a_top)++;
		}
		update_position(*stack_a, *stack_b);
	}
}

void	rotate_the_rest(int *cost_to_b_top, int *cost_to_a_top,
		t_node **stack_a, t_node **stack_b)
{
	rotate_b_until_top(cost_to_b_top, stack_a, stack_b);
	rotate_a_until_top(cost_to_a_top, stack_a, stack_b);
}

void	rotate_both_stacks_to_prepare(t_node **stack_a, t_node **stack_b,
		t_node *min_cost_node)
{
	int		cost_to_b_top;
	int		target_pos_in_a;
	t_node	*target_node;
	int		cost_to_a_top;

	cost_to_b_top = min_cost_node->cost_to_top;
	target_pos_in_a = min_cost_node->target_position_in_a;
	target_node = *stack_a;
	while (target_node && target_node->position != target_pos_in_a)
		target_node = target_node->next;
	if (!target_node)
		exit_with_error();
	cost_to_a_top = target_node->cost_to_top;
	rotate_both_stacks(&cost_to_b_top, &cost_to_a_top, stack_a, stack_b);
	rotate_the_rest(&cost_to_b_top, &cost_to_a_top, stack_a, stack_b);
}
