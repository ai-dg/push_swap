/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_and_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	t_node	*current;

	if (stack == NULL)
	{
		printf("\n");
		return ;
	}
	current = stack;
	while (1)
	{
		printf("%d\n", current->value);
		current = current->next;
		if (current == stack)
			break ;
	}
	printf("\n");
}

t_node	*putnodes(t_node *stack, int value)
{
	t_node	*newnode;
	t_node	*current;
	t_node	*temp;

	newnode = create_new_node(value);
	if (stack == NULL)
		return (newnode);
	current = stack;
	while (current->next != NULL)
		current = current->next;
	current->next = newnode;
	current = stack;
	temp = stack;
	while (temp->next != NULL)
	{
		current = current->next;
		current->prev = temp;
		temp = temp->next;
	}
	return (stack);
}

bool	sort_check(t_node **stack)
{
	t_node	*current;
	t_node	*first;

	current = *stack;
	first = *stack;
	current = current->next;
	while (current != first)
	{
		if (current->value < current->prev->value)
			return (false);
		current = current->next;
	}
	return (true);
}
