/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 21:54:06 by moni              #+#    #+#             */
/*   Updated: 2024/09/29 15:31:44 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	find_max_index(t_stack *stack)
{
	int	max;
	int	max_index;
	int	index;

	max_index = 0;
	index = 0;
	if (!stack)
		return (-1);
	max = stack->content;
	while (stack != NULL)
	{
		if (stack->content > max)
		{
			max = stack->content;
			max_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (max_index);
}

int	find_min_index(t_stack *stack)
{
	int		min;
	int		min_index;
	int		index;

	min_index = 0;
	index = 0;
	if (!stack)
		return (-1);
	min = stack->content;
	while (stack != NULL)
	{
		if (stack->content < min)
		{
			min = stack->content;
			min_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (min_index);
}

bool	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->content < a->next->content)
			a = a->next;
		else
			return (false);
	}
	return (true);
}

void	rotate_stack(t_stack **a, t_stack **b, t_info *info, t_price *cheapest)
{
	while (cheapest->a_price > 0 && cheapest->b_price > 0)
	{
		rr(a, b, info);
		cheapest->a_price--;
		cheapest->b_price--;
	}
	while (cheapest->a_price > 0)
	{
		ra(a, info);
		cheapest->a_price--;
	}
	while (cheapest->b_price > 0)
	{
		rb(b, info);
		cheapest->b_price--;
	}
}
