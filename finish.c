/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:09:24 by antonweizma       #+#    #+#             */
/*   Updated: 2023/12/15 16:23:43 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	top_to_bottom(t_stack **stack_a, t_sort *sort_a)
{
	get_sort(*stack_a, &sort_a);
	fetch_index(*stack_a, sort_a);
	while (*stack_a != sort_a->min)
	{
		if (sort_a->min->over_midpoint)
			rra(stack_a);
		else
			ra(stack_a);
	}
}

void	fetch_target_b(t_stack *stack_a, t_stack *stack_b, t_sort *sort_a)
{
	int		target;
	t_stack	*a_save;
	t_stack	*targetp;

	while (stack_b)
	{
		target = INT_MAX;
		a_save = stack_a;
		while (a_save)
		{
			if (a_save->content > stack_b->content && a_save->content < target)
			{
				target = a_save->content;
				targetp = a_save;
			}
			a_save = a_save->next;
		}
		if (target == INT_MAX)
			stack_b->target = sort_a->min;
		else
			stack_b->target = targetp;
		stack_b = stack_b->next;
	}
}

void	fetch_node_b(t_stack *stack_a, t_stack *stack_b,
			t_sort **sort_a, t_sort **sort_b)
{
	get_sort(stack_a, sort_a);
	if (!*sort_a)
		return ;
	get_sort(stack_b, sort_b);
	if (!*sort_b)
		return ;
	fetch_index(stack_a, *sort_a);
	fetch_index(stack_b, *sort_b);
	fetch_target_b(stack_a, stack_b, *sort_a);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	rotate_to_push(stack_a, (*stack_b)->target, stack_b, 0);
	pa(stack_a, stack_b);
}
