/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:18:27 by yeju              #+#    #+#             */
/*   Updated: 2021/10/08 02:33:27 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	check_value(char *argv, t_list **a)
{
	int		j;
	long	content;

	j = 0;
	while (argv[j])
	{
		if (ft_atoi(&argv[j], &content) == -1 || \
			find(*a, (void *)&content, sizeof(int)) != -1)
		{
			ft_lstclear(a, free);
			ft_putstr_fd("Error\n", 1);
			return (-1);
		}
		ft_lstadd_back(a, new_stack((void *)&content, sizeof(int)));
		while (ft_isspace(argv[j]))
			j++;
		j += ft_strchr("+-", argv[j]) != 0;
		while (ft_isdigit(argv[j]))
			j++;
	}
	return (0);
}

static t_list	*parse(int argc, char **argv)
{
	t_list	*a;
	int		i;

	a = NULL;
	i = 0;
	if (argc < 2)
		return (NULL);
	while (++i < argc)
	{
		if (check_value(argv[i], &a) == -1)
			return (NULL);
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = parse(argc, argv);
	if (!a)
		return (0);
	order(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
