/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/06 03:21:22 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_values_prev_stack_b(t_node *current_a, t_data *data)
{
	current_a->cost.prev = data->max_a + 1;
	current_a->cost.prev_rb = 0;
	current_a->cost.prev_rrb = 0;
}

void	set_values_next_stack_a(t_node *current_b, t_data *data)
{
	current_b->cost.next = data->min_a - 1;
	current_b->cost.next_ra = 0;
	current_b->cost.next_rra = 0;
}

void	set_values_prev_stack_a(t_node *current_b, t_data *data)
{
	current_b->cost.next = data->max_a + 1;
	current_b->cost.next_ra = 0;
	current_b->cost.next_rra = 0;
}

int	my_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
