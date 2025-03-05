/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_costs_and_data(t_node **stack_a, t_data *data)
{
	init_values_in_cost(stack_a);
	init_values_in_data(data);
}

void	init_values_in_cost(t_node **stack)
{
	t_node	*current;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (1)
	{
		current->cost.prev = 0;
		current->cost.next = 0;
		current->cost.ra = 0;
		current->cost.rra = 0;
		current->cost.next_ra = 0;
		current->cost.next_rra = 0;
		current->cost.prev_ra = 0;
		current->cost.prev_rra = 0;
		current->cost.rb = 0;
		current->cost.rrb = 0;
		current->cost.next_rb = 0;
		current->cost.next_rrb = 0;
		current->cost.prev_rb = 0;
		current->cost.prev_rrb = 0;
		current = current->next;
		if (current == *stack)
			break ;
	}
}

void	init_values_in_data(t_data *data)
{
	data->move_a = 0;
	data->move_b = 0;
	data->total_cost = 0;
	data->common_moves = 0;
	data->pivot_stack_a = 0;
	data->ra = 0;
	data->ra_temp = 0;
	data->rb = 0;
	data->rb_temp = 0;
	data->rr_on = 0;
	data->rrr_on = 0;
	data->rra = 0;
	data->rra_temp = 0;
	data->rrb = 0;
	data->rrb_temp = 0;
	data->min_a = 0;
	data->max_a = 0;
	data->stage_1 = false;
}
