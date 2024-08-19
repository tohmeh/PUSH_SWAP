/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:06:52 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 10:52:33 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//t_stack
typedef struct t_stack {
	char			*str;
	struct t_stack	*next;
}	t_stack;

//number_normalisation_map
typedef struct t_N_list{
	int					index;
	int					number;
	struct t_N_list		*next;
}	t_N_list;

//t_stack functions
int			push(t_stack **s, const char *value);
int			pop(t_stack **s);
char		*peek(t_stack *s);
int			is_empty(t_stack *s);

//push_swap_operations
int			pa(t_stack **A, t_stack **B);
int			pb(t_stack **A, t_stack **B);
int			ra(t_stack **A);
int			rb(t_stack **B);
int			rr(t_stack **A, t_stack **B);
int			rra(t_stack **A);
int			rrb(t_stack **B);
int			rrr(t_stack **A, t_stack **B);
int			sb(t_stack **B);
int			sa(t_stack **A);

//prepare_binary_t_stack
void		bubble_sort(int arr[], int n);
t_N_list	*map_the_elements(int *temp, int n);
void		switch_to_natural_arr(int *temp, int n, t_N_list *lst);
char		*to_binary(int value, int *temp, int size);
t_stack		*to_binary_stk(int *temp, int size);

//prepare_natural_number_array
int			*to_normal_array(char **str, int size);

//prepare_binary_t_stack_utils
int			find_index(int num, t_N_list *lst, int n);
int			maximum_binary_size(int *temp, int n);
char		*reverse_string(const char *str);

//main_utils
void		printarray(int arr[], int size);
void		copy_array(int *source, int *destination, int n);
void		printt_stack(t_stack *s);
int			count_words(const char *str, const char *delimiters);

//input_check
int			sorted_check(int *temp, int size);
int			is_within_int_bounds(const char *str);
int			duplicate_check(int *temp, int size);
int			only_numbers_check(const char *str);

//sort_little
int			binary_to_int(const char *binary);
int			*t_stack_to_int_array(t_stack *head, int size);
void		reverse_switch_index1(int *temp);
int			find_min_index(int *arr, int size);
void		sort_three(t_stack **A, int *arr);
void		sort_four(t_stack **A, t_stack **B, int *arr);
void		sort_five(t_stack **A, t_stack **B, int *arr);
void		optimize_small_sort(t_stack **A, t_stack **B, int *arr);
int			size_of_t_stack(t_stack *A);

//freesome
void		destroy_2d_char_array(char **array, int rows);
void		destroyt_stack(t_stack **s);

//radixSort
void		radixsort_binary(t_stack **inputt_stack, int maxBits);

#endif