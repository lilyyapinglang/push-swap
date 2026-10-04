/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smallnumebrs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:29:52 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 12:53:36 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_small_num(int stack_a_len, t_node **stack_a, t_node **stack_b)
{
	if (stack_a_len == 2)
		sort_a_2(stack_a);
	if (stack_a_len == 3)
		sort_a_3(stack_a);
	if (stack_a_len == 4)
		sort_a_4(stack_a, stack_b);
	if (stack_a_len == 5)
		sort_a_5(stack_a, stack_b);
}

void	sort_a_2(t_node **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a, 1);
	}
}

void	sort_a_3(t_node **stack_a)
{
	t_node	*h;
	int		a;
	int		b;
	int		c;

	h = *stack_a;
	if (!h || !h->next || !h->next->next)
		return ;
	a = h->data;
	b = h->next->data;
	c = h->next->next->data;
	if (a > c && a > b)
		ra(stack_a, 1);
	else if (b > a && b > c)
		rra(stack_a, 1);
	h = *stack_a;
	a = h->data;
	b = h->next->data;
	if (a > b)
		sa(stack_a, 1);
}

void	sort_a_4(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	int		a;
	int		b;
	int		c;
	int		d;

	current = *stack_a;
	a = current->data;
	b = current->next->data;
	c = current->next->next->data;
	d = current->next->next->next->data;
	if (b < a && b < c && b < d)
		sa(stack_a, 1);
	else if (c < a && c < b && c < d)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (d < a && d < b && d < c)
		rra(stack_a, 1);
	pb(stack_a, stack_b);
	sort_a_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_a_5(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = get_stack_len(*stack_a);
	while (len > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			pb(stack_a, stack_b);
			len--;
		}
		else
			ra(stack_a, 1);
	}
	sort_a_3(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, 1);
}
