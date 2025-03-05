/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a, t_data *data)
{
	int	temp;

	data->len_stack_a = data_size(*stack_a);
	write(1, "sa\n", 3);
	if (data->len_stack_a > 1)
	{
		temp = (*stack_a)->value;
		(*stack_a)->value = (*stack_a)->next->value;
		(*stack_a)->next->value = temp;
	}
	data->mouv_count++;
}

void	sb(t_node **stack_b, t_data *data)
{
	int	temp;

	data->len_stack_b = data_size(*stack_b);
	write(1, "sb\n", 3);
	if (data->len_stack_b > 1)
	{
		temp = (*stack_b)->value;
		(*stack_b)->value = (*stack_b)->next->value;
		(*stack_b)->next->value = temp;
	}
	data->mouv_count++;
}

void	ra(t_node **stack_a, t_data *data)
{
	if (*stack_a == NULL || (*stack_a)->next == *stack_a)
	{
		return ;
	}
	if (data->rr_on != 1)
	{
		write(1, "ra\n", 3);
		data->mouv_count++;
	}
	*stack_a = (*stack_a)->next;
	data->first_a = *stack_a;
	data->last_a = (*stack_a)->prev;
}

void	rb(t_node **stack_b, t_data *data)
{
	if (*stack_b == NULL || (*stack_b)->next == *stack_b)
		return ;
	if (data->rr_on != 1)
	{
		write(1, "rb\n", 3);
		data->mouv_count++;
	}
	*stack_b = (*stack_b)->next;
	data->first_b = *stack_b;
	data->last_b = (*stack_b)->prev;
}

void	rr(t_node **stack_a, t_node **stack_b, t_data *data)
{
	data->rr_on = 1;
	write(1, "rr\n", 3);
	data->mouv_count++;
	ra(stack_a, data);
	rb(stack_b, data);
	data->rr_on = 0;
}
