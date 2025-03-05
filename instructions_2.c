/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b, t_data *data)
{
	t_node	*new_node;

	if (*stack_b == NULL)
		return ;
	write(1, "pa\n", 3);
	data->mouv_count++;
	new_node = create_new_node((*stack_b)->value);
	put_front(stack_a, new_node, data, 'A');
	remove_node(stack_b, (*stack_b)->value);
	data->len_stack_b = data_size(*stack_b);
	data->len_stack_a = data_size(*stack_a);
}

void	pb(t_node **stack_a, t_node **stack_b, t_data *data)
{
	t_node	*new_node;

	if (*stack_a == NULL)
		return ;
	write(1, "pb\n", 3);
	data->mouv_count++;
	new_node = create_new_node((*stack_a)->value);
	put_front(stack_b, new_node, data, 'B');
	remove_node(stack_a, (*stack_a)->value);
	data->len_stack_a = data_size(*stack_a);
	data->len_stack_b = data_size(*stack_b);
}

void	rra(t_node **stack_a, t_data *data)
{
	if (*stack_a == NULL || (*stack_a)->next == *stack_a)
		return ;
	if (data->rrr_on != 1)
	{
		write(1, "rra\n", 4);
		data->mouv_count++;
	}
	*stack_a = (*stack_a)->prev;
	data->first_a = *stack_a;
	data->last_a = (*stack_a)->prev;
}

void	rrb(t_node **stack_b, t_data *data)
{
	if (*stack_b == NULL || (*stack_b)->next == *stack_b)
		return ;
	if (data->rrr_on != 1)
	{
		write(1, "rrb\n", 4);
		data->mouv_count++;
	}
	*stack_b = (*stack_b)->prev;
	data->first_b = *stack_b;
	data->last_b = (*stack_b)->prev;
}

void	rrr(t_node **stack_a, t_node **stack_b, t_data *data)
{
	data->rrr_on = 1;
	write(1, "rrr\n", 4);
	data->mouv_count++;
	rra(stack_a, data);
	rrb(stack_b, data);
	data->rrr_on = 0;
}
