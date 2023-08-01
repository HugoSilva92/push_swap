/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:39:02 by huolivei          #+#    #+#             */
/*   Updated: 2023/01/04 00:36:04 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../bonus/get_next_line.h"

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				targ_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}			t_list;

int			is_nb(char c);
int			sign(char c);
int			is_correct_input(char **av);
int			is_digit(char *av);
int			amount_zeros(char *av);
int			has_duplicates(char **av);
int			nb_cmp(char *str, char *str1);
void		error(t_list **stack_a, t_list **stack_b);
void		free_stack(t_list **stack);
t_list		*get_values(int ac, char **av);
long int	ft_atoi(const char *str);
t_list		*initialize(long int nb);
void		add_bottom(t_list **stack, t_list *new);
t_list		*get_bottom_stack(t_list *stack);
int			get_size(t_list *stack);
void		get_index(t_list *stack, int size);
int			is_sorted(t_list *stack);
void		sa(t_list **stack);
void		swap(t_list *stack);
void		small_sort(t_list **stack);
int			get_max_i(t_list *stack);
void		rotate(t_list **stack);
void		ra(t_list	**stack);
void		rra(t_list **stack);
void		reverse_rotate(t_list **stack);
t_list		*get_before_bottom_stack(t_list *stack);
void		push_to_b(t_list **stack_a, t_list **stack_b);
void		sort(t_list **stack_a, t_list **stack_b);
void		push(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		get_tar_pos(t_list **stack_a, t_list **stack_b);
void		get_pos(t_list **stack);
int			get_best_targ_pos(t_list **stack, int b_index,
				int max_index, int tar_pos);
void		get_cost(t_list **stack_a, t_list **stack_b);
void		do_less_cost(t_list **stack_a, t_list **stack_b);
int			abs_nb(int nb);
void		move_stack(t_list **stack_a, t_list **stack_b,
				int cost_a, int cost_b);
void		rrr_both(t_list **stack_a, t_list **stack_b,
				int *cost_a, int *cost_b);
void		rrr(t_list **stack_a, t_list **stack_b);
void		rr_both(t_list **stack_a, t_list **stack_b,
				int *cost_a, int *cost_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		r_a(t_list **stack, int *cost);
void		r_b(t_list **stack, int *cost);
void		rrb(t_list **stack);
void		rb(t_list **stack);
void		pa(t_list **stack_a, t_list **stack_b);
void		rotate_stack(t_list **stack_a);
int			get_lowest_index(t_list **stack);
void		getting_str(t_list **stack_a, t_list **stack_b);
int			move_check(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		sb(t_list **stack);
void		ss(t_list **stack_a, t_list **stack_b);
void		do_moves(t_list **stack_a, t_list **stack_b, char *str);

#endif
