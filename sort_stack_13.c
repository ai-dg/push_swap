/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_13.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_position_correction(t_node **stack_a, t_node **stack_b,
		t_data *data)
{
	if ((*stack_a)->value != data->min_a)
	{
		data->ra = find_index_value(stack_a, data->min_a);
		data->rra = data->len_stack_a - data->ra;
		execute_moves_stacks(stack_a, stack_b, data);
	}
}

void	sort_large_stacks(t_node **stack_a, t_node **stack_b, t_data *data)
{
	find_pivot_stack_a(stack_a, data);
	list_to_tab(stack_a, data);
	find_biggest_sequence(data->values_list, data->len_stack_a,
		&data->biggest_sequence, &data->size_of_biggest);
	find_non_lis_sequence(data);
	data->stage_1 = true;
	handle_lis_and_non_lis(stack_a, stack_b, data);
	move_remaining_to_b(stack_a, stack_b, data);
	find_min_stack_b(stack_b, data);
	data->stage_1 = true;
	move_all_from_b_to_a(stack_a, stack_b, data);
	data->stage_1 = false;
	final_position_correction(stack_a, stack_b, data);
}

void	sort_stack(t_node **stack_a, t_node **stack_b, t_data *data)
{
	if (!sort_check(stack_a))
	{
		if (data->len_stack_a <= 5)
			sort_small_stacks(stack_a, stack_b, data);
		else if (data->len_stack_a <= 100)
			sort_medium_stacks(stack_a, stack_b, data);
		else
			sort_large_stacks(stack_a, stack_b, data);
	}
}
