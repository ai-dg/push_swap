/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_malloc_stack(t_node **stack)
{
	t_node	*first;
	t_node	*current;
	t_node	*temp;

	if (stack == NULL || *stack == NULL)
		return ;
	first = *stack;
	current = first;
	while (current->next != first)
	{
		current = current->next;
	}
	current->next = NULL;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	free_malloc_stack_init(t_node **stack)
{
	t_node	*temp;

	if (stack == NULL || *stack == NULL)
		return ;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	free_malloc_split(char **splited)
{
	int	j;

	j = 0;
	while (splited[j] != NULL)
	{
		free(splited[j]);
		j++;
	}
	free(splited);
}

void	cleanup_large_data_structures(t_data *data)
{
	if (data->len_stack_a > 100)
	{
		free(data->values_list);
		free(data->biggest_sequence);
		free(data->no_lis_sequence);
		free(data->no_lis_sorted_sequence);
	}
}
