/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:08:57 by aweizman          #+#    #+#             */
/*   Updated: 2023/12/15 18:33:26 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_stacks(char **argv, t_stack *stacks_a, int argc)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	stacks_a->content = ft_atoi(argv[i++]);
	stacks_a->next = NULL;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]));
		if (!tmp)
			return (-1);
		ft_lstadd_back(&stacks_a, tmp);
		i++;
	}
	return (0);
}

int	check_conds(char **argv, int argc)
{
	int	i;
	int	j;

	j = 0;
	while (j < argc)
	{
		if (ft_atoi(argv[j]) == -1)
			return (-1);
		i = 0;
		while (argv[j][i])
		{
			if (!ft_isdigit(argv[j][i]))
				if (!(argv[j][i] == '+' || argv[j][i] == '-')
				|| ((argv[j][i] == '+' || argv[j][i] == '-')
				&& !ft_isdigit(argv[j][i + 1])))
					return (-1);
			i++;
		}
		i = -1;
		while (++i < argc)
			if (!ft_strncmp(argv[j], argv[i], 11) && j != i)
				return (-1);
		j++;
	}
	return (0);
}
