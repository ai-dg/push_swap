/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_best_cost(t_data *data, int *best_cost, int total_cost,
		t_node *current)
{
	*best_cost = total_cost;
	data->ra_temp = current->cost.ra;
	data->rra_temp = current->cost.rra;
	data->rb_temp = current->cost.rb;
	data->rrb_temp = current->cost.rrb;
}

static void	apply_best_cost(t_data *data)
{
	data->ra = data->ra_temp;
	data->rra = data->rra_temp;
	data->rb = data->rb_temp;
	data->rrb = data->rrb_temp;
}

void	take_best_option_to_pushb(t_node **stack_a, t_data *data)
{
	t_node	*current;
	int		best_cost;
	int		total_cost;
	int		first_iteration;

	first_iteration = 1;
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	current = *stack_a;
	best_cost = INT_MAX;
	while (current != *stack_a || first_iteration)
	{
		set_current_node_cost(data, current);
		total_cost = calculate_total_cost_of_rotations(data);
		if (is_better_cost(total_cost, best_cost))
		{
			update_best_cost(data, &best_cost, total_cost, current);
		}
		current = current->next;
		first_iteration = 0;
	}
	apply_best_cost(data);
}

void	set_rotations_from_node_cost(t_data *data, t_node *node)
{
	data->ra = node->cost.ra;
	data->rra = node->cost.rra;
	data->rb = node->cost.rb;
	data->rrb = node->cost.rrb;
}

void	update_best_cost_and_rotations(t_data *data, int *best_cost,
		int total_cost, t_node *node)
{
	*best_cost = total_cost;
	data->ra_temp = node->cost.ra;
	data->rra_temp = node->cost.rra;
	data->rb_temp = node->cost.rb;
	data->rrb_temp = node->cost.rrb;
}
