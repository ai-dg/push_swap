/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_prev_number_on_stack_a_from_stack_b(t_node *current_b,
		t_node **stack_a, t_data *data)
{
	t_node	*current;
	int		value_prev;

	value_prev = current_b->value + 1;
	current = (*stack_a)->next;
	while (true)
	{
		if (value_prev == data->max_a + 1)
		{
			set_values_prev_stack_a(current_b, data);
			break ;
		}
		if (current->value == value_prev)
		{
			current_b->cost.next = value_prev;
			current_b->cost.next_ra = find_index_value(stack_a, value_prev);
			current_b->cost.next_rra = data->len_stack_a
				- current_b->cost.next_ra;
			break ;
		}
		if (current == *stack_a)
			value_prev++;
		current = current->next;
	}
}

static void	set_costs_to_prev_a(t_node *current)
{
	current->cost.ra = current->cost.prev_ra;
	current->cost.rra = current->cost.prev_rra;
}

static void	set_costs_to_next_a(t_node *current)
{
	current->cost.ra = current->cost.next_ra;
	current->cost.rra = current->cost.next_rra;
}

static void	set_costs_to_best_option_a(t_node *current, t_data *data)
{
	int	total_cost_next;
	int	total_cost_prev;

	data->ra = current->cost.next_ra;
	data->rra = current->cost.next_rra;
	total_cost_next = calculate_total_cost_of_rotations(data);
	data->ra = current->cost.prev_ra;
	data->rra = current->cost.prev_rra;
	total_cost_prev = calculate_total_cost_of_rotations(data);
	if (total_cost_next <= total_cost_prev)
		set_costs_to_next_a(current);
	else
		set_costs_to_prev_a(current);
}

void	take_best_option_to_move_stack_a(t_node **stack_b, t_data *data)
{
	t_node	*current;
	int		is_first_iteration;

	is_first_iteration = 1;
	current = *stack_b;
	while (current != *stack_b || is_first_iteration)
	{
		is_first_iteration = 0;
		if (current->cost.next_ra == 0 && current->cost.next_rra == 0)
			set_costs_to_prev_a(current);
		else if (current->cost.prev_ra == 0 && current->cost.prev_rra == 0)
			set_costs_to_next_a(current);
		else
			set_costs_to_best_option_a(current, data);
		current = current->next;
	}
}
