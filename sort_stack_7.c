/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/02 15:15:09 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_move_cost_stack_b_to_stack_a(t_node **stack_a,
		t_node **stack_b, t_data *data)
{
	t_node	*current_b;
	int		is_first_iteration;

	is_first_iteration = 1;
	current_b = *stack_b;
	init_values_in_cost(stack_b);
	init_values_in_cost(stack_a);
	while (current_b != *stack_b || is_first_iteration)
	{
		is_first_iteration = 0;
		current_b->cost.rb = find_index_value(stack_b, current_b->value);
		current_b->cost.rrb = data->len_stack_b - current_b->cost.rb;
		find_next_number_on_stack_a_from_stack_b(current_b, stack_a, data);
		find_prev_number_on_stack_a_from_stack_b(current_b, stack_a, data);
		if (current_b->value == data->min_b && data->stage_1 == true)
		{
			current_b->cost.rb = data->len_stack_a + data->len_stack_b;
			current_b->cost.rrb = data->len_stack_a + data->len_stack_b;
			current_b->cost.ra = data->len_stack_a + data->len_stack_b;
			current_b->cost.rra = data->len_stack_a + data->len_stack_b;
		}
		current_b = current_b->next;
	}
	take_best_option_to_move_stack_a(stack_b, data);
}

void	cost_common_moves(t_data *data)
{
	if (data->move_a > 0 && data->move_b > 0)
	{
		data->common_moves = min(data->move_a, data->move_b);
		data->total_cost += 2 * data->common_moves;
		data->move_a -= data->common_moves;
		data->move_b -= data->common_moves;
	}
	else if (data->move_a < 0 && data->move_b < 0)
	{
		data->common_moves = min(-data->move_a, -data->move_b);
		data->total_cost += 2 * data->common_moves;
		data->move_a += data->common_moves;
		data->move_b += data->common_moves;
	}
}

int	calculate_total_cost_of_rotations(t_data *data)
{
	data->move_a = 0;
	data->move_b = 0;
	if (data->ra <= data->rra)
		data->move_a = data->ra;
	else
		data->move_a = -data->rra;
	if (data->rb <= data->rrb)
		data->move_b = data->rb;
	else
		data->move_b = -data->rrb;
	data->total_cost = 0;
	cost_common_moves(data);
	data->total_cost += my_abs(data->move_a) + my_abs(data->move_b);
	return (data->total_cost);
}

void	set_current_node_cost(t_data *data, t_node *current)
{
	data->ra = current->cost.ra;
	data->rra = current->cost.rra;
	data->rb = current->cost.rb;
	data->rrb = current->cost.rrb;
}

int	is_better_cost(int total_cost, int best_cost)
{
	return (total_cost < best_cost);
}
