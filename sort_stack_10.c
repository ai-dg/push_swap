/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/02 14:32:26 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*allocate_lis_sequence(int size)
{
	int	*lis_sequence;

	lis_sequence = (int *)malloc(size * sizeof(int));
	if (lis_sequence == NULL)
	{
		perror("Failure memory allocation\n");
		exit(EXIT_FAILURE);
	}
	return (lis_sequence);
}

void	free_allocate_sequence(int **lis, int **parent, int n)
{
	*lis = (int *)malloc(n * sizeof(int));
	*parent = (int *)malloc(n * sizeof(int));
	if (*lis == NULL || *parent == NULL)
	{
		perror("Failure memory allocation\n");
		exit(EXIT_FAILURE);
	}
}

void	find_biggest_sequence(int arr[], int n, int **lis_sequence,
		int *lis_size)
{
	int	*lis;
	int	*parent;
	int	max_index;
	int	t;
	int	i;

	free_allocate_sequence(&lis, &parent, n);
	initialize_arrays(lis, parent, n);
	max_index = compute_lis(arr, lis, parent, n);
	*lis_size = lis[max_index];
	*lis_sequence = allocate_lis_sequence(*lis_size);
	t = max_index;
	i = *lis_size - 1;
	while (i >= 0)
	{
		(*lis_sequence)[i] = arr[t];
		t = parent[t];
		i--;
	}
	free(lis);
	free(parent);
}

void	initialize_lis_marker(int *lis_marker, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		lis_marker[i] = 0;
		i++;
	}
}

void	mark_lis_elements(t_data *data, int *lis_marker)
{
	int	i;
	int	j;
	int	lis_element;

	i = 0;
	while (i < data->size_of_biggest)
	{
		lis_element = data->biggest_sequence[i];
		j = 0;
		while (j < data->len_stack_a)
		{
			if (data->values_list[j] == lis_element)
			{
				lis_marker[j] = 1;
				break ;
			}
			j++;
		}
		i++;
	}
}
