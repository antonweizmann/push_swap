/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:36:24 by antonweizma       #+#    #+#             */
/*   Updated: 2023/12/15 17:39:44 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*fetch_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	int		cost;

	cost = INT_MAX;
	while (stack)
	{
		if (stack->cost < cost)
		{
			cost = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}

void	rotate_to_push(t_stack **stack_a, t_stack *cheapest
	, t_stack **stack_b, int all)
{
	while (*stack_a != cheapest)
	{
		if (!(cheapest->over_midpoint))
			ra(stack_a);
		else
			rra(stack_a);
	}
	while (*stack_b != cheapest->target && all)
	{
		if (!(cheapest->target->over_midpoint))
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	reverse_together(t_stack **stack_a, t_stack **stack_b
	, t_stack *cheapest)
{
	while (cheapest != *stack_a && cheapest->target != *stack_b)
		rrr(stack_a, stack_b);
}

void	rotate_together(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (cheapest != *stack_a && cheapest->target != *stack_b)
		rr(stack_a, stack_b);
}

void	push_a(t_stack **stack_a, t_stack **stack_b,
			t_sort *sort_a, t_sort *sort_b)
{
	t_stack	*cheapest;

	cheapest = fetch_cheapest(*stack_a);
	if (cheapest->over_midpoint && cheapest->target->over_midpoint)
	{
		reverse_together(stack_a, stack_b, cheapest);
		fetch_index(*stack_a, sort_a);
		fetch_index(*stack_b, sort_b);
	}
	else if (!(cheapest->over_midpoint) && !(cheapest->target->over_midpoint))
	{
		rotate_together(stack_a, stack_b, cheapest);
		fetch_index(*stack_a, sort_a);
		fetch_index(*stack_b, sort_b);
	}
	rotate_to_push(stack_a, cheapest, stack_b, 1);
	pb(stack_a, stack_b);
}
