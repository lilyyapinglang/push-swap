/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_n_push_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:17:45 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 12:53:57 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_node **stack_a, int print)
{
	t_node	*first;
	t_node	*second;
	int		temp_data;
	int		temp_index;

	if (!stack_a && !(*stack_a) && !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	temp_data = first->data;
	temp_index = first->index;
	first->data = second->data;
	first->index = second->index;
	second->data = temp_data;
	second->index = temp_index;
	if (print == 1)
		ft_putstr("sa\n");
}

void	sb(t_node **stack_b, int print)
{
	t_node	*first;
	t_node	*second;
	int		temp_data;
	int		temp_index;

	if (!stack_b && !(*stack_b) && !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	temp_data = first->data;
	temp_index = first->index;
	first->data = second->data;
	first->index = second->index;
	second->data = temp_data;
	second->index = temp_index;
	if (print == 1)
		ft_putstr("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_putstr("ss\n");
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_push;

	if (!stack_b && !(*stack_b))
		return ;
	node_to_push = *stack_b;
	*stack_b = node_to_push->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	node_to_push->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = node_to_push;
	node_to_push->prev = NULL;
	*stack_a = node_to_push;
	ft_putstr("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_push;

	if (!stack_a || !(*stack_a))
		return ;
	node_to_push = *stack_a;
	*stack_a = node_to_push->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	node_to_push->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = node_to_push;
	node_to_push->prev = NULL;
	*stack_b = node_to_push;
	ft_putstr("pb\n");
}
