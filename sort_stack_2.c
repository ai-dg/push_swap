/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_stack(t_node **stack_a, t_node **stack_b, t_data *data)
{
	push_max_to_b(stack_a, stack_b, data);
	sort_and_push_back(stack_a, stack_b, data);
}

void	sort_five_stack(t_node **stack_a, t_node **stack_b, t_data *data)
{
	pushb_lower_elements_than_pivot(stack_a, stack_b, data);
	if (data->len_stack_a == 3)
	{
		sort_three_stack_a(stack_a, data);
		if ((*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b, data);
	}
	else if (data->len_stack_b == 3)
	{
		sort_three_stack_b(stack_b, data);
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a, data);
	}
	while (data->len_stack_a != 5)
		pa(stack_a, stack_b, data);
}

void	rotate_stack_a(t_node **stack_a, t_data *data, int ra_count)
{
	int	i;

	i = 0;
	while (i < ra_count)
	{
		ra(stack_a, data);
		i++;
	}
}

void	reverse_rotate_stack_a(t_node **stack_a, t_data *data, int rra_count)
{
	int	i;

	i = 0;
	while (i < rra_count)
	{
		rra(stack_a, data);
		i++;
	}
}

void	pushb_lower_elements_than_pivot(t_node **stack_a, t_node **stack_b,
		t_data *data)
{
	int	num_elements;
	int	ra_count;
	int	rra_count;
	int	i;

	find_pivot_stack_a(stack_a, data);
	num_elements = data->len_stack_a;
	i = 0;
	while (i < num_elements)
	{
		ra_count = find_index_value(stack_a, (*stack_a)->value);
		rra_count = data->len_stack_a - ra_count;
		if ((*stack_a)->value < data->pivot_stack_a)
		{
			if (ra_count <= rra_count)
				rotate_stack_a(stack_a, data, ra_count);
			else
				reverse_rotate_stack_a(stack_a, data, rra_count);
			pb(stack_a, stack_b, data);
		}
		else
			ra(stack_a, data);
		i++;
	}
}
