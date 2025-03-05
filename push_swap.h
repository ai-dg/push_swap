/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:44:04 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/06 03:21:34 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cost
{
	int				prev;
	int				next;
	int				ra;
	int				rra;
	int				next_ra;
	int				next_rra;
	int				prev_ra;
	int				prev_rra;
	int				rb;
	int				rrb;
	int				next_rb;
	int				next_rrb;
	int				prev_rb;
	int				prev_rrb;
}					t_cost;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_cost	cost;
}					t_node;

typedef struct s_data
{
	int				move_a;
	int				move_b;
	int				total_cost;
	int				common_moves;
	int				len_stack_a;
	int				len_stack_b;
	int				pivot_stack_a;
	int				ra;
	int				ra_temp;
	int				rb;
	int				rb_temp;
	int				rr_on;
	int				rrr_on;
	int				rra;
	int				rra_temp;
	int				rrb;
	int				rrb_temp;
	int				min_a;
	int				min_b;
	int				max_a;
	int				*sorted_stack_a;
	int				*values_list;
	int				*biggest_sequence;
	int				size_of_biggest;
	int				*no_lis_sequence;
	int				count_no_lis;
	int				*no_lis_sorted_sequence;
	int				count_no_lis_sorted_sequence;
	int				mouv_count;
	bool			stage_1;
	struct s_node	*first_a;
	struct s_node	*last_a;
	struct s_node	*first_b;
	struct s_node	*last_b;
}					t_data;

void				init_values_in_data(t_data *data);
void				init_values_in_cost(t_node **stack);
void				convert_stack_to_cercle(t_node **stack, t_data *data,
						char stack_aB);
void				sort_stack(t_node **stack_a, t_node **stack_b,
						t_data *data);
void				find_min_stack_b(t_node **stack_b, t_data *data);
void				find_non_lis_sequence(t_data *data);
void				find_biggest_sequence(int arr[], int n, int **lis_sequence,
						int *lis_size);
void				list_to_tab(t_node **stack_a, t_data *data);
void				take_best_option_to_pusha(t_node **stack_b, t_data *data);
void				take_best_option_to_pushb(t_node **stack_a, t_data *data);
int					calculate_total_cost_of_rotations(t_data *data);
void				calculate_move_cost_stack_b_to_stack_a(t_node **stack_a,
						t_node **stack_b, t_data *data);
void				take_best_option_to_move_stack_a(t_node **stack_b,
						t_data *data);
void				find_prev_number_on_stack_a_from_stack_b(t_node *current_b,
						t_node **stack_a, t_data *data);
void				find_next_number_on_stack_a_from_stack_b(t_node *current_b,
						t_node **stack_a, t_data *data);
void				calculate_move_cost_stack_a_to_stack_b(t_node **stack_a,
						t_node **stack_b, t_data *data);
bool				check_value_no_lis_sequence(int value, t_data *data);
void				take_best_option_to_move_stack_b(t_node **stack_a,
						t_data *data);
void				find_prev_number_on_stack_b_from_stack_a(t_node *current_a,
						t_node **stack_b, t_data *data);
void				find_next_number_on_stack_b_from_stack_a(t_node *current_a,
						t_node **stack_b, t_data *data);
void				execute_moves_stacks(t_node **stack_a, t_node **stack_b,
						t_data *data);
void				pushb_lower_elements_than_pivot(t_node **stack_a,
						t_node **stack_b, t_data *data);
int					find_index_value(t_node **stack, int value);
void				sort_five_stack(t_node **stack_a, t_node **stack_b,
						t_data *data);
int					min(int a, int b);
void				find_pivot_stack_a(t_node **stack_a, t_data *data);
void				sort_four_stack(t_node **stack_a, t_node **stack_b,
						t_data *data);
void				sort_three_stack_b(t_node **stack_b, t_data *data);
void				sort_three_stack_a(t_node **stack_a, t_data *data);
void				free_malloc_split(char **splited);
void				free_malloc_stack(t_node **stack);
bool				is_number_repeated(t_node **stack_a);
bool				is_number_valid(char *str);
bool				sort_check(t_node **stack);
void				rr(t_node **stack_a, t_node **stack_b, t_data *data);
void				rb(t_node **stack_b, t_data *data);
void				ra(t_node **stack_a, t_data *data);
void				pb(t_node **stack_a, t_node **stack_b, t_data *data);
void				pa(t_node **stack_a, t_node **stack_b, t_data *data);
void				rrr(t_node **stack_a, t_node **stack_b, t_data *data);
void				rrb(t_node **stack_b, t_data *data);
void				rra(t_node **stack_a, t_data *data);
void				ss(t_node **stack_a, t_node **stack_b, t_data *data);
void				sb(t_node **stack_b, t_data *data);
void				sa(t_node **stack_a, t_data *data);
t_node				*putnodes(t_node *stack, int value);
t_node				*create_new_node(int value);
void				print_stack(t_node *stack);
void				remove_node(t_node **head, int key);
void				put_front(t_node **stack, t_node *new_node, t_data *data,
						char stack_aB);
int					data_size(t_node *lst);
size_t				ft_strlen(const char *s);
char				**ft_split(const char *s, char c);
int					validate_and_split_arg(char *arg, t_node **stack_a,
						char ***splited);
int					fill_stack_with_numbers(char **splited, t_node **stack_a);
int					print_error_and_cleanup(t_node **stack_a);
int					ft_atoi_push_swap(const char *nptr, t_node **stack,
						char **splited);
void				free_malloc_stack_init(t_node **stack);
int					check_for_duplicates(t_node **stack_a);
void				cleanup_large_data_structures(t_data *data);
void				initialize_costs_and_data(t_node **stack_a, t_data *data);
void				push_max_to_b(t_node **stack_a, t_node **stack_b,
						t_data *data);
void				sort_and_push_back(t_node **stack_a, t_node **stack_b,
						t_data *data);
void				sort_four_stack(t_node **stack_a, t_node **stack_b,
						t_data *data);
void				set_costs_to_prev(t_node *current);
void				set_costs_to_next(t_node *current);
void				set_costs_to_best_option(t_node *current, t_data *data);
bool				check_value_no_lis_sequence(int value, t_data *data);
bool				check_value_biggest_sequence(int value, t_data *data);
void				set_current_node_cost(t_data *data, t_node *current);
int					is_better_cost(int total_cost, int best_cost);
void				set_rotations_from_node_cost(t_data *data, t_node *node);
void				update_best_cost_and_rotations(t_data *data, int *best_cost,
						int total_cost, t_node *node);
void				initialize_arrays(int *lis, int *parent, int n);
int					compute_lis(int *arr, int *lis, int *parent, int n);
void				mark_lis_elements(t_data *data, int *lis_marker);
void				initialize_lis_marker(int *lis_marker, int len);
void				sort_small_stacks(t_node **stack_a, t_node **stack_b,
						t_data *data);

void				sort_medium_stacks(t_node **stack_a, t_node **stack_b,
						t_data *data);
void				handle_lis_and_non_lis(t_node **stack_a, t_node **stack_b,
						t_data *data);

void				move_remaining_to_b(t_node **stack_a, t_node **stack_b,
						t_data *data);
void				move_all_from_b_to_a(t_node **stack_a, t_node **stack_b,
						t_data *data);
void				set_values_next_stack_b(t_node *current_a, t_data *data);
void				set_values_prev_stack_b(t_node *current_a, t_data *data);
void				set_values_next_stack_a(t_node *current_b, t_data *data);
void				set_values_prev_stack_a(t_node *current_b, t_data *data);
int					my_abs(int n);

#endif