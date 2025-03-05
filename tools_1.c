/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:07 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/02 15:17:24 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_strings(const char *str, char c)
{
	size_t	nbr_mots;

	nbr_mots = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			while (*str != '\0' && *str != c)
				str++;
			nbr_mots++;
		}
		else
			str++;
	}
	if (nbr_mots == 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	return (nbr_mots);
}

static const char	*ft_replace(char **dest, const char *src, char c)
{
	size_t	len;
	size_t	i;

	if (!src || !dest || !c)
		return (NULL);
	while (*src == c)
		src++;
	len = 0;
	while (src[len] != '\0' && src[len] != c)
		len++;
	*dest = (char *)malloc(sizeof(char) * (len + 1));
	if (*dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		(*dest)[i] = src[i];
		i++;
	}
	(*dest)[i] = '\0';
	src += len + 1;
	return (src);
}

char	**ft_split(const char *s, char c)
{
	char	**dest;
	size_t	nbr_mots;
	size_t	i;

	if (!s)
		return (NULL);
	nbr_mots = count_strings(s, c);
	dest = (char **)malloc(sizeof(char *) * (nbr_mots + 1));
	if (dest == NULL)
		return (NULL);
	dest[nbr_mots] = NULL;
	i = 0;
	while (i < nbr_mots)
	{
		s = ft_replace(dest + i, s, c);
		if (s == NULL)
		{
			free_malloc_split(dest);
			return (0);
		}
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	data_size(t_node *lst)
{
	size_t	size;
	t_node	*first;
	t_node	*current;

	if (lst == NULL)
		return (0);
	size = 1;
	first = lst;
	current = lst->next;
	while (current != first)
	{
		current = current->next;
		size++;
	}
	return (size);
}
