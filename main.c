/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:04:36 by aweizman          #+#    #+#             */
/*   Updated: 2023/12/15 19:04:18 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error_sort(t_sort **sort_a, t_sort **sort_b)
{
	free(*sort_a);
	free(*sort_b);
	free(sort_a);
	free(sort_a);
	ft_printf("Error\n");
	exit(0);
}

void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free (tmp);
	}
	while (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		free (tmp);
	}
	free(stack_a);
	free(stack_b);
	free(tmp);
	ft_printf("Error\n");
	exit(0);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_sort	*sort_a;
	t_sort	*sort_b;

	sort_a = malloc(sizeof(t_sort));
	sort_b = malloc(sizeof(t_sort));
	if (!sort_a || !sort_b)
		return (ft_error_sort(&sort_a, &sort_b));
	if (argc > 3)
		pb(stack_a, stack_b);
	if (argc > 4)
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
	else
		big_sort(stack_a, stack_b, argc);
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
		|| init_stacks(argv, stack_a, argc) == 0)
		return (ft_error(&stack_a, &stack_b), 0);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b, argc);
}
