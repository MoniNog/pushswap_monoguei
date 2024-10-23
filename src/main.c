/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:19:34 by moni              #+#    #+#             */
/*   Updated: 2024/09/22 20:00:52 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	initialize_stacks(t_stack **a, t_stack **b, t_info **info)
{
	*a = NULL;
	*b = NULL;
	*info = NULL;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_info	*info;
	char	**z;

	if (ac > 1 && checks_are_ok(av[1]) == true)
	{
		if (ac == 2)
		{
			av[1] = clean_whitespace(av[1]);
			if (!ft_strchr(av[1], ' '))
				return (0);
			z = split(av[1], ' ');
		}
		else
			z = av + 1;
		initialize_stacks(&a, &b, &info);
		create_stack(&a, &b, &info, z);
		choose_sort(&a, &b, info);
		clean(&a, &b, &info);
	}
	return (0);
}
