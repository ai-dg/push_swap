/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_stack_a(t_node **stack_a, t_data *data)
{
	t_node	*current;
	int		i;

	current = *stack_a;
	i = 0;
	while (i < 2)
	{
		if (current->value > current->next->value && i == 0)
			sa(stack_a, data);
		else if (current->value > current->next->value && i == 1)
			rra(stack_a, data);
		current = current->next;
		i++;
	}
	current = *stack_a;
	if (current->value > current->next->value)
		sa(stack_a, data);
}

void	sort_three_stack_b(t_node **stack_b, t_data *data)
{
	t_node	*current;
	int		i;

	current = *stack_b;
	i = 0;
	while (i < 2)
	{
		if (current->value < current->next->value && i == 0)
			sb(stack_b, data);
		else if (current->value < current->next->value && i == 1)
			rrb(stack_b, data);
		current = current->next;
		i++;
	}
	current = *stack_b;
	if (current->value < current->next->value)
		sb(stack_b, data);
}

void	rotate_to_max(t_node **stack_a, t_data *data, int *index_max,
		int *value)
{
	t_node	*current;

	current = *stack_a;
	*index_max = 0;
	*value = current->value;
	while (current->next != *stack_a)
	{
		if (*value > current->value)
			(*index_max)++;
		if (*index_max >= 1)
		{
			ra(stack_a, data);
			*index_max = 0;
			current = *stack_a;
			*value = current->value;
		}
		else
			current = current->next;
	}
}

void	push_max_to_b(t_node **stack_a, t_node **stack_b, t_data *data)
{
	int	index_max;
	int	value;

	rotate_to_max(stack_a, data, &index_max, &value);
	pb(stack_a, stack_b, data);
}

void	sort_and_push_back(t_node **stack_a, t_node **stack_b, t_data *data)
{
	if (!sort_check(stack_a))
		sort_three_stack_a(stack_a, data);
	pa(stack_a, stack_b, data);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, data);
}
