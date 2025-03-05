/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_12.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stacks(t_node **stack_a, t_node **stack_b, t_data *data)
{
	if (data->len_stack_a == 2)
		sa(stack_a, data);
	else if (data->len_stack_a == 3)
		sort_three_stack_a(stack_a, data);
	else if (data->len_stack_a == 4)
		sort_four_stack(stack_a, stack_b, data);
	else if (data->len_stack_a == 5)
		sort_five_stack(stack_a, stack_b, data);
}

void	sort_medium_stacks(t_node **stack_a, t_node **stack_b, t_data *data)
{
	init_values_in_cost(stack_a);
	find_pivot_stack_a(stack_a, data);
	pb(stack_a, stack_b, data);
	pb(stack_a, stack_b, data);
	while (data->len_stack_a > 3)
		pb(stack_a, stack_b, data);
	sort_three_stack_a(stack_a, data);
	find_min_stack_b(stack_b, data);
	while (data->len_stack_b > 0)
	{
		calculate_move_cost_stack_b_to_stack_a(stack_a, stack_b, data);
		take_best_option_to_pusha(stack_b, data);
		execute_moves_stacks(stack_a, stack_b, data);
		pa(stack_a, stack_b, data);
	}
	data->ra = find_index_value(stack_a, data->min_a);
	data->rra = data->len_stack_a - data->ra;
	execute_moves_stacks(stack_a, stack_b, data);
}

void	handle_lis_and_non_lis(t_node **stack_a, t_node **stack_b, t_data *data)
{
	bool	found;
	bool	found_lis;

	while (data->len_stack_a > data->size_of_biggest
		+ data->count_no_lis_sorted_sequence)
	{
		found = check_value_biggest_sequence((*stack_a)->value, data);
		found_lis = check_value_no_lis_sequence((*stack_a)->value, data);
		if (found || found_lis)
			ra(stack_a, data);
		else
			pb(stack_a, stack_b, data);
	}
}

void	move_remaining_to_b(t_node **stack_a, t_node **stack_b, t_data *data)
{
	bool	found;

	while (data->len_stack_a > data->size_of_biggest)
	{
		found = check_value_no_lis_sequence((*stack_a)->value, data);
		if (!found)
			ra(stack_a, data);
		else
			pb(stack_a, stack_b, data);
	}
}

void	move_all_from_b_to_a(t_node **stack_a, t_node **stack_b, t_data *data)
{
	while (data->len_stack_b > 0)
	{
		calculate_move_cost_stack_b_to_stack_a(stack_a, stack_b, data);
		take_best_option_to_pusha(stack_b, data);
		execute_moves_stacks(stack_a, stack_b, data);
		pa(stack_a, stack_b, data);
	}
}
