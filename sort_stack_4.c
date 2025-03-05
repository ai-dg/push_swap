/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_prev_number_on_stack_b_from_stack_a(t_node *current_a,
		t_node **stack_b, t_data *data)
{
	int		value_prev;
	t_node	*current;

	value_prev = current_a->value + 1;
	current = (*stack_b)->next;
	while (true)
	{
		if (value_prev == data->max_a + 1)
		{
			set_values_prev_stack_b(current_a, data);
			break ;
		}
		if (current->value == value_prev)
		{
			current_a->cost.prev = value_prev;
			current_a->cost.prev_rb = find_index_value(stack_b, value_prev);
			current_a->cost.prev_rrb = data->len_stack_b
				- current_a->cost.prev_rb;
			break ;
		}
		if (current == *stack_b)
			value_prev++;
		current = current->next;
	}
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	set_costs_to_prev(t_node *current)
{
	current->cost.rb = current->cost.prev_rb;
	current->cost.rrb = current->cost.prev_rrb;
}

void	set_costs_to_next(t_node *current)
{
	current->cost.rb = current->cost.next_rb;
	current->cost.rrb = current->cost.next_rrb;
}

void	set_costs_to_best_option(t_node *current, t_data *data)
{
	int	total_cost_next;
	int	total_cost_prev;

	data->ra = current->cost.ra;
	data->rra = current->cost.rra;
	data->rb = current->cost.next_rb;
	data->rrb = current->cost.next_rrb;
	total_cost_next = calculate_total_cost_of_rotations(data);
	data->rb = current->cost.prev_rb;
	data->rrb = current->cost.prev_rrb;
	total_cost_prev = calculate_total_cost_of_rotations(data);
	if (total_cost_next <= total_cost_prev)
		set_costs_to_next(current);
	else
		set_costs_to_prev(current);
}
