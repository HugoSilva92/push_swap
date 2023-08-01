/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:03:12 by huolivei          #+#    #+#             */
/*   Updated: 2023/01/04 00:53:03 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_nb(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

void	get_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_size(tmp_a);
	size_b = get_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > (size_b / 2))
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->targ_pos;
		if (tmp_b->targ_pos > (size_a / 2))
			tmp_b->cost_a = (size_a - tmp_b->targ_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	do_less_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		cost_a;
	int		cost_b;
	int		less_mov;

	tmp = *stack_b;
	less_mov = INT_MAX;
	while (tmp)
	{
		if ((abs_nb(tmp->cost_a) + abs_nb(tmp->cost_b)) < less_mov)
		{
			less_mov = abs_nb(tmp->cost_a) + abs_nb(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move_stack(stack_a, stack_b, cost_a, cost_b);
}
