/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 01:37:54 by yeju              #+#    #+#             */
/*   Updated: 2021/10/08 02:30:54 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	swap_ab(t_list **stack, char c)
{
	void	*temp;
	t_list	*head;

	head = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		temp = head->content;
		head->content = head->next->content;
		head->next->content = temp;
		if (c == 'a')
			ft_putstr_fd("sa\n", 1);
		if (c == 'b')
			ft_putstr_fd("sb\n", 1);
		return (1);
	}
	return (0);
}

int	push_ab(t_list **a, t_list **b, char c)
{
	void	*temp;

	if (ft_lstsize(*b))
	{
		temp = pop(b);
		push(a, temp, sizeof(int));
		free(temp);
		if (c == 'a')
			ft_putstr_fd("pa\n", 1);
		if (c == 'b')
			ft_putstr_fd("pb\n", 1);
		return (1);
	}
	return (0);
}

int	rotate_ab(t_list **stack, char c)
{
	void	*content;

	if (ft_lstsize(*stack) > 1)
	{
		content = pop(stack);
		ft_lstadd_back(stack, ft_lstnew(content));
		if (c == 'a')
			ft_putstr_fd("ra\n", 1);
		if (c == 'b')
			ft_putstr_fd("rb\n", 1);
		return (1);
	}
	return (0);
}

int	reverse_ab(t_list **stack, char c)
{
	void	*content;
	t_list	*laa;
	t_list	*prev;

	if (ft_lstsize(*stack) > 1)
	{
		laa = cut_stack(*stack, ft_lstsize(*stack) - 1);
		prev = cut_stack(*stack, ft_lstsize(*stack) - 2);
		content = laa->content;
		push(stack, content, sizeof(int));
		ft_lstdelone(laa, free);
		prev->next = NULL;
		if (c == 'a')
			ft_putstr_fd("rra\n", 1);
		if (c == 'b')
			ft_putstr_fd("rrb\n", 1);
		return (1);
	}
	return (0);
}
