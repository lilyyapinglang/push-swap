/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:50:31 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 19:47:58 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*get_min_node(t_node *current, t_node *min)
{
	while (current)
	{
		if (current->index < min->index)
			min = current;
		current = current->next;
	}
	return (min);
}

int	is_fully_sorted(t_node *begin)
{
	while (begin)
	{
		if (begin->index != begin->position)
			return (0);
		begin = begin->next;
	}
	return (1);
}

int	is_rotationaly_sorted(t_node *stack)
{
	t_node	*min;
	t_node	*current;

	min = stack;
	current = stack;
	min = get_min_node(current, min);
	current = min;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	current = stack;
	while (current != min)
	{
		if (current->next && current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

void	push_to_b(t_node **stack_a, t_node **stack_b)
{
	int	j;
	int	i;

	i = 0;
	j = get_stack_len(*stack_a);
	while (i < j && get_stack_len(*stack_a) > 3)
	{
		if ((*stack_a)->index >= j / 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
		i++;
	}
	i = 0;
	while (i < j && get_stack_len(*stack_a) > 3)
	{
		if (((*stack_a)->index < j / 2) && ((*stack_a)->index > 2))
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
		i++;
	}
}

void	sort_stack(t_node **stack_a)
{
	t_node	*stack_b;
	int		stack_a_len;

	stack_b = NULL;
	if (is_fully_sorted(*stack_a))
		return ;
	if (is_rotationaly_sorted(*stack_a))
	{
		rotate_a_to_correct_order(stack_a);
		return ;
	}
	stack_a_len = get_stack_len(*stack_a);
	if (stack_a_len <= 5)
		sort_small_num(stack_a_len, stack_a, &stack_b);
	else
	{
		push_to_b(stack_a, &stack_b);
		sort_a_3(stack_a);
		reinsert_b_to_a(stack_a, &stack_b);
		if (!is_fully_sorted(*stack_a))
			rotate_a_to_correct_order(stack_a);
	}
	if (stack_b)
		free_stack(stack_b);
}
