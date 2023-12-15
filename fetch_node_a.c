/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_node_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:45:41 by antonweizma       #+#    #+#             */
/*   Updated: 2023/12/15 17:37:54 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_sort(t_stack *stack, t_sort **sort)
{
	int		min;
	int		max;

	(*sort)->size = 0;
	max = INT_MIN;
	min = INT_MAX;
	while (stack)
	{
		(*sort)->size += 1;
		if (stack->content > max)
		{
			max = stack->content;
			(*sort)->max = stack;
		}
		if (stack->content < min)
		{
			min = stack->content;
			(*sort)->min = stack;
		}
		stack = stack->next;
	}
}

void	fetch_index(t_stack *stack, t_sort *sort)
{
	int	i;
	int	midpoint;

	if (!stack)
		return ;
	i = 0;
	midpoint = sort->size / 2;
	while (stack)
	{
		stack->index = i;
		if (i > midpoint)
			stack->over_midpoint = true;
		else if (i <= midpoint)
			stack->over_midpoint = false;
		i++;
		stack = stack->next;
	}
}

void	fetch_target(t_stack *stack_a, t_stack *stack_b, t_sort *sort_b)
{
	int		target;
	t_stack	*b_save;
	t_stack	*targetp;

	while (stack_a)
	{
		target = INT_MIN;
		b_save = stack_b;
		while (b_save)
		{
			if (b_save->content < stack_a->content && b_save->content > target)
			{
				target = b_save->content;
				targetp = b_save;
			}
			b_save = b_save->next;
		}
		if (target == INT_MIN)
			stack_a->target = sort_b->max;
		else
			stack_a->target = targetp;
		stack_a = stack_a->next;
	}
}

void	fetch_cost(t_stack *stack_a, t_sort *sort_a, t_sort *sort_b)
{
	while (stack_a)
	{
		stack_a->cost = stack_a->index;
		if (stack_a->over_midpoint)
			stack_a->cost = sort_a->size - stack_a->index;
		if (stack_a->target->over_midpoint)
			stack_a->cost += sort_b->size
				- stack_a->target->index;
		else
			stack_a->cost += stack_a->target->index;
		stack_a = stack_a->next;
	}
}

void	fetch_node_a(t_stack *stack_a, t_stack *stack_b,
			t_sort **sort_a, t_sort **sort_b)
{
	get_sort(stack_a, sort_a);
	get_sort(stack_b, sort_b);
	fetch_index(stack_a, *sort_a);
	fetch_index(stack_b, *sort_b);
	fetch_target(stack_a, stack_b, *sort_b);
	fetch_cost(stack_a, *sort_a, *sort_b);
}
