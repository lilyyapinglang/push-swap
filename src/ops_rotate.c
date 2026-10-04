/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:20:42 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 12:53:22 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_node **stack_a, int print)
{
	t_node	*first;
	t_node	*ptr;

	first = *stack_a;
	ptr = *stack_a;
	while (ptr->next)
		ptr = ptr->next;
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	ptr->next = first;
	first->prev = ptr;
	first->next = NULL;
	if (print == 1)
		ft_putstr("ra\n");
}

void	rb(t_node **stack_b, int print)
{
	t_node	*first;
	t_node	*ptr;

	first = *stack_b;
	ptr = *stack_b;
	while (ptr->next)
		ptr = ptr->next;
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	ptr->next = first;
	first->prev = ptr;
	first->next = NULL;
	if (print == 1)
		ft_putstr("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_putstr("rr\n");
}
