/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:59:13 by aweizman          #+#    #+#             */
/*   Updated: 2023/12/15 04:35:38 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/include/ft_printf.h"
# include <limits.h>
int		init_stacks(char **argv, t_stack *stacks_a, int argc);

int		check_conds(char **argv, int argc);
void	print_stack(t_stack *stack);
int		count_args(char **argv);
t_stack	*ft_beforelast(t_stack *lst);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);

int		is_sorted(t_stack *stack);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

void	push_a(t_stack **stack_a, t_stack **stack_b, t_sort *sort_a, t_sort *sort_b);
void	rotate_to_push(t_stack **stack_a, t_stack *cheapest,
			t_stack **stack_b, int all);
void	fetch_node_a(t_stack *stack_a, t_stack *stack_b, t_sort **sort_a, t_sort **sort_b);
void	fetch_index(t_stack *stack, t_sort *sort);
t_sort	*get_sort(t_stack *stack);
void	fetch_node_b(t_stack *stack_a, t_stack *stack_b, t_sort **sort_a, t_sort **sort_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	top_to_bottom(t_stack **stack_a, t_sort *sort_a);
#endif
