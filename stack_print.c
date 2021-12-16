/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:17:39 by yeju              #+#    #+#             */
/*   Updated: 2021/10/08 02:32:53 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_list	*printstack(t_list *stack, char *base, int max_value)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (stack)
	{
		if (*(int *)stack->content >= 0)
			ft_putnchar_fd('0', 1, ft_nbrlen(max_value, base_len) - \
				ft_nbrlen(*(int *)stack->content, base_len));
		ft_putnbr_base_fd(*(int *)stack->content, base, 1);
		if (ft_nbrlen(*(int *)stack->content, 10) > 7)
			ft_putnchar_fd('\t', 1, 1);
		else
			ft_putnchar_fd('\t', 1, 2);
		stack = stack->next;
	}
	else
	{
		ft_putchar_fd('.', 1);
		ft_putnchar_fd('\t', 1, 2);
	}
	return (stack);
}

int	printstack_ab(t_list *a, t_list *b, char *base)
{
	t_list	*max_a;
	t_list	*max_b;

	if (!a && !b)
		return (ft_putstr_fd("Error\n", 2));
	write(1, "\n", 1);
	max_a = max(a);
	max_b = max(b);
	while (a || b)
	{
		if (max_a)
			a = printstack(a, base, *(int *)max_a->content);
		else
			a = printstack(a, base, 0);
		if (max_b)
			b = printstack(b, base, *(int *)max_b->content);
		else
			b = printstack(b, base, 0);
		ft_putchar_fd('\n', 1);
	}
	ft_putnchar_fd('-', 1, 10);
	ft_putstr_fd("\t", 1);
	ft_putnchar_fd('-', 1, 10);
	ft_putstr_fd("\na\t\tb\n\n", 1);
	return (0);
}
