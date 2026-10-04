/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_str_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:44:22 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 20:05:08 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*dup_int_array(int *src, int size)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}

void	sort_int_arr(int *numbers, int size)
{
	int	i;
	int	temp;
	int	is_list_sorted;

	i = 0;
	is_list_sorted = 0;
	while (!is_list_sorted)
	{
		is_list_sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (numbers[i] > numbers[i + 1])
			{
				temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
				is_list_sorted = 0;
			}
			i++;
		}
	}
}

void	check_dup_num(int size, int *numbers, char **strs, int should_free_strs)
{
	int	*tmp;
	int	i;

	tmp = dup_int_array(numbers, size);
	if (!tmp)
		free_and_exit_error(numbers, strs, should_free_strs, NULL);
	sort_int_arr(tmp, size);
	i = 1;
	while (i < size)
	{
		if (tmp[i] == tmp[i - 1])
			free_and_exit_error(numbers, strs, should_free_strs, tmp);
		i++;
	}
	free(tmp);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}
