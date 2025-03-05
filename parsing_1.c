/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/06 03:25:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node **stack_a, t_node **stack_b, t_data *data)
{
	sa(stack_a, data);
	sb(stack_b, data);
}

int	print_error_and_cleanup(t_node **stack_a)
{
	printf("Error\n");
	free_malloc_stack_init(stack_a);
	return (1);
}

int	validate_and_split_arg(char *arg, t_node **stack_a, char ***splited)
{
	if (arg == NULL || ft_strlen(arg) == 0)
	{
		print_error_and_cleanup(stack_a);
		exit(EXIT_FAILURE);
	}
	*splited = ft_split(arg, ' ');
	return (*splited != NULL);
}

int	fill_stack_with_numbers(char **splited, t_node **stack_a)
{
	int	j;

	j = 0;
	while (splited[j] != NULL)
	{
		if (!is_number_valid(splited[j]))
		{
			print_error_and_cleanup(stack_a);
			free_malloc_split(splited);
			exit(EXIT_FAILURE);
		}
		*stack_a = putnodes(*stack_a, ft_atoi_push_swap(splited[j], stack_a,
					splited));
		j++;
	}
	return (0);
}

bool	is_number_valid(char *str)
{
	if ((*str == '-' || *str == '+'))
		str++;
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (false);
		}
		str++;
	}
	return (true);
}
