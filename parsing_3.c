/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_number_repeated(t_node **stack_a)
{
	t_node	*current1;
	t_node	*current2;

	if (stack_a == NULL || *stack_a == NULL)
		return (false);
	current2 = *stack_a;
	while (current2 != NULL)
	{
		current1 = *stack_a;
		while (current1 != NULL)
		{
			if (current1 != current2 && current1->value == current2->value)
				return (true);
			current1 = current1->next;
		}
		current2 = current2->next;
	}
	return (false);
}

int	check_for_duplicates(t_node **stack_a)
{
	if (is_number_repeated(stack_a))
		return (print_error_and_cleanup(stack_a));
	return (0);
}
