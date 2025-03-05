/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_11.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/02 14:28:53 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_non_lis_elements(int *lis_marker, int len)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < len)
	{
		if (!lis_marker[i])
			count++;
		i++;
	}
	return (count);
}

int	*allocate_non_lis_sequence(int count)
{
	int	*sequence;

	sequence = (int *)malloc(count * sizeof(int));
	if (sequence == NULL)
	{
		perror("Failure memory allocation\n");
		exit(EXIT_FAILURE);
	}
	return (sequence);
}

void	fill_non_lis_sequence(t_data *data, int *lis_marker)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (i < data->len_stack_a)
	{
		if (!lis_marker[i])
			data->no_lis_sequence[index++] = data->values_list[i];
		i++;
	}
}

void	find_non_lis_sequence(t_data *data)
{
	int	*lis_marker;

	lis_marker = (int *)malloc(data->len_stack_a * sizeof(int));
	if (lis_marker == NULL)
	{
		perror("Failure memory allocation\n");
		exit(EXIT_FAILURE);
	}
	initialize_lis_marker(lis_marker, data->len_stack_a);
	mark_lis_elements(data, lis_marker);
	data->count_no_lis = count_non_lis_elements(lis_marker, data->len_stack_a);
	data->no_lis_sequence = allocate_non_lis_sequence(data->count_no_lis);
	fill_non_lis_sequence(data, lis_marker);
	find_biggest_sequence(data->no_lis_sequence, data->count_no_lis,
		&data->no_lis_sorted_sequence, &data->count_no_lis_sorted_sequence);
	free(lis_marker);
}

void	find_min_stack_b(t_node **stack_b, t_data *data)
{
	t_node	*current;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	current = *stack_b;
	data->min_b = current->value;
	while (1)
	{
		if (current->value < data->min_b)
			data->min_b = current->value;
		current = current->next;
		if (current == *stack_b)
			break ;
	}
}
