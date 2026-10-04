/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:42:38 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 19:41:59 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**parse_args(int ac, char **av, int *should_free_strs)
{
	char	**strs;

	if (ac == 2)
	{
		strs = ft_split(av[1], ' ');
		if (!strs)
			exit_with_error();
		*should_free_strs = 1;
		return (strs);
	}
	*should_free_strs = 0;
	return (&av[1]);
}

static int	strs_len(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

static void	run_push_swap(char **strs, int should_free_strs, int size)
{
	int		*numbers;
	int		*copy;
	t_node	*stack_a;

	numbers = malloc(sizeof(int) * size);
	if (!numbers)
	{
		if (should_free_strs)
			free_split(strs);
		exit_with_error();
	}
	check_strs_validity(strs, should_free_strs, numbers);
	check_dup_num(size, numbers, strs, should_free_strs);
	copy = dup_int_array(numbers, size);
	if (!copy)
		free_and_exit_error(numbers, strs, should_free_strs, NULL);
	sort_int_arr(copy, size);
	stack_a = create_stack(numbers, copy, size);
	if (!stack_a)
		free_and_exit_error(numbers, strs, should_free_strs, copy);
	sort_stack(&stack_a);
	free(copy);
	free(numbers);
	free_stack(stack_a);
}

int	main(int ac, char **av)
{
	char	**strs;
	int		should_free_strs;
	int		size;

	if (ac < 2)
		return (0);
	strs = parse_args(ac, av, &should_free_strs);
	size = strs_len(strs);
	if (size == 0)
	{
		if (should_free_strs)
			free_split(strs);
		exit_with_error();
	}
	run_push_swap(strs, should_free_strs, size);
	if (should_free_strs)
		free_split(strs);
	return (0);
}
