/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:43:49 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 20:31:41 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	handle_error(int *error)
{
	*error = 1;
	return (0);
}

char	*handle_prefix(char *str, int *sign)
{
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

int	ft_atoi_with_overflow_check(char *str, int *error)
{
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	*error = 0;
	str = handle_prefix(str, &sign);
	if (*str == '\0')
		return (handle_error(error));
	while (*str >= '0' && *str <= '9')
	{
		nbr = 10 * nbr + (*str - 48);
		if ((sign == 1 && nbr > INT_MAX) || (sign == -1 && (-nbr) < INT_MIN))
			return (*error = 1, 0);
		str++;
	}
	if (*str != '\0')
		return (handle_error(error));
	return ((int)(nbr * sign));
}

static int	parse_one_str(char *str, int *out)
{
	int	error;

	error = 0;
	if (!is_all_digit(str))
		return (-1);
	*out = ft_atoi_with_overflow_check(str, &error);
	if (error)
		return (-1);
	return (0);
}

void	check_strs_validity(char **strs, int should_free_strs, int *numbers)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (parse_one_str(strs[i], &numbers[i]) < 0)
		{
			if (should_free_strs)
				free_split(strs);
			free(numbers);
			exit_with_error();
		}
		i++;
	}
}
