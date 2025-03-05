/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/02 13:56:34 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_front(t_node **stack, t_node *new_node, t_data *data, char stack_aB)
{
	if (*stack == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		new_node->prev = (*stack)->prev;
		(*stack)->prev->next = new_node;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	if (stack_aB == 'A')
		data->last_a = (*stack)->prev;
	else
		data->last_b = (*stack)->prev;
}

void	free_node(t_node **head, t_node *node_to_remove)
{
	t_node	*last;

	if (node_to_remove->next == node_to_remove)
	{
		free(node_to_remove);
		*head = NULL;
	}
	else
	{
		last = node_to_remove;
		while (last->next != node_to_remove)
		{
			last = last->next;
		}
		if (node_to_remove == *head)
		{
			*head = node_to_remove->next;
		}
		last->next = node_to_remove->next;
		node_to_remove->next->prev = last;
		free(node_to_remove);
	}
}

void	remove_node_from_list(t_node **head, t_node *current, t_node *prev,
		int key)
{
	int	first_iteration;

	if (current == NULL)
		return ;
	first_iteration = 1;
	while (current != *head || first_iteration)
	{
		first_iteration = 0;
		if (current->value == key)
		{
			if (prev)
			{
				prev->next = current->next;
				if (current->next)
					current->next->prev = prev;
			}
			free_node(head, current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	remove_node(t_node **head, int key)
{
	t_node	*current;

	if (*head == NULL)
		return ;
	current = *head;
	if (current->value == key)
		free_node(head, current);
	else
		remove_node_from_list(head, current->next, current, key);
}

t_node	*create_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
	{
		perror("Failure memory allocation\n");
		exit(EXIT_FAILURE);
	}
	if (node)
	{
		node->value = value;
		node->next = NULL;
	}
	return (node);
}
