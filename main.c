/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/06 03:22:03 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_stacks(t_node **stack_a, t_node **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
}

static void	prepare_stack_data(t_node **stack_a, t_node **stack_b, t_data *data)
{
	convert_stack_to_cercle(stack_a, data, 'A');
	data->mouv_count = 0;
	data->len_stack_a = data_size(*stack_a);
	data->len_stack_b = data_size(*stack_b);
	if (data->len_stack_a == 0)
		print_error_and_cleanup(stack_a);
}

static void	sort_and_print_stacks(t_node **stack_a, t_node **stack_b,
		t_data *data)
{
	sort_stack(stack_a, stack_b, data);
}

static void	execute_algo_push_swap(t_node **stack_a, t_node **stack_b,
		t_data *data)
{
	prepare_stack_data(stack_a, stack_b, data);
	initialize_costs_and_data(stack_a, data);
	sort_and_print_stacks(stack_a, stack_b, data);
	cleanup_large_data_structures(data);
	free_malloc_stack(stack_a);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_data	data;
	char	**splited;
	int		i;

	if (argc == 1)
		return (1);
	initialize_stacks(&stack_a, &stack_b);
	i = 1;
	while (i < argc)
	{
		if (!validate_and_split_arg(argv[i], &stack_a, &splited))
			return (1);
		if (fill_stack_with_numbers(splited, &stack_a))
			return (1);
		free_malloc_split(splited);
		i++;
	}
	if (check_for_duplicates(&stack_a))
		return (1);
	execute_algo_push_swap(&stack_a, &stack_b, &data);
	return (0);
}
