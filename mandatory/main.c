/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:53:15 by huolivei          #+#    #+#             */
/*   Updated: 2023/01/04 00:55:32 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2 && (!is_sorted(*stack_a)))
		sa(stack_a);
	else if (size == 3)
		small_sort(stack_a);
	else if (size > 3 && (!is_sorted(*stack_a)))
		sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		error(NULL, NULL);
	stack_a = get_values(ac, av);
	stack_b = NULL;
	stack_size = get_size(stack_a);
	get_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

	/*while (stack_a)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}*/
