/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	take_best_option_to_move_stack_b(t_node **stack_a, t_data *data)
{
	t_node	*current;
	t_node	*first;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	current = *stack_a;
	first = *stack_a;
	while (current != first || current == *stack_a)
	{
		if (current->cost.next_rb == 0 && current->cost.next_rrb == 0)
			set_costs_to_prev(current);
		else if (current->cost.prev_rb == 0 && current->cost.prev_rrb == 0)
			set_costs_to_next(current);
		else
			set_costs_to_best_option(current, data);
		current = current->next;
		if (current == *stack_a)
			first = NULL;
	}
}

bool	check_value_biggest_sequence(int value, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_of_biggest)
	{
		if (data->biggest_sequence[i] == value)
			return (true);
		i++;
	}
	return (false);
}

bool	check_value_no_lis_sequence(int value, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count_no_lis_sorted_sequence)
	{
		if (data->no_lis_sorted_sequence[i] == value)
			return (true);
		i++;
	}
	return (false);
}

void	calculate_move_cost_stack_a_to_stack_b(t_node **stack_a,
		t_node **stack_b, t_data *data)
{
	t_node	*current_a;
	t_node	*first_a;
	int		first_iteration;

	first_iteration = 1;
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	current_a = *stack_a;
	first_a = *stack_a;
	while (first_iteration || current_a != first_a)
	{
		current_a->cost.ra = find_index_value(stack_a, current_a->value);
		current_a->cost.rra = data->len_stack_a - current_a->cost.ra;
		find_next_number_on_stack_b_from_stack_a(current_a, stack_b, data);
		find_prev_number_on_stack_b_from_stack_a(current_a, stack_b, data);
		current_a = current_a->next;
		first_iteration = 0;
	}
	take_best_option_to_move_stack_b(stack_a, data);
}

void	find_next_number_on_stack_a_from_stack_b(t_node *current_b,
		t_node **stack_a, t_data *data)
{
	t_node	*current;
	int		value_next;

	value_next = current_b->value - 1;
	current = (*stack_a)->next;
	while (true)
	{
		if (value_next == data->min_a - 1)
		{
			set_values_next_stack_a(current_b, data);
			break ;
		}
		if (current->value == value_next)
		{
			current_b->cost.prev = value_next;
			current_b->cost.prev_ra = find_index_value(stack_a, value_next) + 1;
			current_b->cost.prev_rra = data->len_stack_a
				- current_b->cost.prev_ra;
			break ;
		}
		if (current == *stack_a)
			value_next--;
		current = current->next;
	}
}
