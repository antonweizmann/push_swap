/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:16:07 by antonweizma       #+#    #+#             */
/*   Updated: 2023/12/11 15:41:14 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	third_spot(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last;

	sa(stack_a);
	ra(stack_a);
	sa(stack_a);
	last = ft_lstlast(*stack_a);
	if (*stack_b && (*stack_b)->content > last->content)
	{
		pa(stack_a, stack_b);
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
	rra(stack_a);
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*two;
	t_stack	*three;
	t_stack	*one;

	one = *stack_a;
	two = (*stack_a)->next;
	three = two->next;
	if (one->content > two->content && two->content < three->content
		&& three->content > one->content)
		sa(stack_a);
	if (one->content > two->content && two->content > three->content
		&& one->content > three->content)
		sa(stack_a);
	if (one->content < two->content && two->content > three->content
		&& one->content < three->content)
		sa(stack_a);
	if (one->content < two->content && two->content > three->content
		&& three->content < one->content)
		rra(stack_a);
	if (one->content > two->content && two->content < three->content
		&& three->content < one->content)
		ra(stack_a);
	if (!(one->content < two->content && two->content < three->content
			&& three->content > one->content))
		sort_3(stack_a);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	while (!is_sorted(*stack_a) || *stack_b)
	{
		if (ft_lstlast(*stack_a)->content < (*stack_a)->content)
			ra(stack_a);
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			third_spot(stack_a, stack_b);
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	if ((*stack_b)->content < (*stack_b)->next->content)
		rb(stack_b);
	pa(stack_a, stack_b);
	while (!is_sorted(*stack_a) || *stack_b)
	{
		if (*stack_b && ft_lstlast(*stack_a)->content < (*stack_b)->content)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			ra(stack_a);
		}
		if (ft_lstlast(*stack_a)->content < (*stack_a)->content)
			ra(stack_a);
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			third_spot(stack_a, stack_b);
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
		if (*stack_b)
			pa(stack_a, stack_b);
	}
}
