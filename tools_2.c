/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_stack_to_cercle(t_node **stack, t_data *data, char stack_aB)
{
	t_node	*current;

	if (*stack == NULL)
		return ;
	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = *stack;
	(*stack)->prev = current;
	if (stack_aB == 'A')
	{
		data->first_a = *stack;
		data->last_a = current;
	}
	else
	{
		data->first_b = *stack;
		data->last_b = current;
	}
}

void	bubble_sort(int *arr, int n)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	find_pivot_stack_a(t_node **stack_a, t_data *data)
{
	t_node	*current;
	int		i;

	i = 0;
	current = *stack_a;
	data->len_stack_a = data_size(*stack_a);
	data->sorted_stack_a = (int *)malloc(sizeof(int) * data->len_stack_a);
	if (data->sorted_stack_a == NULL)
	{
		perror("Failure memory allocation\n");
		exit(EXIT_FAILURE);
	}
	while (i < data->len_stack_a)
	{
		data->sorted_stack_a[i] = current->value;
		current = current->next;
		i++;
	}
	bubble_sort(data->sorted_stack_a, data->len_stack_a);
	data->pivot_stack_a = data->sorted_stack_a[data->len_stack_a / 2];
	data->max_a = data->sorted_stack_a[data->len_stack_a - 1];
	data->min_a = data->sorted_stack_a[0];
	free(data->sorted_stack_a);
}

int	find_index_value(t_node **stack, int value)
{
	t_node	*current;
	t_node	*start;
	int		index;

	index = 0;
	current = *stack;
	if (current == NULL)
		return (-1);
	start = current;
	while (1)
	{
		if (current->value == value)
			return (index);
		index++;
		current = current->next;
		if (current == start)
			break ;
	}
	return (-1);
}

void	set_values_next_stack_b(t_node *current_a, t_data *data)
{
	current_a->cost.next = data->min_a - 1;
	current_a->cost.next_rb = 0;
	current_a->cost.next_rrb = 0;
}
