/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/06 03:25:33 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_sign(const char **nptr)
{
	int	sign;

	sign = 1;
	while (**nptr == ' ' || (**nptr >= 9 && **nptr <= 13))
		(*nptr)++;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			sign = -1;
		(*nptr)++;
	}
	if (**nptr == '+' || **nptr == '-')
		return (0);
	return (sign);
}

static int	check_overflow(long temp, int sign, char current_char)
{
	if (sign == 1)
	{
		if (temp > INT_MAX / 10 || (temp == INT_MAX / 10 && current_char
				- '0' > 7))
			return (1);
	}
	else
	{
		if (temp > -(long long)(INT_MIN / 10) || (temp == -(long long)(INT_MIN
					/ 10) && current_char - '0' > 8))
			return (1);
	}
	return (0);
}

static void	handle_error(t_node **stack, char **splited)
{
	printf("Error\n");
	free_malloc_stack_init(stack);
	free_malloc_split(splited);
	exit(EXIT_FAILURE);
}

static long	convert_to_number(const char *nptr, int sign, t_node **stack,
		char **splited)
{
	long	temp;
	int		i;

	temp = 0;
	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (check_overflow(temp, sign, nptr[i]))
		{
			handle_error(stack, splited);
			return (0);
		}
		temp = temp * 10 + (nptr[i] - '0');
		i++;
	}
	return (temp * sign);
}

int	ft_atoi_push_swap(const char *nptr, t_node **stack, char **splited)
{
	int		sign;
	long	result;

	sign = parse_sign(&nptr);
	if (sign == 0)
		return (0);
	result = convert_to_number(nptr, sign, stack, splited);
	return ((int)result);
}
