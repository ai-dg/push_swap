/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rr_rrr_moves(t_node **stack_a, t_node **stack_b, t_data *data)
{
	while (data->move_a > 0 && data->move_b > 0)
	{
		rr(stack_a, stack_b, data);
		data->move_a--;
		data->move_b--;
	}
	while (data->move_a < 0 && data->move_b < 0)
	{
		rrr(stack_a, stack_b, data);
		data->move_a++;
		data->move_b++;
	}
}

void	execute_ra_rra_moves(t_node **stack_a, t_data *data)
{
	while (data->move_a > 0)
	{
		ra(stack_a, data);
		data->move_a--;
	}
	while (data->move_a < 0)
	{
		rra(stack_a, data);
		data->move_a++;
	}
}

void	execute_rb_rrb_moves(t_node **stack_b, t_data *data)
{
	while (data->move_b > 0)
	{
		rb(stack_b, data);
		data->move_b--;
	}
	while (data->move_b < 0)
	{
		rrb(stack_b, data);
		data->move_b++;
	}
}

void	execute_moves_stacks(t_node **stack_a, t_node **stack_b, t_data *data)
{
	if (data->ra <= data->rra)
		data->move_a = data->ra;
	else
		data->move_a = -data->rra;
	if (data->rb <= data->rrb)
		data->move_b = data->rb;
	else
		data->move_b = -data->rrb;
	execute_rr_rrr_moves(stack_a, stack_b, data);
	execute_ra_rra_moves(stack_a, data);
	execute_rb_rrb_moves(stack_b, data);
}

void	find_next_number_on_stack_b_from_stack_a(t_node *current_a,
		t_node **stack_b, t_data *data)
{
	int		value_next;
	t_node	*current;

	value_next = current_a->value - 1;
	current = (*stack_b)->next;
	while (true)
	{
		if (value_next == data->min_a - 1)
		{
			set_values_next_stack_b(current_a, data);
			break ;
		}
		if (current->value == value_next)
		{
			current_a->cost.next = value_next;
			current_a->cost.next_rb = find_index_value(stack_b, value_next);
			current_a->cost.next_rrb = data->len_stack_b
				- current_a->cost.next_rb;
			break ;
		}
		if (current == *stack_b)
			value_next--;
		current = current->next;
	}
}
