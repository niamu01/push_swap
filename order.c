/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:17:59 by yeju              #+#    #+#             */
/*   Updated: 2021/10/08 02:36:12 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	order(t_list **a, t_list **b)
{
	int	max_value;

	max_value = ft_lstsize(*a) - 1;
	if (check_sorted(*a))
		return (0);
	if (max_value + 1 == 2)
		return (swap_ab(a, 'a'));
	translate(a);
	while (ft_lstsize(*a) > 3 && ft_lstsize(*a) < 7)
	{
		first_node(a, min(*a)->content, 'a');
		push_ab(b, a, 'b');
	}
	sort_3(a, b);
	if (!check_sorted(*a))
		bit_sort(a, b, ft_nbrlen(max_value, 2), 0);
	return (0);
}

void	sort_3(t_list **a, t_list **b)
{
	if (*(int *)cut_stack(*a, 1)->content == *(int *)min(*a)->content && \
		*(int *)cut_stack(*a, 2)->content == *(int *)max(*a)->content)
		swap_ab(a, 'a');
	if (*(int *)cut_stack(*a, 1)->content == *(int *)min(*a)->content && \
		*(int *)cut_stack(*a, 0)->content == *(int *)max(*a)->content)
		rotate_ab(a, 'a');
	if (*(int *)cut_stack(*a, 2)->content == *(int *)min(*a)->content && \
		*(int *)cut_stack(*a, 1)->content == *(int *)max(*a)->content)
		reverse_ab(a, 'a');
	if (*(int *)cut_stack(*a, 0)->content == *(int *)min(*a)->content && \
		*(int *)cut_stack(*a, 1)->content == *(int *)max(*a)->content)
	{
		swap_ab(a, 'a');
		rotate_ab(a, 'a');
	}
	if (*(int *)cut_stack(*a, 2)->content == *(int *)min(*a)->content && \
		*(int *)cut_stack(*a, 0)->content == *(int *)max(*a)->content)
	{
		swap_ab(a, 'a');
		reverse_ab(a, 'a');
	}
	while (ft_lstsize(*b))
		push_ab(a, b, 'a');
}

int	bit_sort(t_list **a, t_list **b, int max_len, int n_bit)
{
	int	i;
	int	len;
	int	tmp;

	if (n_bit > max_len || check_sorted(*a))
	{
		while (ft_lstsize(*b))
			push_ab(a, b, 'a');
		return (0);
	}
	i = -1;
	len = ft_lstsize(*a);
	tmp = sorted_stack(*a, *b, 'a');
	while (++i < len - tmp && !check_sorted(*a))
	{
		if (!(*(int *)(*a)->content >> n_bit & 1))
			push_ab(b, a, 'b');
		else
			rotate_ab(a, 'a');
	}
	i = -1;
	len = ft_lstsize(*b);
	while (++i < len - sorted_stack(*a, *b, 'b'))
		push_ab(a, b, 'a');
	return (bit_sort(a, b, max_len, n_bit + 1));
}
