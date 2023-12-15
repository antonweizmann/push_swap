/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:09:09 by aweizman          #+#    #+#             */
/*   Updated: 2023/12/15 16:08:15 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	print_stack(t_stack *stack)
{
	ft_printf("--------------\n");
	while (stack)
	{
		ft_printf("%i\n", stack->content);
		stack = stack->next;
	}
}

t_stack	*ft_beforelast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	while (stack->next)
	{
		tmp = stack;
		stack = stack->next;
		if (tmp->content > stack->content)
			return (0);
	}
	return (1);
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
