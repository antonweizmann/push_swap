/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:04:36 by aweizman          #+#    #+#             */
/*   Updated: 2023/12/15 04:37:10 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_sort	*sort_a;
	t_sort	*sort_b;

	sort_a = NULL;
	sort_b = NULL;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		fetch_node_a(*stack_a, *stack_b, &sort_a, &sort_b);
		push_a(stack_a, stack_b, sort_a, sort_b);
	}
	sort_3(stack_a);
	while (*stack_b)
	{
		fetch_node_b(*stack_a, *stack_b, &sort_a, &sort_b);
		push_b(stack_a, stack_b);
	}
	top_to_bottom(stack_a, sort_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (is_sorted(*stack_a) || ft_lstsize(*stack_a) < 2)
		return ;
	if (argc == 2)
		sa(stack_a);
	else if (argc == 3)
		sort_3(stack_a);
	else if (argc == 4)
		sort_4(stack_a, stack_b);
	else if (argc == 5)
		sort_5(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (argc == 1)
		return (0);
	if (ft_strchr(argv[1], ' '))
		argv = ft_split(argv[1], ' ');
	else
		argv++;
	argc = count_args(argv);
	if (!argv || !stack_a || !stack_b || check_conds(argv, argc) == -1
		|| init_stacks(argv, stack_a, argc) == -1)
		return (ft_printf("Error\n"), 0);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b, argc);
}
