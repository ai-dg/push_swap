/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_9.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finalize_best_rotations(t_data *data)
{
	data->ra = data->ra_temp;
	data->rra = data->rra_temp;
	data->rb = data->rb_temp;
	data->rrb = data->rrb_temp;
}

void	take_best_option_to_pusha(t_node **stack_b, t_data *data)
{
	t_node	*current;
	int		best_cost;
	int		total_cost;
	int		first_iteration;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	current = *stack_b;
	best_cost = INT_MAX;
	first_iteration = 1;
	while (current != *stack_b || first_iteration)
	{
		set_rotations_from_node_cost(data, current);
		total_cost = calculate_total_cost_of_rotations(data);
		if (total_cost < best_cost)
			update_best_cost_and_rotations(data, &best_cost, total_cost,
				current);
		current = current->next;
		first_iteration = 0;
	}
	finalize_best_rotations(data);
}

void	list_to_tab(t_node **stack_a, t_data *data)
{
	t_node	*current;
	int		i;
	int		first_iteration;

	if (stack_a == NULL || *stack_a == NULL)
	{
		fprintf(stderr, "Stack is empty\n");
		exit(EXIT_FAILURE);
	}
	current = *stack_a;
	data->values_list = (int *)malloc(sizeof(int) * data->len_stack_a);
	if (data->values_list == NULL)
	{
		perror("Failure memory allocation\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	first_iteration = 1;
	while (current != *stack_a || first_iteration)
	{
		data->values_list[i] = current->value;
		current = current->next;
		i++;
		first_iteration = 0;
	}
}

void	initialize_arrays(int *lis, int *parent, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		lis[i] = 1;
		parent[i] = -1;
		i++;
	}
}

int	compute_lis(int *arr, int *lis, int *parent, int n)
{
	int	i;
	int	j;
	int	max_index;

	max_index = 0;
	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				parent[i] = j;
			}
			j++;
		}
		if (lis[max_index] < lis[i])
			max_index = i;
		i++;
	}
	return (max_index);
}
