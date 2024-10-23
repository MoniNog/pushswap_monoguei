/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:48:35 by moni              #+#    #+#             */
/*   Updated: 2024/09/22 18:38:18 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	clean(t_stack **a, t_stack **b, t_info **info)
{
	if (b && *b)
		free_stack(*b);
	if (info && *info)
		free(*info);
	if (a && *a)
		free_stack(*a);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = NULL;
	while (stack)
	{
		temp = stack->next;
		if (stack->struct_price)
		{
			free(stack->struct_price);
			stack->struct_price = NULL;
		}
		free(stack);
		stack = temp;
	}
}

void	initialize_struct_price(t_stack *stack)
{
	while (stack)
	{
		stack->struct_price = malloc(sizeof(t_price));
		if (!stack->struct_price)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		stack->struct_price->price = 0;
		stack->struct_price->a_price = 0;
		stack->struct_price->b_price = 0;
		stack = stack->next;
	}
}
