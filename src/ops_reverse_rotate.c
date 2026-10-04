/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:20:40 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 12:53:19 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_node **stack_a, int print)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	first = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack_a = last;
	if (print == 1)
		ft_putstr("rra\n");
}

void	rrb(t_node **stack_b, int print)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	first = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack_b = last;
	if (print == 1)
		ft_putstr("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_putstr("rrr\n");
}
